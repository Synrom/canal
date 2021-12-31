#include <canal/variable.h>
#include <canal/operation.h>
#include <canal/debugger.h>
#include <string>

operation::~operation(){
	debug("deconstructing operation");
}

operation::operation(Types _type,const std::string &l,const std::string &r,function &func): freference(func) {
	debug("constructing operation");
	left = l;
	right = r;
	type = _type;
	call = NULL;
}



operation::operation(Types _type, function *f, const std::vector<std::string> &v, function &func): call(f) , freference(func), variables(v) {
	debug("constructing operation");
	type = _type;
}

/*
variable *Add::executeOperation(variable *v1, variable *v2){
	debug("> Add::executeOperation");
	return v1->Plus(v2);
}

variable *Minus::executeOperation(variable *v1, variable *v2){
	debug("> Minus::executeOperation");
	return v1->Minus(v2);
}

variable *Divide::executeOperation(variable *v1, variable *v2){
	debug("> Divide::executeOperation");
	return v1->Divide(v2);
}

variable *Times::executeOperation(variable *v1, variable *v2){
	debug("> Times::executeOperation");
	return v1->Times(v2);
}

variable *Or::executeOperation(variable *v1, variable *v2){
	debug("> Or::executeOperation");
	return v1->Or(v2);
}

variable *And::executeOperation(variable *v1, variable *v2){
	debug("> And::executeOperation");
	return v1->And(v2);
}

variable *Xor::executeOperation(variable *v1, variable *v2){
	debug("> Xor::executeOperation");
	return v1->Xor(v2);
}

variable *Neg::executeOperation(variable *v1, variable *v2){
	debug("> Neg::executeOperation");
	if(!v1)
		return NULL;

	return v1->Neg();
}

variable *Dec::executeOperation(variable *v1, variable *v2){
	debug("> Dec::executeOperation");
	if(!v1)
		return NULL;

	return v1->Dec();
}

variable *Inc::executeOperation(variable *v1, variable *v2){
	debug("> Inc::executeOperation");
	if(!v1)
		return NULL;

	return v1->Inc();
}

variable *Call::executeOperation(variable *v1, variable *v2){
	warning("> Call::executeOperation usually shouldnt get called");
	return NULL;
}

variable *Equal::executeOperation(variable *v1, variable *v2){
	debug("> Equal::executeOperation");
	v1->value.unsignedlonglong = v2->value.unsignedlonglong;
	return v1;
}

variable *Ret::executeOperation(variable *v1,variable *v2){
	warning("> Ret::executeOperation usually shouldnt get called");
	return NULL;
}

variable *Ret::execute(){
	debug("> Ret::execute");
	return NULL;
}

*/


