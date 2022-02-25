#include <new>
#include <string>
#include <vector>

#include <canal/variable.h>
#include <canal/debugger.h>
#include <canal/operation.h>
#include <canal/function.h>

VarPush::VarPush(const std::string &name, function &f) : operation(operation::VarPush,f) { 
	debug("creating IntLiteral operation");
	var_name = name;
}

VarPush::VarPush(operation *cpy) : operation(operation::VarPush,cpy->freference) { 
	debug("creating IntLiteral operation");
	var_name = cpy->var_name;
}

VarPush::VarPush(const VarPush &cpy) : operation(operation::VarPush,cpy.freference) { 
	debug("creating IntLiteral operation clone");
	var_name = cpy.var_name;
}

void VarPush::executeOperation(variable *left, variable *right, variable *where){
	warning("calling VarPush executeOperation which is really weird");
}

void VarPush::clone(operation *location) const {
	debug("cloning VarPush operation to %p",location);
	new (location) VarPush(var_name,freference);
}

void VarPush::execute(){
	debug("executing VarPush");

	std::vector<variable *> var_vector = freference.current_vstance->get_var(var_name);

	error_conditional(var_vector.size() != freference.current_vstance->container_quantity(),
			"result of get_var(%s) in VarPush execute is %ld while container_quantity is %d",
			var_name.c_str(), var_vector.size(), freference.current_vstance->container_quantity()
			);

	freference.locals.push(var_vector);

}
