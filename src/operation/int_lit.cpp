#include <new>

#include <canal/variable.h>
#include <canal/debugger.h>
#include <canal/operation.h>
#include <canal/function.h>

IntLiteral::IntLiteral(signed long long v, function &f) : operation(operation::IntLiteral,f) { 
	debug("creating IntLiteral operation");
	literal.signedlonglong = v;
}

IntLiteral::IntLiteral(operation *cpy) : operation(operation::IntLiteral,cpy->freference) { 
	debug("creating IntLiteral operation");
	literal.signedlonglong = cpy->literal.signedlonglong;
}

IntLiteral::IntLiteral(const IntLiteral &cpy) : operation(operation::IntLiteral,cpy.freference) { 
	debug("creating IntLiteral operation clone");
	literal.signedlonglong = cpy.literal.signedlonglong;
}

void IntLiteral::executeOperation(variable *left, variable *right, variable *where){
	warning("calling IntLiteral executeOperation which is really weird");
}

void IntLiteral::clone(operation *location) const {
	debug("cloning IntLiteral operation to %p",location);
	new (location) IntLiteral(literal.signedlonglong,freference);
}

void IntLiteral::execute(){
	debug("executing IntLiteral");

	result &space = freference.results.push_result(freference.current_vstance->container_quantity());

	for(auto i = space.begin(); i != space.end(); i++)
		new (i) signedlonglong("",literal.signedlonglong);

}
