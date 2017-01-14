/*
 * ReverseInteger.cpp
 *
 *  Created on: 2017年1月14日
 *      Author: rojar
 */

#include <ctime>
#include <iostream>
#include <limits>
#include "ReverseInteger.h"

using namespace std;

/*
 * Reverse Integer
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 *
 * Example2: x = -123, return -321
 *
 */

int ReverseInteger::reverse(int x) {
	long long ans = 0;
	int n = 0;

	while (0 != x) {
		n = x % 10;
		ans = 10 * ans + n;
		x = x / 10;
	}

	//max=2147483647, min=-2147483648
	if (numeric_limits<int>::max() < ans || numeric_limits<int>::min() > ans) {
		return 0;
	}

	return ans;
}

ReverseInteger::ReverseInteger() {
	double start, end;
	int loop = 1000000;

	int s1 = 1000000003;

	start = clock();
	int ans1;
	for (int i = 0; i < loop; i++) {
		ans1 = reverse(s1);
	}
	end = clock();

	cout << ans1 << " ";
	cout << "use=" << (end - start) / CLOCKS_PER_SEC << " s" << endl;
	cout << endl;
}

ReverseInteger::~ReverseInteger() {
}

