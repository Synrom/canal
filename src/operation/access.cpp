#include <string>

#include <canal/debugger.h>
#include <canal/operation.h>

Access::Access(function &f) : operation(operation::Access, f){
	debug("creating Access operation");
}

Access::Access(operation *cpy): operation(operation::Access, cpy->freference){
	debug("creating Access operation cpy");
}

Access::Access(const Access &cpy) : operation(operation::Access, cpy.freference){
	debug("creating Access operation cpy");
}

void Access::executeOperation(variable *left,variable *right,variable *where){
	warning("calling executeOperation on Access Operation, which is not intended");
}

void Access::clone(operation *location) const{
	debug("cloning Access operation to %p",location);
	new (location) Access(freference);
}


void Access::print(){

	printf("*(");

	operation *op = freference.operations.getNext();
	error_conditional(!op, "trying to print Access Operation on nothing");

	op->print();
	printf(");\n");

}

void Access::print_simple(){
	printf("*\n");
}

void Access::execute(){

	debug("executing Access Operation");

	operation *op = freference.operations.getNext();
	error_conditional(!op, "trying to print Access Operation on nothing");

	op->execute();

	if(freference.identifier.look() == result_identifier_stack::local){

		debug("accessing local variable");

		std::vector<variable *> var = freference.locals.pop();

		for(auto var_it = var.begin();var_it != var.end();var_it++){
			if((*var_it)->value.signedlonglong < 0){
				printf("found an overfloawing access\n");
			}

		}
	}else{

		debug("accessing result");

		auto res = freference.results.pop_result();

		for(auto res_it = res.begin();res_it != res.end();res_it++){
			if(res_it->value.signedlonglong < 0){
				printf("found an overfloawing access\n");
			}
		}
	}

}





















