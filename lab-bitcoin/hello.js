var bitcoin = require('bitcoinjs-lib');
var rp = require('request-promise');

var data = Buffer.from('Hello World', 'utf8');
var testnet = bitcoin.networks.testnet;
var privateKey = 'cRRDYNr2aSMKdn27iVvmbZhHnBzpTUCgaXuHY2hoe5PvLZrA3Fnz';
var SourceAddress = '2N421LSaY5TmM9NnvTzZxg2StpAMXgYfKTx';

var url = "https://btctest.haskoin.com/api/address/" + SourceAddress + "/unspent";

var DestionationAddress = '2N4a3TP4hkkEQsm1ToSciJSvLLrnmhyUNbL';

var options = {
    uri: url,
    json: true
};

rp(options).then(function (response) {
    console.log(response);
    var index = response.length - 1;
    console.log(response[index]); 
    var UtxoId = response[index].txid; 
    var vout = response.index; 
    var amount = Number(response[index].value);
    var fee = 0.0005 * 100000000;
}).catch(function (err) { console.error(err);});

