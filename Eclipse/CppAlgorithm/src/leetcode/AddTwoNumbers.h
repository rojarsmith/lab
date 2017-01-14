/*
 * AddTwoNumbers.h
 *
 *  Created on: 2017年1月14日
 *      Author: rojar
 */

#ifndef LEETCODE_ADDTWONUMBERS_H_
#define LEETCODE_ADDTWONUMBERS_H_

#include <cstddef>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class AddTwoNumbers {
protected:

public:
	ListNode* addTwoNumbers(ListNode*, ListNode*);
	AddTwoNumbers();
	virtual ~AddTwoNumbers();
};

#endif /* LEETCODE_ADDTWONUMBERS_H_ */
