var bitcoin = require('bitcoinjs-lib');
var rp = require('request-promise');

var data = Buffer.from('Hello World', 'utf8');
var testnet = bitcoin.networks.testnet;
var privateKey = 'cRRDYNr2aSMKdn27iVvmbZhHnBzpTUCgaXuHY2hoe5PvLZrA3Fnz';
var SourceAddress = '2N421LSaY5TmM9NnvTzZxg2StpAMXgYfKTx';

var scriptPK = 'a91476296a15198693df5384e1066031b29a3a458afb87';

var redeemS = '001478651e8b9efca6d880fb2c05ca5ef42d3ccf8e07';

var rawUnspent = '02000000000101dac4d966a79a6ee492e0e3b971ac84b5bc92f41721b7ace1e8b0038df75e611101000000171600148a1f4a199fffea3fa280acec8924683a7e881370feffffff02102700000000000017a91476296a15198693df5384e1066031b29a3a458afb8779b5a1440900000017a9141914f7c486ba32f8af1161ff339d9d43553f4aec870247304402200c806d76bb8a0a5be653a18dc1dee038659669f7aaa238174a3aaf10e1261de2022029ac51a94dfaeb1e9c77d180dd8c554779b76c5c283009765deb30e69dd8a2c40121021f60aa94afaf90f8af21ae933b7d81e79077f3aca51c2770ef0f77c0ddc644909cf71800';

var url = "https://btctest.haskoin.com/api/address/" + SourceAddress + "/unspent";

var DestionationAddress = '2N4a3TP4hkkEQsm1ToSciJSvLLrnmhyUNbL';
var DestionationAddress2 = '2N421LSaY5TmM9NnvTzZxg2StpAMXgYfKTx';
var send_coin = 100;

var options = {
    uri: url,
    json: true
};

rp(options).then(function (response) {
    console.log(response);
    var index = response.length - 1;
    var UtxoId = response[index].txid;
    var vout = response[index].index;
    var amount = Number(response[index].value);
    var fee = 0.000003 * 100000000;



    const RawTranscation = new bitcoin.Psbt({ network: testnet });

    const isSegwit = rawUnspent.substring(8, 12) === '0001';

    if (isSegwit) {
        RawTranscation.addInput({
            hash: UtxoId,
            index: vout,
            witnessUtxo: {
                script: Buffer.from(scriptPK, 'hex'),
                value: amount // value in satoshi
            },
            redeemScript: Buffer.from(redeemS, 'hex')
        })
    }


    RawTranscation.addOutput({
        address: DestionationAddress, // destination address
        value: send_coin // value in satoshi
    })

    RawTranscation.addOutput({
        address: DestionationAddress2, // destination address
        value: amount - send_coin - fee// value in satoshi
    })

    var scrypt = bitcoin.script.compile([bitcoin.opcodes.OP_RETURN, data]);
    RawTranscation.addOutput({
        script: scrypt,
        value: 0
    });

    /// Sign the transaction.

    var keyPair = bitcoin.ECPair.fromWIF(privateKey, testnet);
    RawTranscation.signInput(0, keyPair);
    var s1 = RawTranscation.validateSignaturesOfAllInputs();

    RawTranscation.finalizeAllInputs();

    const transaction = RawTranscation.extractTransaction();
    const signedTransaction = transaction.toHex();
    const transactionId = transaction.getId();

    /* For P2SH transaction use the following code instead the previous line. Make sure that the source address is a P2SH address
    
    const p2wpkh = bitcoin.payments.p2wpkh({ pubkey: keyPair.publicKey, network: bitcoin.networks.testnet })
    const p2sh = bitcoin.payments.p2sh({ redeem: p2wpkh, network: bitcoin.networks.testnet })
    RawTransaction.sign(0, keyPair, p2sh.redeem.output, null, parseInt(amount))
    */

    /// Push the transaction

    /// RPC.

    const Client = require('bitcoin-core');
    const client = new Client({
        username: 'user_name',
        password: 'your_password',
        network: 'testnet'
    });
    client.sendRawTransaction(signedTransaction, (error, response) => {
        if (error) console.log(error);
        console.log(response);
    });

    /// RPC, not work. :(

    // const http = require("http");
    // const options = {
    //     "method": "POST",
    //     "hostname": "localhost",
    //     "port": "18332",
    //     "headers": {
    //         "Content-Type": "application/json",
    //     }
    // };
    // const req = http.request(options, function (res) {
    //     const chunks = []
    //     res.on("data", function (chunk) {
    //         chunks.push(chunk)
    //     })
    //     res.on("end", function () {
    //         const body = Buffer.concat(chunks)
    //     })
    // });
    // req.write(JSON.stringify({        
    //     method: 'sendrawtransaction',
    //     params: [signedTransaction],
    //     id: '1'
    // }));
    // req.end();


    /// API, not work. :(

    // var headers = {
    //     'accept': 'application/json',
    //     'Content-Type': 'text/plain'
    // };

    //     var Sendingoptions = { 
    //         method: 'POST', 
    //         url: 'https://btctest.haskoin.com/api/transactions', 
    //         headers: headers,
    //         body: signedTransaction, 
    //         json: true 
    //     };

    //     rp(Sendingoptions).then(function (response) {
    //         var Jresponse = JSON.stringify(response);
    //         console.log("Transcation ID:\n" + Jresponse);
    //     }).catch(function (err) { console.error(err); });

}).catch(function (err) { console.error(err); });
