
#ifndef SCOPE_H
#define SCOPE_H

#include <vector>
#include <iostream>

#include "variable.h"


class scope{
public:
	std::vector<variable *> lvariables;
	scope *parent,*root;

	virtual variable *findVariable(const std::string &);

	virtual ~scope();

};


#endif
