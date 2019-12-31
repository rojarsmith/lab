/// Building a P2PKH script using JavaScript

var bitcore = require('bitcore-lib');
var Address = bitcore.Address;
var address = Address.fromString('2MwKb8iyJyRKR1WfE1EfVsyS5xyXmXYftYz');
var script = bitcore.Script.buildPublicKeyHashOut(address);
console.log(script);