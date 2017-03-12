/*
 * PointerLab.cpp
 *
 *  Created on: 2017年2月27日
 *      Author: rojar
 */

#include <iostream>
#include "PointerLab.hpp"

using namespace std;

struct Human
{
	int height;
};

int * v1 = new int;
int * v2 = new int [10];

PointerLab::PointerLab() {
	*v1 = 12345;
	cout << "Val=" << *v1 << ", Loc=" << v1 << ", size=" << sizeof v1 << endl;


	//Puzzle
	int v3[10] = { 1,2,3,4,5 };
	int (*v4)[10] = &v3;
	cout << v3 << ", size=" << sizeof v3 << endl;
	cout << &v3 << ", size=" << sizeof &v3 << endl;
	cout << &v3[0] << ", size=" << sizeof &v3[0] << endl;
	cout << v3 + 1 << endl;
	cout << &v3 + 1 << endl;
	cout << (&v3 + 1) - &v3 << endl;
	cout << v4 << ", size=" << sizeof v4 << endl;
	cout << *v4 << ", size=" << sizeof *v4 << endl;
	cout << (*v4)[0] << ", size=" << sizeof (*v4)[0] << endl;

	//Puzzle
	char flower[10] = "rose";
	cout << flower << "s are red \n";

	//Puzzle
	Human h1, h2 ,h3;
	h1.height = 100;
	h2.height = 122;
	const Human * arp[3] = {&h1, &h2, &h3};
	const Human ** ppa = arp;
	cout << (*ppa)->height << endl;
	cout << (*(ppa+1))->height << endl;
}

PointerLab::~PointerLab() {
	delete v1;
	delete [] v2;
}

