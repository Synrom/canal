#ifndef ROOT_OPERATION_H
#define ROOT_OPERATION_H

#include <vector>

#include "variable.h"
#include "operation.h"

class operation;

class root_operation{
public:
	char *buf;
	char *rbuf;
	operation *end;
	operation *rend;

	/* in terms of elements */
	unsigned int capacity,size;
	unsigned int rcapacity,rsize;

	root_operation();
	~root_operation();

	operation *append();
	operation *rappend();

	operation *begin();
	operation *rbegin();
	operation *new_place();
	operation *new_rplace();
	unsigned int new_capacity();
	unsigned int new_rcapacity();

};

#endif
