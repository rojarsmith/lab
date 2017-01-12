/*
 * TwoSum.h
 *
 *  Created on: 2017年1月11日
 *      Author: rojar
 */

#ifndef LEETCODE_TWOSUM_H_
#define LEETCODE_TWOSUM_H_

#include <vector>

using namespace std;

class TwoSum {
public:
	vector<int> twoSum(vector<int>&, int);
    vector<int> twoSum_Slow(vector<int>&, int);

	TwoSum();
	virtual ~TwoSum();
};

#endif /* LEETCODE_TWOSUM_H_ */
