exports.timer = () => {
    var timeoutID = setTimeout((() => console.log("delay 1 sec")), 1000);
    console.log(timeoutID);

    var timeoutID2 = setInterval((() => {
        console.log("loop delay 3 sec")
        console.log(timeoutID2);
        if (timeoutID2._idleStart > 10000) {
            clearTimeout(timeoutID2);
        }
    }), 2000);
}

// Wrong, delay not work, output is wrong.
// Out put will over < 5, Loop 6 times.
// Only fi
exports.timer2 = () => {
    for (var i = 0; i < 5; i++) {
        setTimeout(function () {
            console.log(i);
        }, 2000);
    }
}

// Using let. out put is correct.
// Log output run the same time nearly.
exports.timer3 = () => {
    for (let i = 0; i < 5; i++) {
        setTimeout(function () {
            console.log(i);
        }, 2000);
    }
}

// Using let. Delay not work, out put is correct.
exports.timer4 = () => {
    for (let i = 0; i < 5; i++) {
        (() => {
            setTimeout(function () {
                console.log(i);
            }, 2000 * i); // Notice: Delay is not the block function.
        })(i)
    }
}

exports.timer5 = () => {
    console.log('start');

    (function () {
        console.log('call function')

        setTimeout(function () {
            console.log('setTimeout');
        }, 0);
    })();

    console.log('end');
}

exports.timer6 = () => {
    var startTime = new Date().getTime();

    setTimeout(function () {
        var endTime = new Date().getTime();
        console.log('Time elapsed: ' + (endTime - startTime) + ' ms');
    }, 1000);
}
