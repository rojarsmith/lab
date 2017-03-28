/*
 * BaseLab.cpp
 *
 *  Created on: 2017年3月28日
 *      Author: rojar
 */

#include "BaseLab.hpp"

BaseLab::BaseLab() {
	// TODO Auto-generated constructor stub

}

BaseLab::~BaseLab() {
	// TODO Auto-generated destructor stub
}

void BaseLab::printAddressAndValue(int &value){
	cout << "address=" << &value << ", value=" << value << endl;
}
