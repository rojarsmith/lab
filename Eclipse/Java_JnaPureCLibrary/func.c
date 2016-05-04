/*
 * func.c
 *
 *  Created on: 2014/7/13
 *      Author: administrator
 *
 *
 *      click [Properties->C/C++ Build->Settings->Build Steps]
 *      select [All configurations]
 *      on [Post-Build steps] key in:
 *       cp *.so ../../Jna/bin
 *
 *       or
 *
 *       cp *.dll ../../Jna/bin
 *
 *       for auto copy .so to java project.
 *
 *
 *       if on the windows 64bit platform,
 *       you must setting compile for 64 bit yourself
 *       click [Properties->C/C++ Build->Settings->Tool Settings]
 *       select [Miscellaneous]
 *
 *       on [Other flags] add parameter: -m64
 *
 *       Important :
 *       64bit JRE need 64bit C Library
 *       32bit JRE need 32bit C Library
 *
 */

#include "func.h"
#include "string.h"

int add(int input1, int input2) {
	return input1 + input2;
}

order get_order(int order_items_count) {
	order r;

	r.order_items_count = order_items_count;
	order_item *ois;
	ois = (order_item *) malloc(order_items_count * sizeof(order_item));
	r.order_items = ois;

	int i;
	for (i = 0; i < order_items_count; i++) {
		int name_index = i + 1;
		r.order_items[i].order_count = name_index;

		item oi;
		char str1[7] = "order";
		char str2[2];
		sprintf(str2, "%d", name_index);
		strcat(str1, str2);
		oi.name = (char*) malloc(sizeof(char) * (strlen(str1) + 1));
		strcpy(oi.name, str1);
		oi.weight = 0.1 + i;
		r.order_items[i].order_item = oi;
	}

	return r;
}

order* get_order_return_point(int order_items_count) {
	order* r;
	r = malloc(sizeof(order));

	r->order_items_count = order_items_count;
	order_item *ois;
	ois = (order_item *) malloc(order_items_count * sizeof(order_item));
	r->order_items = ois;

	int i;
	for (i = 0; i < order_items_count; i++) {
		int name_index = i + 1;
		r->order_items[i].order_count = name_index;

		item oi;
		char str1[7] = "order";
		char str2[2];
		sprintf(str2, "%d", name_index);
		strcat(str1, str2);
		oi.name = (char*) malloc(sizeof(char) * (strlen(str1) + 1));
		strcpy(oi.name, str1);
		oi.weight = 0.1 + i;
		r->order_items[i].order_item = oi;
	}

	return r;
}

order change_order(order* input, float new_weight) {
	int order_items_count = input->order_items_count;

	int i;
	for (i = 0; i < order_items_count; i++) {
		input->order_items[i].order_item.weight += (new_weight + 10);
	}

	return *input;
}
