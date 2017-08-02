/*
 * TemplateLab.cpp
 *
 *  Created on: 2017年4月1日
 *      Author: rojar
 */

#include "TemplateLab.hpp"
#include <iostream>

using namespace std;



TemplateLab::TemplateLab() {
	int i = 10, j = 20;
	this->Swap(i, j);
	cout << i << ", " << j << endl;

	Job job1 = {"aaa", 100, int(99.9)};
	Job job2 = {"bbb", 200, int(55.5)};
	this->Swap(job1, job2);
	cout << job1.salary << ", " << job1.floor << endl;
}

TemplateLab::~TemplateLab() {

}

template <typename T>
void TemplateLab::Swap(T &a, T &b){
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void TemplateLab::Swap<Job>(Job &a, Job &b){
	Job temp = a;
	a.floor = b.floor;
	a.salary = b.salary;
	b.floor = temp.floor;
	b.salary = temp.salary;
}
