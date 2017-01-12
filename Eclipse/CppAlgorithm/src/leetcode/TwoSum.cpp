/*
 * TwoSum.cpp
 *
 *  Created on: 2017年1月11日
 *      Author: rojar
 */

#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
#include "TwoSum.h"

/*
 * Two Sum
 *
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 *
 * Example:
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 *
 * return [0, 1].
 *
 */

vector<int> TwoSum::twoSum(vector<int>& nums, int target) {
	map<int, int> hash;
	vector<int> ans;
	int s = nums.size();

	for (int i = 0; i < s; i++) {
		int v = target - nums.at(i);
		if (hash.find(v) != hash.end() && hash.at(v) != i) {
			ans.push_back(i);
			ans.push_back(hash.at(v));
			break;
		} else {
			hash[nums.at(i)] = i;
		}
	}

	return ans;
}

vector<int> TwoSum::twoSum_Slow(vector<int>& nums, int target) {
	int idx1 = nums.size();
	int idx2 = idx1 - 1;
	vector<int> ans;
	bool flag = false;

	//find target.
	for (int i = 0; i < idx2; i++) {
		int i1 = i + 1;
		for (int j = i1; j < idx1; j++) {
			if (target == nums.at(i) + nums.at(j)) {
				ans.push_back(i);
				ans.push_back(j);
				flag = true;
				break;
			}
		}

		if (flag) {
			break;
		}
	}

	return ans;
}

TwoSum::TwoSum() {
	double start, end;
	int loop = 1000000;

	int array1[] = { 1, 4, 3, 9, 65, 13, 0 };
	vector<int> vector1(array1, array1 + sizeof(array1) / sizeof(*array1));

	start = clock();
	vector<int> ans1;
	for (int i = 0; i < loop; i++) {
		ans1 = twoSum_Slow(vector1, 14);
	}
	end = clock();

	for (int i = 0; i < 2; i++) {
		cout << ans1.at(i) << " ";
	}
	cout << "use=" << (end - start) / CLOCKS_PER_SEC << " s" << endl;
	cout << endl;

	start = clock();
	vector<int> ans2;
	for (int i = 0; i < loop; i++) {
		ans2 = twoSum_Slow(vector1, 14);
	}
	end = clock();

	for (int i = 0; i < 2; i++) {
		cout << ans2.at(i) << " ";
	}
	cout << "use=" << (end - start) / CLOCKS_PER_SEC << " s" << endl;
	cout << endl;
}

TwoSum::~TwoSum() {
}

