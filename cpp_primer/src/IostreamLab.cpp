/*
 * IostreamLab.cpp
 *
 *  Created on: 2017年3月19日
 *      Author: rojar
 */

#include "IostreamLab.hpp"

#include <iostream>

using namespace std;

IostreamLab::IostreamLab() {
	//Chapter 6, Q3
	char ch;
	int ct1, ct2;

	ct1 = ct2 = 0;
	while((ch=cin.get()) != '$')
	{
		cout << ch;
		ct1++;
		if(ch='$')
			ct2++;
		cout<<ch;
	}
	cout <<"ct1 = " << ct1 << ", ct2 = " << ct2 << "\n";
	return;

}

IostreamLab::~IostreamLab() {
}

