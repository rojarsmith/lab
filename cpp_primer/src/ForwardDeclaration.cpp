/*
 *  Created on: 2017/8/1
 *      Author: Rojar
 */

#include "ForwardDeclaration.hpp"
#include "Animal.hpp"

ForwardDeclaration::ForwardDeclaration() :
		m_animal1(0) {
	m_animal1 = new Animal();
	this->animal1()->setSpecies("SPE1");
}

ForwardDeclaration::~ForwardDeclaration() {
	if(m_animal1){
		delete m_animal1;
	}
}

Animal *ForwardDeclaration::animal1() {
	return m_animal1;
}
