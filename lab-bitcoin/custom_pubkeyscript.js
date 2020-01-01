/// Build custom script.
/// Worked on 0.19.x :)

var bitcore = require('bitcore-lib');
bitcore.Transaction = require('bitcore-lib').Transaction;
bitcore.Script = require('bitcore-lib').Script;
bitcore.PublicKey = require('bitcore-lib').PublicKey;
var Networks = require('bitcore-lib').Networks;
Networks.enableRegtest();

var privateKey = bitcore.PrivateKey.fromWIF('cTLvv9HzNzweeez4azFKZtAgxZd56phrGMN1kC3A3iSgofjAeGc5');
var addr1 = privateKey.toAddress().toString();

var privateKey2 = bitcore.PrivateKey.fromWIF('cPQmMMNZRB2xyLrADDwRfvvVkGnNLyu2w6awa9qQQtR8xiokFpLh');
var addr2 = privateKey2.toAddress().toString();

var lockingscript = bitcore.Script().add('OP_13')
    .add('OP_ADD')
    .add('OP_15')
    .add('OP_EQUAL');

var txId = '58db4df17e73cb253d1ff669aff4de3f22e135c6e037b0abcde9058c2c86250f';
var pkey = 'cTLvv9HzNzweeez4azFKZtAgxZd56phrGMN1kC3A3iSgofjAeGc5'; //UTXOs private key
var scriptPubKey = '76a914165ac25f964d6e72cba2564037149b9f4da6886c88ac';

var Saddress = 'mhZ9tLcdg9gaW3tkea3qTjtFidx5jqNp3x';
var Taddress = 'mrbBqiKUKxPdwk8dRESWJkQXPENR63TLtZ'; //Destination address

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
//transaction = transaction.fee(0.0005 * 100000000);
transaction = transaction.fee(100000);
transaction = transaction.addOutput(new bitcore.Transaction.Output({
    script: lockingscript,
    satoshis: 999900000,
    address: Taddress
}));
transaction = transaction.sign(pkey); //Sign all inputs
console.log("Raw Transaction\n" + transaction);

var sys = require('sys')
var exec = require('child_process').exec;
function puts(error, stdout, stderr) { console.log(stdout) }
exec("bitcoin-cli decoderawtransaction "+transaction, puts);