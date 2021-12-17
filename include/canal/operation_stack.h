#ifndef ROOT_OPERATION_H
#define ROOT_OPERATION_H

#include "operation.h"

class function;
class operation;

class operation_stack{
public:
	operation &getNext();

	operation_stack();
	operation_stack(operation_stack &&);
	operation_stack& operator=(operation_stack &&);
	
	~operation_stack();

private:
	operation *start_buf, *end_buf;
	operation *iterator;


};

#endif
