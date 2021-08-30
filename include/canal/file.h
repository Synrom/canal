#ifndef FILE_H
#define FILE_H

#include <vector>
#include <string>

#include "scope.h"
#include "function.h"

class function;

class file: public scope{
public:
	std::vector<function *> functions;
	function *findFunction(const std::string &);
	std::string name;

	
};

#endif
