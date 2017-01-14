/*
 * ZigZagConversion.cpp
 *
 *  Created on: 2017年1月13日
 *      Author: rojar
 */

#include <ctime>
#include <iostream>
#include "ZigZagConversion.h"

string ZigZagConversion::convert(string s, int numRows) {
	if(numRows <= 1){
		return s;
	}

	int c = 2 * numRows - 2;
	string a[numRows];
	int l = s.size();

	for (int i = 0; i < l; i++) {
		int i1 = i % c;
		if (i1 < numRows) {
			a[i1].append(s, i, 1);
		} else {
			int i2 = c - i1;
			a[i2].append(s, i, 1);
		}
	}

	string ans = "";
	for (int i = 0; i < numRows; i++) {
		int l = a[i].size();
		ans.append(a[i], 0, l);
	}

	return ans;
}

ZigZagConversion::ZigZagConversion() {
	double start, end;
	int loop = 1000000;

	string s1 = "ABCDEFGHIJKLMN";

	start = clock();
	string ans1;
	for (int i = 0; i < loop; i++) {
		ans1 = convert(s1, 1);
	}
	end = clock();

	cout << ans1 << " ";
	cout << "use=" << (end - start) / CLOCKS_PER_SEC << " s" << endl;
	cout << endl;
}

ZigZagConversion::~ZigZagConversion() {
}

