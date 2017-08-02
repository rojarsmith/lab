/*
 *  Created on: 2017/8/2
 *      Author: Rojar
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include "Lambda.hpp"

using namespace std;

bool Lambda::condition1(int value) {
	return (value > 5);
}

Lambda::Lambda() {
	auto lambda = []() {cout << "Hello, Lambda" << endl;};
	lambda();
	auto lambda2 = [] {cout << "Hello, Lambda2" << endl;};
	lambda2();
	auto lambda3 = [](void) {cout << "Hello, Lambda3" << endl;};
	lambda3();
	auto lambda4 = [](void) -> void {cout << "Hello, Lambda4" << endl;};
	lambda4();
	int lambda5 = [](int x, int y) {return x+y;}(5, 4);
	cout << lambda5 << endl;

	vector<int> numbers { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
	auto count1 = count_if(numbers.begin(), numbers.end(), bind1st(mem_fun(&Lambda::condition1), this));
	cout << "Count: " << count1 << endl;

	vector<int> numbers2 { 1, 2, 3, 4, 5, 10, 15, 20, 25, 35, 45, 50 };
	auto count2 = count_if(numbers2.begin(), numbers2.end(),
			[](int x) {return (x > 5);});
	cout << "Count2: " << count2 << endl;
}

Lambda::~Lambda() {
}
