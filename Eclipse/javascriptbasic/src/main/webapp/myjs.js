/**
 * 
 */
function Person(first, last) {
    this.first = first;
    this.last = last;
}
Person.prototype.fullName = function() {
    return this.first + ' ' + this.last;
}
Person.prototype.fullNameReversed = function() {
    return this.last + ', ' + this.first;
}

function lastNameCaps() {
    return this.last.toUpperCase();
}

function makeAdder(a) {
    return function(b) {
        return a + b;
    }
}

var v1, v2;

try {
    eval("alert('Hello)");   // Missing ' will produce an error
}
catch(err) {
    v1 = err.name;
}

x = makeAdder(5);
y = makeAdder(20);
v1 = x(6);
v2 = y(7);

v1 = new Person("Simon", "Willison");
v2 = lastNameCaps.call(v1);

v1 = new Person("Simon", "Willison");
Person.prototype.toString = function() {
    return '<Person: ' + this.fullName() + '>';
};
v2 = v1.toString();

v1 = "Simon";
String.prototype.reversed = function() {
    var r = "";
    for (var i = this.length - 1; i >= 0; i--) {
        r += this[i];
    }
    return r;
}
v2 = v1.reversed();

v1 = new Person("Simon", "Willison");
Person.prototype.firstNameCaps = function() {
    return this.first.toUpperCase();
};
v2 = v1.firstNameCaps();

v1 = makePerson("Simon", "Willison");
v2 = v1.fullName();
v2 = v1.fullNameReversed();

v1 = funccounter();
v1 = funccounter();
v1 = funccounter();

v1 = (function(elm) {
    if (elm.nodeType == 3) { // TEXT_NODE
        return elm.nodeValue.length;
    }
    var count = 0;
    for (var i = 0, child; child = elm.childNodes[i]; i++) {
        count += arguments.callee(child);
    }
    return count;
})(document.body);

var a = 1, b = 2;
(function() {
    var b = 3;
    a += b;
})();
v1 = a;
v2 = b;

var v2 = function() {
	var sum = 0;
	for (var i = 0, j = arguments.length; i < j; i++) {
		sum += arguments[i];
	}
	return sum / arguments.length;
}
v1 = v2.apply(null, [ 2, 3, 4, 5 ]);

v1 = avg.apply(null, [ 2, 3, 4, 5 ]);
v1 = [ 2, 4, 8, 12 ];
v1 = avgArray(v1);
v1 = avgArray([ 2, 3, 4, 5 ]);
v1 = add2(2, 3, 4);
v1 = add();
v1 = add(2, 3, 4);

v1 = [ 'dog', 'cat', 'fish' ];
v1[10] = 'pig';
for ( var i in v1) {
	v1[i] = 'aaa';
}
v1[v1.length] = 'end';

v1 = [ 'dog', 'cat', 'fish' ];
v2 = v1.length;
v1[10] = 'pig';
v2 = v1.length;

for (var i = 0, len = v1.length; i < len; i++) {
	v1[i] = 'AAA' + i;
}

v1 = new Array();
v1[0] = 'dog';
v1[1] = 'cat';
v1[2] = 'fish';
v2 = v1.length;

v1 = {
	name : 'rojar',
	'for' : 'smith',
	details : {
		color : 'red',
		size : 12
	}
};

v2 = v1.details.color;
v2 = v1['details']['size'];

v1 = new Object();
v1.name = 'rojar';
v2 = v1.name;
v1['name'] = 'smith';
v2 = v1['name'];

switch (1 + 3) {
case 2 + 2:
	v1 = 6;
	break;
}

v1 = 'run';
switch (v1) {
case 'run':
	v2 = 10;
	break;
case 'stop':
case 'play':
	break;
default:
	v2 = 30;
}

v2 = 15;
v1 = (v2 > 18) ? 'Y' : 'N';

v1 = v1 && v1.getName;
v1 = v1 || 'default';

v1 = 3;
do {
	v1--
} while (v1 > 0)

v1 = 3;
while (v1 > 0) {
	v1--;
}

v1 = 'Cat';
if (v1 == 'Dog') {
	v1 += '!';
} else if (v1 == 'Cat') {
	v1 += '!!';
} else {
	v1 = '!' + v1;
}
v1 = v1 == 'Cat!!';

v1 = 'dog' == 'dog';
v1 = 1 == true;
v1 = 1 === true;
v1 = true === true;

v1 = 3 + 4 + '5';
v1 = '3' + 4 + 5;
v1 = 'hello' + ' world';
v1 = 1;
v1 += 5;
v1 = v1 + 5;

v1 = Boolean('');
v1 = Boolean(234);

// String Type
v1 = 'hello'.length;
v1 = 'hello'.charAt(0);
v1 = 'hello, world'.replace('hello', 'goodbye');
v1 = 'hello'.toUpperCase();

// Number Type
v1 = 1 / 0;
v1 = -1 / 0;
v1 = isNaN(NaN);
v1 = NaN + 5;
v1 = parseInt('hello', 10);
v1 = parseInt('11', 2);
v1 = parseInt('010');
v1 = parseInt('010', 10);
v1 = parseInt('123', 10);
v1 = Math.sin(3.5);
v1 = 0.1 + 0.2; // 0.30000000000000004

v1 = 'END';




function makePerson(first, last) {
    return {
        first: first,
        last: last,
        fullName: function() {
            return this.first + ' ' + this.last;
        },
        fullNameReversed: function() {
            return this.last + ', ' + this.first;
        }
    }
}

function funccounter() {
    if (!arguments.callee.count) {
        arguments.callee.count = 0;
    }
    return arguments.callee.count++;
}

function avgArray(arr) {
	var sum = 0;
	for (var i = 0, j = arr.length; i < j; i++) {
		sum += arr[i];
	}
	return sum / arr.length;
}

function avg() {
	var sum = 0;
	for (var i = 0, j = arguments.length; i < j; i++) {
		sum += arguments[i];
	}
	return sum / arguments.length;
}

function add2() {
	var sum = 0;
	for (var i = 0, j = arguments.length; i < j; i++) {
		sum += arguments[i];
	}
	return sum;
}

function add(x, y) {
	var total = x + y;
	return total;
}