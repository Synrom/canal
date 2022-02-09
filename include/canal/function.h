#ifndef FUNCTION_STORE_H
#define FUNCTION_STORE_H



#include "container.h"
#include "operation_stack.h"
#include "result.h"



#include <string>
#include <vector>



class function{

public:


	operation_stack operations;
	std::vector<std::string> pvariables;
	std::string name;
	result_stack results;
	local_stack locals;
	result_identifier_stack identifier;


	vcontainer_vector vcontainers;
	vstance_vector stances;
	vstance *current_vstance;

	unsigned int original_caller_quantity {0};
	function *caller {0};
	bool hasAlreadyReturnedSomething{false};


	/* noch nicht final */
	variable *execute(std::vector<variable *> & );
	function(const std::string &);
	function(function &&);
	~function();

	void execute();
	void reset();
	
	void print();
	void print_simple();
	void print_vars();


		

};	

#endif
