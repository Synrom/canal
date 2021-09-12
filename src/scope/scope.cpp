#include <stdlib.h>

#include <vector>
#include <string>

#include <canal/variable.h>
#include <canal/scope.h>
#include <canal/function.h>
#include <canal/operation.h>
#include <canal/root_operation.h>
#include <canal/debugger.h>


variable *scope::findVariable(const std::string &s){
	debug("> scope::findVariable");

	for(variable *varit = lvariables.begin(); varit != lvariables.end;varit++ ){
		if(varit->name == s)
			return varit;
	}

	debug("didnt found variable in scope, searching in parent");
	if(parent != NULL)
		return parent->findVariable(s);

	warning("parent of scope is NULL");
	return NULL;
}

variable *function::findVariable(const std::string &s){
	debug("> function::findVariable");

	for(variable *varit = pvariables.begin(); varit != pvariables.end;varit++ ){
		if(varit->name == s)
			return varit;
	}

	debug("didnt found it in pvariables, searching in lvariables");
	for(variable *varit = lvariables.begin(); varit != lvariables.end;varit++ ){
		if(varit->name == s)
			return varit;
	}

	debug("didnt found it in lvariables, searching in parent");
	if(parent != NULL)
		return parent->findVariable(s);

	warning("parent of function is NULL");
	return NULL;
}

void function::replace(const std::vector<variable *> &params){
	debug("> function::replace");

	if(params.size() != pvariables.size){
		error("params size != pvariables size in function::replace_back");
		return; 
	}
	
	debug("> iterating over root_operations.operations");
	for(operation *opit = operations.begin(); opit != operations.end; opit++){

		for(int varit = 0;varit < opit->variables.size(); varit++){

			for(unsigned int pit = 0;pit < pvariables.size; pit++){

				if(opit->variables[varit] == pvariables.get_pointer(pit))
					opit->variables[varit] = params[pit];


			}

		}

	}

	debug("> iterating over root_operations.roperations");
	for(operation *opit = operations.rbegin(); opit != operations.rend; opit++){

		for(int varit = 0;varit < opit->variables.size(); varit++){

			for(int pit = 0;pit < pvariables.size; pit++){

				if(opit->variables[varit] == pvariables.get_pointer(pit))
					opit->variables[varit] = params[pit];

			}

		}

	}

}

void function::replace_back(const std::vector<variable *> &params){
	debug("> function::replace_back");

	if(params.size() != pvariables.size){
		error("params size != pvariables size in function::replace_back");
		return; 
	}
	
	debug("> iterating over root_operations.operations");
	for(operation *opit = operations.begin(); opit != operations.end; opit++){

		for(int varit = 0;varit < opit->variables.size(); varit++){

			for(int pit = 0;pit < params.size(); pit++){

				if(opit->variables[varit] == params[pit])
					opit->variables[varit] = pvariables.get_pointer(pit);

			}

		}

	}

	debug("> iterating over root_operations.roperations");
	for(operation *opit = operations.rbegin(); opit != operations.rend; opit++){

		for(int varit = 0;varit < opit->variables.size(); varit++){

			for(int pit = 0;pit < params.size(); pit++){

				if(opit->variables[varit] == params[pit])
					opit->variables[varit] = pvariables.get_pointer(pit);

			}

		}

	}

}

variable *function::execute(const std::vector<variable *> &params){
	debug("> function::execute");

	replace(params);

	variable *ret = (variable *)malloc(sizeof(pointer));
	error_conditional(!ret,"malloc returned NULL in function::execute");

	new (ret) pointer(variable::rvalue,0,0);
	
	for(operation *opit = operations.begin();opit != operations.end;opit++){

		variable *result = opit->execute();
		
		if(opit->type == operation::Ret){
			if(result && result > ret){
				ret->~variable();
				result->copy_to_pointer(ret);
			}
		}

		if(result && result->type == variable::rvalue){
			debug_conditional(opit->type != operation::Ret 
				&& opit->type != operation::Equal
				&& opit->type != operation::Dec 
				&& opit->type != operation::Inc
				&& opit->type != operation::Call,
				"operation returned something without beeing one of the reasonable types for returning"
			);
			delete result;
		}

	}

	replace_back(params);

	if(!ret->size){
		ret->~variable();
		free(ret);
		return NULL;
	}
	
	return ret;
}

scope::~scope(){
}

function::~function(){
}





