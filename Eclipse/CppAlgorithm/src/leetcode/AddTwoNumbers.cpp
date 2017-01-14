/*
 * AddTwoNumbers.cpp
 *
 *  Created on: 2017年1月14日
 *      Author: rojar
 */

#include "AddTwoNumbers.h"

/*
 * Add Two Numbers
 *
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *
 * Output: 7 -> 0 -> 8
 */

#include <ctime>
#include <iostream>

using namespace std;

ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* tmp = new ListNode(0);
	ListNode* ans = tmp;

	int sum = 0;
	int carry = 0;

	while (l1 != NULL || l2 != NULL || carry > 0) {
		sum = 0;

		if (NULL != l1) {
			sum += l1->val;
			l1 = l1->next;
		}

		if (NULL != l2) {
			sum += l2->val;
			l2 = l2->next;
		}

		sum += carry;
		tmp->next = new ListNode(sum%10);
		carry = sum/10;

		tmp = tmp->next;
	}

	return ans->next;
}

AddTwoNumbers::AddTwoNumbers() {
	double start, end;
	int loop = 1000000;

	ListNode * ln1 = new ListNode(2);
	ListNode * ln1_2 = new ListNode(4);
	ListNode * ln1_3 = new ListNode(3);
	ln1->next = ln1_2;
	ln1_2->next = ln1_3;
	ListNode * ln2 = new ListNode(5);
	ListNode * ln2_2 = new ListNode(6);
	ln2->next = ln2_2;

	start = clock();
	ListNode* ans1;
	for (int i = 0; i < loop; i++) {
		ans1 = addTwoNumbers(ln1, ln2);
	}
	end = clock();

	while (NULL != ans1) {
		cout << ans1->val << " ";
		ans1 = ans1->next;
	}
	cout << "use=" << (end - start) / CLOCKS_PER_SEC << " s" << endl;
	cout << endl;
}

AddTwoNumbers::~AddTwoNumbers() {
}

