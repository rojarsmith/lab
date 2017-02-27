/*
 * StructLab.h
 *
 *  Created on: 2017年2月27日
 *      Author: rojar
 */

#ifndef STRUCTLAB_HPP_
#define STRUCTLAB_HPP_

struct inflatable {
	char name[20];
	float volume;
	double price;
};

struct torgle_reg {
	unsigned int SN :4;
	unsigned int :4;
	bool goodIn :1;
	bool goodTorgle :1;
	union {
		long id_name;
		char id_char[20];
	};
};

class StructLab {
public:
	StructLab();
	virtual ~StructLab();
};

#endif /* STRUCTLAB_HPP_ */
