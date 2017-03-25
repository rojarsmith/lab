/*
 * PointerLab.cpp
 *
 *  Created on: 2017年2月27日
 *      Author: rojar
 */

#include <iostream>
#include "PointerLab.hpp"

using namespace std;

struct Human {
	int height;
};

int * v1 = new int;
int * v2 = new int[10];

PointerLab::PointerLab() {
	*v1 = 12345;
	cout << "Val=" << *v1 << ", Loc=" << v1 << ", size=" << sizeof v1 << endl;

	//Puzzle
	int v3[10] = { 1, 2, 3, 4, 5 };
	int (*v4)[10] = &v3;
	cout << v3 << ", size=" << sizeof v3 << endl;
	cout << &v3 << ", size=" << sizeof &v3 << endl;
	cout << &v3[0] << ", size=" << sizeof &v3[0] << endl;
	cout << v3 + 1 << endl;
	cout << &v3 + 1 << endl;
	cout << (&v3 + 1) - &v3 << endl;
	cout << v4 << ", size=" << sizeof v4 << endl;
	cout << *v4 << ", size=" << sizeof *v4 << endl;
	cout << (*v4)[0] << ", size=" << sizeof(*v4)[0] << endl;

	//Puzzle
	char flower[10] = "rose";
	cout << flower << "s are red \n";

	//Puzzle
	Human h1, h2, h3;
	h1.height = 100;
	h2.height = 122;
	const Human * arp[3] = { &h1, &h2, &h3 };
	const Human ** ppa = arp;
	cout << (*ppa)->height << endl;
	cout << (*(ppa + 1))->height << endl;

	//Function pointer.
	double av1[3] = { 1112.3, 2223.4, 3334.5 };

	//Pointer to a function.
	const double * (PointerLab::*fp1)(const double *, int) = func1;
	cout << "address=" << (this->*fp1)(av1, 3);
	cout << ", value=" << *(this->*fp1)(av1, 3) << endl;

	cout << "An array of pointers." << endl;
	const double * (PointerLab::*fpa1[3])(const double *, int) = {func1, func2, func3};
	for(int i = 0; i < 3; i++){
		cout << "address=" << (this->*fpa1[i])(av1, 3);
		cout << ", value=" << *(this->*fpa1[i])(av1, 3) << endl;
	}

	cout << "A pointer to first element of array of pointers." << endl;
	const double * (PointerLab::**fpab1)(const double *, int) = fpa1;
	for(int i = 0; i < 3; i++){
			cout << "address=" << (this->*fpab1[i])(av1, 3);
			cout << ", value=" << *(this->*fpab1[i])(av1, 3) << endl;
	}

	cout << "A pointer to an array of function pointers." << endl;
	const double * (PointerLab::*(*fpac1)[3])(const double *, int) = &fpa1;
	const double * pbd =  (this->*(*fpac1)[2])(av1, 3);
	for(int i = 0; i < 3; i++){
			cout << "address=" << (this->*(*fpac1)[i])(av1, 3);
			cout << ", value=" << *(this->*(*fpac1)[i])(av1, 3) << endl;
	}
}

PointerLab::~PointerLab() {
	delete v1;
	delete[] v2;
}

const double * PointerLab::func1(const double * ar, int n) {
	return ar;
}

const double * PointerLab::func2(const double ar[], int n) {
	return ar + 1;
}

const double * PointerLab::func3(const double * ar, int n) {
	return ar + 2;
}
