/*
 * entry_point.c
 *
 *  Created on: 2014/7/13
 *      Author: administrator
 */

#include <stdio.h>
#include <func.h>

int main(void) {
	int r1 = add(1, 2);
	printf("test func [add]\n");
	printf("return : %d\n", r1);

	order o1;
	int order_LENGTH = 3;
	o1 = get_order(order_LENGTH);
	printf("test func [get_order]\n");
	printf("order_items_count : %d\n", o1.order_items_count);
	int i;
	for (i = 0; i < order_LENGTH; i++) {
		printf("order_item [%d]\n", i);
		printf("order_count : %d\n", o1.order_items[i].order_count);
		printf("name : %s\n", o1.order_items[i].order_item.name);
		printf("weight : %.1f\n", o1.order_items[i].order_item.weight);
	}

	order *o2 = get_order_return_point(order_LENGTH);
	printf("test func [get_order_return_point]\n");
	printf("order_items_count : %d\n", o2->order_items_count);
	for (i = 0; i < order_LENGTH; i++) {
		printf("order_item [%d]\n", i);
		printf("order_count : %d\n", o2->order_items[i].order_count);
		printf("name : %s\n", o2->order_items[i].order_item.name);
		printf("weight : %.1f\n", o2->order_items[i].order_item.weight);
	}

	order o3 = change_order(&o1, (float)0.9);
	printf("test func [change_order]\n");
	printf("order_items_count : %d\n", o3.order_items_count);
	for (i = 0; i < order_LENGTH; i++) {
		printf("order_item [%d]\n", i);
		printf("order_count : %d\n", o3.order_items[i].order_count);
		printf("name : %s\n", o3.order_items[i].order_item.name);
		printf("weight : %.1f\n", o3.order_items[i].order_item.weight);
	}

	return 0;
}
