/*
 ============================================================================
 Name        : c-basic.c
 Author      : Rojar Smith
 Version     :
 Copyright   : None
 Description : Test basic feature in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
	uint16_t id;
	uint16_t data[50];
} QueueMessage_t;

int var = 1234;

void func1(){
	QueueMessage_t xMessageRX;
	printf("size = %llu\n", sizeof(QueueMessage_t));
	printf("size = %llu\n", sizeof(QueueMessage_t*));
	printf("size = %p\n", &xMessageRX);
}

int main(void) {
	int *ptr;
	ptr = &var;
	printf("\nDirect access, variable var value = var = %d", var);
	printf("\n\nThe memory address of variable var = &var = %p", &var);
	printf("\nThe memory address of variable var = ptr = %p\n", ptr);

	func1();

	func1();

	return EXIT_SUCCESS;
}
