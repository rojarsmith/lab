console.log("Hello world!");

// curried function
const add = x => y => x + y;
console.log(add(1)(2));
console.log(add(1));

const add2 = function (x) {
    return function (y) {
        return x + y
    }
}

console.log(add2(1)(2));

// timer
var timer = require('./timer');
console.log(timer);
// timer.lab1();

var data = require('./data.js');

console.log(data)
console.log(data.array1.flat())
console.log(data.array1.flat(2))
var dbg0 = data.array1.flat(Infinity)
console.log(dbg0)
console.log(dbg0.toString())
console.log(data.array1)

const reducer = (accumulator, currentValue) => accumulator + currentValue;

// Dont't use multi level data array for reduce.
console.log(data.array1.reduce(reducer))

console.log(dbg0.reduce(reducer))

function flatten1(arr) {
    return arr.toString().split(",").map(item => +item);
}

console.log(flatten1(data.array1))
console.log(flatten1(data.array1).toString())
