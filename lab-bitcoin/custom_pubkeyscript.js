/// Build custom script.
/// Not work...

var bitcore = require('bitcore-lib');
bitcore.Transaction = require('bitcore-lib').Transaction;
bitcore.Script = require('bitcore-lib').Script;
bitcore.PublicKey = require('bitcore-lib').PublicKey;
var Networks = require('bitcore-lib').Networks;
Networks.enableRegtest();

var lockingscript = bitcore.Script().add('OP_13')
    .add('OP_ADD')
    .add('OP_15')
    .add('OP_EQUAL');

var txId = '7926cdb99b77c369b633d7c9ae21510f4cfaf4206ff446e3ba9cdace972ef0b4';
var pkey = 'cQ2gMoiDDyVFtcQCA2pJJikfEV9aauvhrcehH5Ns6VakiVs4SwVp'; //UTXOs private key
var scriptPubKey = 'a914274a2210ff9b841d892dc34ff3b818ef9cbfb58e87';

var Saddress = '2Mvpy9cztY7K1en26a9mnV86vVY3bWTh9Rq';
var Taddress = '2NAx1fVt99EaztmkasGk6NXd4wDWEnd5VbP'; //Destination address

g_utxos = [{
    "address": Saddress,
    "txid": txId,
    "vout": 0,
    "scriptPubKey": scriptPubKey,
    "amount": 50.0
}]; //UTXO details

var transaction = new bitcore.Transaction();

transaction = transaction.from(g_utxos);
transaction = transaction.to(Taddress, 4000000000); // Add a first output with the given amount of satoshis
transaction = transaction.fee(0.0001 * 100000000);
transaction = transaction.addOutput(new bitcore.Transaction.Output({
    script: lockingscript,
    satoshis: 1000000000,
    address: Taddress
}));
transaction = transaction.sign(pkey); //Sign all inputs
console.log("Raw Transaction\n" + transaction);

var sys = require('sys')
var exec = require('child_process').exec;
function puts(error, stdout, stderr) { console.log(stdout) }
exec("bitcoin-cli decoderawtransaction "+transaction, puts);