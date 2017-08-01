/*
 *  Created on: 2017/8/1
 *      Author: Rojar
 */

#ifndef FORWARD_DECLARATION_HPP
#define FORWARD_DECLARATION_HPP

using namespace std;

class Animal;

class ForwardDeclaration {
public:
	ForwardDeclaration();
	virtual ~ForwardDeclaration();

	Animal *animal1();
private:
	Animal *m_animal1;
};

#endif /* FORWARD_DECLARATION_HPP */
