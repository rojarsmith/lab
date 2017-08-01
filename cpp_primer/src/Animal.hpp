/*
 *  Created on: 2017/8/1
 *      Author: Rojar
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

using namespace std;

class Animal {
public:
	Animal();
	virtual ~Animal();

	void setSpecies(string species);
private:
	string species;
};

#endif /* ANIMAL_HPP */
