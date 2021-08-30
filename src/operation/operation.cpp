#include <canal/variable.h>
#include <canal/operation.h>

operation::~operation(){
	for(variable *varit : variables){
		if(varit->type == variable::rvalue)
			delete varit;
	}
}

operation::operation(Types _type, operation *l, operation *r){
	left = l;
	right = r;
	type = _type;
	call = NULL;
}

operation::operation(Types _type, variable *l, operation *r){
	variables.push_back(l);
	right = r;
	left = NULL;
	type = _type;
	call = NULL;
}

operation::operation(Types _type, operation *l, variable *r){
	variables.push_back(r);
	right = NULL;
	left = l;
	type = _type;
	call = NULL;
}

operation::operation(Types _type, variable *l, variable *r){
	variables.push_back(l);
	variables.push_back(r);
	right = NULL;
	left = NULL;
	type = _type;
	call = NULL;
}

operation::operation(Types _type, function *f, const std::vector<variable *> &v){
	type = _type;
	call = f;
	left = NULL;
	right = NULL;
	for(variable *varit : v)
		variables.push_back(varit);
}

variable *Add::executeOperation(variable *v1, variable *v2){
	return v1->Plus(v2);
}

variable *Minus::executeOperation(variable *v1, variable *v2){
	return v1->Minus(v2);
}

variable *Divide::executeOperation(variable *v1, variable *v2){
	return v1->Divide(v2);
}

variable *Times::executeOperation(variable *v1, variable *v2){
	return v1->Times(v2);
}

variable *Or::executeOperation(variable *v1, variable *v2){
	return v1->Or(v2);
}

variable *And::executeOperation(variable *v1, variable *v2){
	return v1->And(v2);
}

variable *Xor::executeOperation(variable *v1, variable *v2){
	return v1->Xor(v2);
}

variable *Neg::executeOperation(variable *v1, variable *v2){
	if(!v1)
		return NULL;

	return v1->Neg();
}

variable *Dec::executeOperation(variable *v1, variable *v2){
	if(!v1)
		return NULL;

	return v1->Dec();
}

variable *Inc::executeOperation(variable *v1, variable *v2){
	if(!v1)
		return NULL;

	return v1->Inc();
}

variable *Call::executeOperation(variable *v1, variable *v2){
	return NULL;
}

variable *Equal::executeOperation(variable *v1, variable *v2){
	v1->value.unsignedlonglong = v2->value.unsignedlonglong;
	return NULL;
}

variable *Call::execute(){
	return call->execute(variables);
}

