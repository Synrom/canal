#ifndef FUNCTION_STORE_H
#define FUNCTION_STORE_H



#include "container.h"
#include "operation_stack.h"


#include <string>
#include <vector>

class vcontainer_vector;
class vstance_vector;
class vstance;

class function{

public:


	operation_stack operations;
	std::vector<std::string> pvariables;
	std::string name;

	vcontainer_vector vcontainers;
	vstance_vector stances;
	vstance *current_vstance;



	/* noch nicht final */
	variable *execute(std::vector<variable *> & );
	function(const std::string &);
	function(function &&);
	~function();

		

};	

#endif
