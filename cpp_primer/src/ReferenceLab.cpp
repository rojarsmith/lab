/*
 * ReferenceLab.cpp
 *
 *  Created on: 2017年3月28日
 *      Author: rojar
 */

#include <iostream>
#include "ReferenceLab.hpp"
#include "BaseLab.hpp"

using namespace std;

ReferenceLab::ReferenceLab() {
	int v1 = 0;
	BaseLab::printAddressAndValue(v1);
	this->Func1(v1);
	BaseLab::printAddressAndValue(v1);
}

ReferenceLab::~ReferenceLab() {
}

void ReferenceLab::Func1(int &v1){
	v1 = 100;
}
