#ifndef FUNCTION_H
#define FUNCTION_H


#include <vector>
#include <iostream>
#include <string>

#include "scope.h"
#include "operation.h"
#include "root_operation.h"
#include "file.h"

class operation;
class file;

class function: public scope{
public:
	std::vector<variable *> pvariables;
	std::string name;
	file *_file;


	root_operation operations;

	~function();
	variable *findVariable(const std::string &);

	variable *execute(const std::vector<variable *> &);

	/* replaces pvariables nur in operations with parameters */
	/*  -> pvariables bleiben gleich nur in operations */
	void replace(const std::vector<variable *> &);
	void replace_back(const std::vector<variable *> &);

	

};

#endif
