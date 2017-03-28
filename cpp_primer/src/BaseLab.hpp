/*
 * BaseLab.hpp
 *
 *  Created on: 2017年3月28日
 *      Author: rojar
 */

#ifndef BASELAB_HPP_
#define BASELAB_HPP_

#include<iostream>

using namespace std;

class BaseLab {
public:
	BaseLab();
	virtual ~BaseLab();

	static void printAddressAndValue(int &value);
};

#endif /* BASELAB_HPP_ */
