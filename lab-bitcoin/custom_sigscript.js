/// Build custom script.
/// Not work....

var bitcore = require('bitcore-lib');

var Taddress = '2NAx1fVt99EaztmkasGk6NXd4wDWEnd5VbP'; //Destination address
var pkey = 'cQ2gMoiDDyVFtcQCA2pJJikfEV9aauvhrcehH5Ns6VakiVs4SwVp'; //UTXOs private key

var unlockingScript = bitcore.Script().add('OP_2');
var transaction = new bitcore.Transaction();
transaction.addInput(new bitcore.Transaction.Input({prevTxId:'c6758cf22346d3d8b7b6042b7701a5f07d140732bf5b93e1fb92ed250e5b6d20', outputIndex: 1, script: unlockingScript }), unlockingScript, 10000);
transaction = transaction.to(Taddress, 90000000);
transaction = transaction.fee(0.0001*100000000);

console.log(transaction);