console.log("Hello world!");

// curried function
const add = x => y => x + y;
console.log(add(1)(2));

const add2 = function (x) {
    return function (y) {
        return x + y
    }
}

console.log(add2(1)(2));

// timer
var timer = require('./timer');
console.log(timer);
// timer.timer();
timer.timer2();
timer.timer3();
timer.timer4();
timer.timer5();
timer.timer6();
