'use strict';

var bitcore_lib = require('bitcore-lib');
var PaymentProtocol = require('bitcore-payment-protocol');
var express = require('express');
var bodyParser = require('body-parser');
var URI = require('bitcore-lib/lib/uri');
var request = require("request");
const https = require('https');
var fs = require("fs");

var dcert = fs.readFileSync('./keys/cert.der');
var mcert = fs.readFileSync('./keys/cert.pem'); // For HTTPS server
var mkey = fs.readFileSync('./keys/key.pem');


var credentials = { key: mkey, cert: mcert }
var app = express();
var os = require('os');
var interfaces = os.networkInterfaces();
var addresses = [];

for (var k in interfaces) {
    for (var k2 in interfaces[k]) {
        var address = interfaces[k][k2];
        if (address.family === 'IPv4' && !address.internal) {
            addresses.push(address.address);
        }
    }
}

var IP = addresses[0];
var port = 8883;
var http_port = 3000;

app.get("/", function (req, res) {
    res.send('Bitcoin Payment protocol');
});

app.listen(http_port, function () {
    console.log("-http Server listening on :" + IP + ":" + http_port);
});

https.createServer(credentials, app).listen(port, function () {
    console.log("-https Server listening on :" + IP + ":" + port);
});


/// Building a payment request URI


bitcore_lib.Networks.defaultNetwork = bitcore_lib.Networks.testnet; // the project runs only on testnet.
var Merchant_address = "2N7BPybxuJ5XzBpjnMtaB6S2HvdATz7da9j";

var merchant_pkey = 'cPPSeHs118aYb1u65AhTLs84dnbfED3qf8cAqFJG3FNCwxYJb5Jn';

var privateKey = bitcore_lib.PrivateKey(merchant_pkey); // we pass a specific private key as argument

var publicKey = bitcore_lib.PublicKey(privateKey);

bitcore_lib.Address(publicKey, bitcore_lib.Networks.defaultNetwork);

function compose_uri(amount_to_pay) {
    var pay_url = "http://" + IP + ":" + http_port + "/request";
    var uriString = new URI({
        address: Merchant_address,
        amount: amount_to_pay, // amount in satoshis 
        message: 'payment request'
    });
    var paymentUri = uriString + "&r=" + pay_url;
    return paymentUri;
}


/// Proceeding with payment


var path = require("path");
app.use(express.static(path.join(__dirname + '/views')));
app.get('/checkout', function (req, res) {
    res.sendFile(path.join(__dirname + '/views/index.html'));
});


/// Payment Processing


app.use(bodyParser.json());
app.post("/ProcessingPayment", function (req, res) {
    var amount_ = req.body.amount;
    var resp = compose_uri(amount_) + "?amount=" + amount_;
    res.send(resp);
});


/// Requesting payment details

var urlencodedParser = bodyParser.urlencoded({ extended: false });
app.get("/request", urlencodedParser, function (req, res) {
    var amount = req.query.amount;
    amount = (amount === undefined) ? 0 : amount; // set amount to 0 if undefined
    var merchant_outputs = []; // Where payment should be sent
    var outputs = new PaymentProtocol().makeOutput();
    outputs.set('amount', amount);
    var script = bitcore_lib.Script.buildPublicKeyHashOut(Merchant_address.toString());
    outputs.set('script', script.toBuffer());
    merchant_outputs.push(outputs.message);

    /// BIP70, defining the payment request details.


    var details = new PaymentProtocol().makePaymentDetails();
    var now = Date.now() / 1000 | 0;
    details.set('network', 'test');
    details.set('outputs', merchant_outputs);
    details.set('time', now); //Unix timestamp when the PaymentRequest was created.
    details.set('expires', now + 60 * 60 * 24); //timestamp after which the PaymentRequest should be considered invalid. 
    details.set('memo', 'A payment request from the merchant.');
    details.set('payment_url', "http://" + IP + ":" + http_port + "/payment?id=12345"); //location where a Payment message may be sent to obtain a PaymentACK.
    details.set('merchant_data', new Buffer("Transaction N 12345")); //identify the payment request


    /// we form the final request as follows:


    var request = new PaymentProtocol().makePaymentRequest();
    request.set('payment_details_version', 1);
    var certificates = new PaymentProtocol().makeX509Certificates();
    certificates.set('certificate', dcert);
    request.set('pki_type', 'x509+sha256');
    request.set('pki_data', certificates.serialize());
    request.set('serialized_payment_details', details.serialize());
    request.sign(mkey);
    var rawbody = request.serialize(); // serialize the request
    res.set({
        'Content-Type': PaymentProtocol.JSON_PAYMENT_REQUEST_CONTENT_TYPE,
        'Content-Length': request.length,
        'Content-Transfer-Encoding': 'binary'
    });

    if (req.query.browser == 1) {
        var buf = new Buffer(rawbody, 'binary').toString('base64');
        res.contentType(PaymentProtocol.JSON_PAYMENT_REQUEST_CONTENT_TYPE);
        res.send(buf);
    }
    else { //response for bitcoin core client
        res.status(200).send(rawbody);
    }
});

/// Receiving and acknowledging payment


var rawBodyParser = bodyParser.raw({ type: PaymentProtocol.JSON_PAYMENT_CONTENT_TYPE });
app.post("/payment", rawBodyParser, function (req, res) {
    var body = PaymentProtocol.Payment.decode(req.body);
    var payment = new PaymentProtocol().makePayment(body);
    var refund_to = payment.get('refund_to'); //output where a refund should be sent.
    var memo = payment.get('memo');
    var Rawtransaction = payment.get('transactions')[0].toBuffer();/*One or more valid, signed Bitcoin transactions that fully pay the PaymentRequest*/
    var TransactionToBrodcast = new bitcore_lib.Transaction(Rawtransaction).toString('hex'); /* potentially broadcast the transaction as we did in the first chapter using chain.so/api/ */


    // Sending to the client a payment acknowledgment message with a receipt ID.

    var ack = new PaymentProtocol().makePaymentACK(); 
    ack.set('payment', payment.message); ack.set('memo', 'Payment processed,Thank you ;) \n invoice ID :' + req.query.id); //store invoice details in database
    var rawack = ack.serialize(); res.set({
        'Content-Type': PaymentProtocol.PAYMENT_ACK_CONTENT_TYPE,
        'Content-Length': rawack.length,
    });
    res.send(rawack);
});


/// Invoicing


app.get("/invoice", urlencodedParser, function (req, res) {
    var invoice_id = req.query.id;
    var detail = "details about the invoice N:" + invoice_id;
    /*....invoice Database access..*/
    res.send(detail);
});