/*
 * TemplateLab.h
 *
 *  Created on: 2017年4月1日
 *      Author: rojar
 */

#ifndef TEMPLATELAB_HPP_
#define TEMPLATELAB_HPP_

	struct Job
	{
		char name[40];
		double salary;
		int floor;
	};

class TemplateLab {
public:


	TemplateLab();
	virtual ~TemplateLab();

	template <typename T> void Swap(T &a, T &b); // template

};

template <> void TemplateLab::Swap<Job>(Job &, Job &); // explicit specialization for Job.

#endif /* TEMPLATELAB_HPP_ */
