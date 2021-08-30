#ifndef CONTAINER_H
#define CONTAINER_H

#include "variable.h"

class vcontainer{
public:
	char *buf;
	variable *end;
	unsigned int capacity,size;

	vcontainer();
	~vcontainer();

	variable *begin();
	unsigned int new_capacity();
	variable *new_last();
	void emplace_back(variable::Types ,double );
	void emplace_back(variable::Types ,float );
	void emplace_back(variable::Types ,long double );
	void emplace_back(variable::Types ,unsigned long long ,unsigned int );
	void emplace_back(variable::Types ,signed char );
	void emplace_back(variable::Types ,signed int );
	void emplace_back(variable::Types ,signed long );
	void emplace_back(variable::Types ,signed long long );
	void emplace_back(variable::Types ,signed short );
	void emplace_back(variable::Types ,unsigned char );
	void emplace_back(variable::Types ,unsigned int );
	void emplace_back(variable::Types ,unsigned long );
	void emplace_back(variable::Types ,unsigned long long );
	void emplace_back(variable::Types ,unsigned short );

};

#endif
