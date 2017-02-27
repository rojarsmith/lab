/*
 * StructLab.cpp
 *
 *  Created on: 2017年2月27日
 *      Author: rojar
 */

#include "StructLab.hpp"

StructLab::StructLab() {
	inflatable guest = { "Rojar Smith", 1.88, 2.99 };
	inflatable guest2 = guest;
	guest2.price = 11;
	torgle_reg tr = { 14, true, false };
	(void)guest2;
	(void)tr;
}

StructLab::~StructLab() {
}

