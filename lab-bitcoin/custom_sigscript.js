/// Build custom script.
/// Worked :)

var bitcore = require('bitcore-lib');

var Taddress = 'mrbBqiKUKxPdwk8dRESWJkQXPENR63TLtZ'; //Destination address
var pkey = 'cPQmMMNZRB2xyLrADDwRfvvVkGnNLyu2w6awa9qQQtR8xiokFpLh'; //UTXOs private key
var txid = 'b80586d2bcb0b03b18880fb8160b6c62bc83f53bb105cea42706d2e28167e9a4';

var unlockingScript = bitcore.Script().add('OP_2');
var transaction = new bitcore.Transaction();
transaction.addInput(new bitcore.Transaction.Input({
    prevTxId: txid,
    outputIndex: 1,
    script: unlockingScript
}),
    unlockingScript,
    999900000);                                    
transaction = transaction.to(Taddress, 999800000);
transaction = transaction.fee(0.0001 * 100000000);

console.log("Raw Transaction\n"+transaction);