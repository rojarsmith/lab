/*
 * func.h
 *
 *  Created on: 2014/7/13
 *      Author: administrator
 */

#include "stdio.h"
#include "stdlib.h"

#ifndef FUNC_H_
#define FUNC_H_

typedef struct {
	char *name;
	float weight;
} item;

typedef struct {
	int order_count;
	item order_item;
} order_item;

typedef struct {
	int order_items_count;
	order_item *order_items;
} order;

int add(int input1, int input2);
order get_order(int order_items_count);
order* get_order_return_point(int order_items_count);
order change_order(order* input, float new_weight);

#endif /* FUNC_H_ */
