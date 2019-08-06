#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
	uint16_t id;
	uint16_t data[50];
} QueueMessage_t;

int var = 1234;

void func1();
void pointerTo1dimensionalArrays();
void pointerTo2dimensionalArrays();
void pointerTo3dimensionalArrays();
void subscriptingPointerToAnArray();

int main() {
	int *ptr;
	ptr = &var;
	printf("\nDirect access, variable var value = var = %d", var);
	printf("\n\nThe memory address of variable var = &var = %p", &var);
	printf("\nThe memory address of variable var = ptr = %p\n", ptr);

	func1();
	pointerTo1dimensionalArrays();
	pointerTo2dimensionalArrays();
	pointerTo3dimensionalArrays();
	subscriptingPointerToAnArray();

	return EXIT_SUCCESS;
}

void func1() {
	QueueMessage_t xMessageRX;
	printf("size = %llu\n", sizeof(QueueMessage_t));
	printf("size = %llu\n", sizeof(QueueMessage_t*));
	printf("size = %p\n", &xMessageRX);
}

void pointerTo1dimensionalArrays() {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *ptr = arr;
	printf("%p\n", ptr);

	// Pointer to an insteger
	int *p;

	// Pinter to an array of 5 integers
	int (*ptr2)[5];

	int arr2[5];

	// Points to 0th element of the arr2.
	p = arr2;

	// Points to the whole array arr2.
	ptr2 = &arr2;

	printf("p = %p, ptr = %p\n", p, ptr2);

	p++;
	ptr2++;

	printf("p = %p, ptr = %p\n", p, ptr2);

	printf("p = %p, ptr = %p\n", p, ptr2);

	printf("*p = %d, *ptr2 = %p\n", *p, *ptr2);

	printf("sizeof(p) = %lu, sizeof(*p) = %lu\n", sizeof(p), sizeof(*p));
	printf("sizeof(ptr) = %lu, sizeof(*ptr) = %lu\n", sizeof(ptr2), sizeof(*ptr2));
}

void pointerTo2dimensionalArrays() {
	int arr[3][4] =
			{ { 10, 11, 12, 13 }, { 20, 21, 22, 23 }, { 30, 31, 32, 33 } };
	int i, j;
	for (i = 0; i < 3; i++) {
		printf("Address of %dth array = %p %p\n", i, arr[i], *(arr + i));

		for (j = 0; j < 4; j++) {
			printf("%d %d ", arr[i][j], *(*(arr + i) + j));
		}

		printf("\n");
	}
}

void pointerTo3dimensionalArrays() {
	int arr[2][3][2] = { { { 5, 10 }, { 6, 11 }, { 7, 12 }, }, { { 20, 30 }, {
			21, 31 }, { 22, 32 }, } };
	int i, j, k;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 2; k++) {
				printf("%d\t", *(*(*(arr + i) + j) + k));
			}

			printf("\n");
		}
	}
}

void subscriptingPointerToAnArray() {
	int arr[3][4] =
			{ { 10, 11, 12, 13 }, { 20, 21, 22, 23 }, { 30, 31, 32, 33 } };
	int (*ptr)[4];
	ptr = arr;

	printf("%p %p %p\n", ptr, ptr + 1, ptr + 2);
	printf("%p %p %p\n", *ptr, *(ptr + 1), *(ptr + 2));
	printf("%d %d %d\n", **ptr, *(*(ptr + 1) + 2), *(*(ptr + 2) + 3));
	printf("%d %d %d\n", ptr[0][0], ptr[1][2], ptr[2][3]);
}
