#ifndef ROOT_OPERATION_H
#define ROOT_OPERATION_H

#include <vector>


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

	/* TODO wenn ich weiss wie sie benutzt werden */
	operation *append(unsigned int);
	operation *rappend(unsigned int);

	operation *begin();
	operation *rbegin();
	operation *new_last();
	operation *new_rlast();
	unsigned int new_capacity();
	unsigned int new_rcapacity();

};

#endif
