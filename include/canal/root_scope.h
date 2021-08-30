
#ifndef ROOT_SCOPE_H
#define ROOT_SCOPE_H

#include <vector>
#include <string>

#include "scope.h"
#include "function.h"

class root_scope: public scope{
public:
	std::vector<function> functions;
	std::vector<file> files;

	~root_scope();
	function *findFunction(const std::string &);
};

#endif
