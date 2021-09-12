#include <canal/variable.h>
#include <canal/operation.h>
#include <canal/debugger.h>

operation::~operation(){
	debug("deconstructing operation");
	for(variable *varit : variables){
		if(varit->type == variable::rvalue)
			delete varit;
	}
}

operation::operation(Types _type, operation *l, operation *r){
	debug("constructing operation");
	left = l;
	right = r;
	type = _type;
	call = NULL;
}
operation::operation(Types _type, variable *l, operation *r){
	debug("constructing operation");
	variables.push_back(l);
	right = r;
	left = NULL;
	type = _type;
	call = NULL;
}

operation::operation(Types _type, operation *l, variable *r){
	debug("constructing operation");
	variables.push_back(r);
	right = NULL;
	left = l;
	type = _type;
	call = NULL;
}

operation::operation(Types _type, variable *l, variable *r){
	debug("constructing operation");
	variables.push_back(l);
	variables.push_back(r);
	right = NULL;
	left = NULL;
	type = _type;
	call = NULL;
}

operation::operation(Types _type, function *f, const std::vector<variable *> &v){
	debug("constructing operation");
	type = _type;
	call = f;
	left = NULL;
	right = NULL;
	for(variable *varit : v)
		variables.push_back(varit);
}

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
	if(left)
		return left->execute();
	if(variables.size() > 0)
		return variables[0];
	return NULL;
}

variable *Call::execute(){
	debug("> Call::execute");
	return call->execute(variables);
}

variable *operation::execute(){
	debug("> operation::execute");
	if(left){
		variable *leftv = left->execute();
		if(right){
			variable *rightv = right->execute();
			variable *result = executeOperation(leftv,rightv);
			if(leftv->type == variable::rvalue)
				delete leftv;
			if(rightv->type == variable::rvalue)
				delete rightv;
			return result;
		}
		if(variables.size() >= 1){
			variable *rightv = variables[0];
			variable *result = executeOperation(leftv,rightv);
			if(leftv->type == variable::rvalue)
				delete leftv;
			return result;
		}
		
		debug("executeOperation von (leftv,NULL)")
		variable *result = executeOperation(leftv,NULL);
		if(leftv->type == variable::rvalue)
			delete leftv;
		return result;

	}else if(right){
		variable *rightv = right->execute();
		if(variables.size() >= 1){
			variable *result = executeOperation(variables[0],rightv);
			if(rightv->type == variable::rvalue)
				delete rightv;
			return result;
		}

		debug("> executeOperation(rightv,NULL)")
		variable *result = executeOperation(rightv,NULL);
		if(rightv->type == variable::rvalue)
			delete rightv;
		return result;
	}

	if(variables.size() < 2){
		if(variables.size() < 1){
			return NULL;
		}
		debug("> executeOperation(variables[0],NULL)");
		return executeOperation(variables[0],NULL);
	}
	
	return executeOperation(variables[0],variables[1]);
}

/* nur fuer Tests */
Add::Add(operation *o1, operation *o2) : operation(operation::Add, o1, o2){
}
