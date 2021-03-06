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
		result &max_space = freference.results.push_result(var.size());

		for(auto var_it = var.begin();var_it != var.end();var_it++){
			if((*var_it)->value.signedlonglong < 0){
				printf("found an overfloawing access\n");
			}


		}

		auto max_it = max_space.begin();
		for(auto max_it = max_space.begin();max_it != max_space.end();max_it++){
			switch(var.front()->type){
				case variable::signedchar: 
					signedchar::cloneMax(max_it);
					break;
				case variable::unsignedchar:
					unsignedchar::cloneMax(max_it);
					break;
				case variable::signedshort:
					signedshort::cloneMax(max_it);
					break;
				case variable::signedint:
					signedint::cloneMax(max_it);
					break;
				case variable::signedlong:
					signedlong::cloneMax(max_it);
					break;
				case variable::signedlonglong:
					signedlonglong::cloneMax(max_it);
					break;
				case variable::unsignedshort:
					unsignedshort::cloneMax(max_it);
					break;
				case variable::unsignedint:
					unsignedint::cloneMax(max_it);
					break;
				case variable::unsignedlong:
					unsignedlong::cloneMax(max_it);
					break;
				case variable::unsignedlonglong:
					unsignedlonglong::cloneMax(max_it);
					break;
				case variable::_float:
					_float::cloneMax(max_it);
					break;
				case variable::_double:
					_double::cloneMax(max_it);
					break;
				case variable::longdouble:
					longdouble::cloneMax(max_it);
					break;
				case variable::pointer:
					signedlonglong::cloneMax(max_it);
					break;
			}
		}
	}else{

		debug("accessing result");

		auto res = freference.results.pop_result();
		result &max_space = freference.results.push_result(res.get_size());

		for(auto res_it = res.begin();res_it != res.end();res_it++){
			if(res_it->value.signedlonglong < 0){
				printf("found an overfloawing access\n");
			}
		}
		auto max_it = max_space.begin();
		for(auto max_it = max_space.begin();max_it != max_space.end();max_it++){
			switch(res.begin()->type){
				case variable::signedchar: 
					signedchar::cloneMax(max_it);
					break;
				case variable::unsignedchar:
					unsignedchar::cloneMax(max_it);
					break;
				case variable::signedshort:
					signedshort::cloneMax(max_it);
					break;
				case variable::signedint:
					signedint::cloneMax(max_it);
					break;
				case variable::signedlong:
					signedlong::cloneMax(max_it);
					break;
				case variable::signedlonglong:
					signedlonglong::cloneMax(max_it);
					break;
				case variable::unsignedshort:
					unsignedshort::cloneMax(max_it);
					break;
				case variable::unsignedint:
					unsignedint::cloneMax(max_it);
					break;
				case variable::unsignedlong:
					unsignedlong::cloneMax(max_it);
					break;
				case variable::unsignedlonglong:
					unsignedlonglong::cloneMax(max_it);
					break;
				case variable::_float:
					_float::cloneMax(max_it);
					break;
				case variable::_double:
					_double::cloneMax(max_it);
					break;
				case variable::longdouble:
					longdouble::cloneMax(max_it);
					break;
				case variable::pointer:
					signedlonglong::cloneMax(max_it);
					break;
			}
		}

	}

}





















