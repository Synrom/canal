#include <vector>
#include <string>

#include <canal/variable.h>
#include <canal/scope.h>
#include <canal/function.h>
#include <canal/operation.h>
#include <canal/root_operation.h>


variable *scope::findVariable(const std::string &s){

	for(variable *varit : lvariables ){
		if(varit->name == s)
			return varit;
	}

	if(parent != NULL)
		return parent->findVariable(s);

	return NULL;
}

variable *function::findVariable(const std::string &s){

	for(variable *varit : pvariables ){
		if(varit->name == s)
			return varit;
	}

	for(variable *varit : lvariables ){
		if(varit->name == s)
			return varit;
	}

	if(parent != NULL)
		return parent->findVariable(s);

	return NULL;
}

void function::replace(const std::vector<variable *> &params){
	if(params.size() != pvariables.size())
		return; /* throw exception */
	
	for(operation *opit = operations.begin(); opit != operations.end; opit++){

		for(int varit = 0;varit < opit->variables.size(); varit++){

			for(int pit = 0;pit < pvariables.size(); pit++){

				if(opit->variables[varit] == pvariables[pit])
					opit->variables[varit] = params[pit];

			}

		}

	}

	for(operation *opit = operations.rbegin(); opit != operations.rend; opit++){

		for(int varit = 0;varit < opit->variables.size(); varit++){

			for(int pit = 0;pit < pvariables.size(); pit++){

				if(opit->variables[varit] == pvariables[pit])
					opit->variables[varit] = params[pit];

			}

		}

	}

}

void function::replace_back(const std::vector<variable *> &params){
	if(params.size() != pvariables.size())
		return; /* throw exception */
	
	for(operation *opit = operations.begin(); opit != operations.end; opit++){

		for(int varit = 0;varit < opit->variables.size(); varit++){

			for(int pit = 0;pit < params.size(); pit++){

				if(opit->variables[varit] == params[pit])
					opit->variables[varit] = pvariables[pit];

			}

		}

	}

	for(operation *opit = operations.rbegin(); opit != operations.rend; opit++){

		for(int varit = 0;varit < opit->variables.size(); varit++){

			for(int pit = 0;pit < params.size(); pit++){

				if(opit->variables[varit] == params[pit])
					opit->variables[varit] = pvariables[pit];

			}

		}

	}

}

scope::~scope(){
	for(variable *varit : lvariables)
		delete varit;
}

function::~function(){
	for(variable *varit : pvariables)
		delete varit;
}





