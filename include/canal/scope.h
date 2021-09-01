
#ifndef SCOPE_H
#define SCOPE_H

#include <vector>
#include <iostream>

#include "variable.h"
#include "container.h"


class scope{
public:
	vcontainer lvariables;
	scope *parent,*root;

	virtual variable *findVariable(const std::string &);

	virtual ~scope();

};


#endif
