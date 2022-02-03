#include <string>

#include <canal/debugger.h>
#include <canal/operation.h>

Shl::Shl(function &f) : operation(operation::Shl,f) { 
	debug("creating Shl operation");
}

Shl::Shl(const Shl &cpy) : operation(operation::Shl,cpy.freference) { 
	debug("creating Shl operation copy");
}

Shl::Shl(operation *cpy) : operation(operation::Shl,cpy->freference) { 
	debug("creating Shl operation copy");
}

void Shl::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Shl operation");
	left->Shl(where, right);
}

void Shl::clone(operation *location){
	debug("cloning Shl operation to %p",location);
	new (location) Shl(freference);
}

Shr::Shr(function &f) : operation(operation::Shr,f) { 
	debug("creating Shr operation");
}

Shr::Shr(const Shr &cpy) : operation(operation::Shr,cpy.freference) { 
	debug("creating Shr operation copy");
}

Shr::Shr(operation *cpy) : operation(operation::Shr,cpy->freference) { 
	debug("creating Shr operation copy");
}

void Shr::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Shr operation");
	left->Shr(where, right);
}

void Shr::clone(operation *location){
	debug("cloning Shr operation to %p",location);
	new (location) Shr(freference);
}
