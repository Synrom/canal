#include <string>

#include <canal/debugger.h>
#include <canal/operation.h>


Inc_Post::Inc_Post(function &f): operation(operation::Inc_Post, f){
	debug("creating Inc Post operation");
}

Inc_Post::Inc_Post(const Inc_Post &cpy) : operation(operation::Inc_Post, cpy.freference){
	debug("creating Inc Post operation cpy");
}

Inc_Post::Inc_Post(operation *cpy): operation(operation::Inc_Post, cpy->freference){
	debug("creating Inc Post operation cpy");
}

void Inc_Post::executeOperation(variable *left, variable *right, variable *where){
	info("calling executeOperation on Inc_Post which is really weird");
}

void Inc_Post::clone(operation *location) const {
	debug("cloning Inc_Post operation to %p",location);
	new (location) Inc_Post(freference);
}

void Inc_Post::print(){

	operation *op = freference.operations.getNext();
	error_conditional(!op || op->type != operation::VarPush, "trying to print Inc_Post of now variable");

	op->print();
	printf("++");
}

void Inc_Post::print_simple(){
	printf("Inc Post\n");
}

Dec_Post::Dec_Post(function &f): operation(operation::Dec_Post, f){
	debug("creating Dec Post operation");
}

Dec_Post::Dec_Post(const Dec_Post &cpy) : operation(operation::Dec_Post, cpy.freference){
	debug("creating Dec Post operation cpy");
}

Dec_Post::Dec_Post(operation *cpy): operation(operation::Dec_Post, cpy->freference){
	debug("creating Dec Post operation cpy");
}

void Dec_Post::executeOperation(variable *left, variable *right, variable *where){
	info("calling executeOperation on Dec_Post which is really weird");
}

void Dec_Post::clone(operation *location) const {
	debug("cloning Dec_Post operation to %p",location);
	new (location) Dec_Post(freference);
}

void Dec_Post::print(){

	operation *op = freference.operations.getNext();
	error_conditional(!op || op->type != operation::VarPush, "trying to print Dec_Post of now variable");

	op->print();
	printf("--");
}

void Dec_Post::print_simple(){
	printf("Dec Post\n");
}

Inc_Pre::Inc_Pre(function &f): operation(operation::Inc_Pre, f){
	debug("creating Inc Pre operation");
}

Inc_Pre::Inc_Pre(const Inc_Pre &cpy) : operation(operation::Inc_Pre, cpy.freference){
	debug("creating Inc Pre operation cpy");
}

Inc_Pre::Inc_Pre(operation *cpy): operation(operation::Inc_Pre, cpy->freference){
	debug("creating Inc Pre operation cpy");
}

void Inc_Pre::executeOperation(variable *left, variable *right, variable *where){
	info("calling executeOperation on Inc_Pre which is really weird");
}

void Inc_Pre::clone(operation *location) const {
	debug("cloning Inc_Pre operation to %p",location);
	new (location) Inc_Pre(freference);
}

void Inc_Pre::print(){

	operation *op = freference.operations.getNext();
	error_conditional(!op || op->type != operation::VarPush, "trying to print Inc_Pre of now variable");

	printf("++");
	op->print();
}

void Inc_Pre::print_simple(){
	printf("Inc Pre\n");
}

Dec_Pre::Dec_Pre(function &f): operation(operation::Dec_Pre, f){
	debug("creating Dec Pre operation");
}

Dec_Pre::Dec_Pre(const Dec_Pre &cpy) : operation(operation::Dec_Pre, cpy.freference){
	debug("creating Dec Pre operation cpy");
}

Dec_Pre::Dec_Pre(operation *cpy): operation(operation::Dec_Pre, cpy->freference){
	debug("creating Dec Pre operation cpy");
}

void Dec_Pre::executeOperation(variable *left, variable *right, variable *where){
	info("calling executeOperation on Dec_Pre which is really weird");
}

void Dec_Pre::clone(operation *location) const {
	debug("cloning Dec_Pre operation to %p",location);
	new (location) Dec_Pre(freference);
}

void Dec_Pre::print(){

	operation *op = freference.operations.getNext();
	error_conditional(!op || op->type != operation::VarPush, "trying to print Dec_Pre of now variable");

	printf("--");
	op->print();
}

void Dec_Pre::print_simple(){
	printf("Dec Pre\n");
}

void Neg::print(){

	operation *op = freference.operations.getNext();
	error_conditional(!op, "trying to print Neg of nothing");

	printf("~(");
	op->print();
	printf(")");
}

void Neg::print_simple(){
	printf("~\n");
}

void Inc_Pre::execute(){
	debug("executing Inc_pre");

	operation *op = freference.operations.getNext();
	error_conditional(!op || op->type != operation::VarPush, "trying to execute Inc_Pre of no variable");

	op->execute();
	error_conditional(freference.identifier.look() != result_identifier_stack::local, "trying to execute Inc_Pre after no variable");

	std::vector<variable *> var = freference.locals.pop();
	debug("executing Inc_Pre of variable %s",var.front()->name.c_str());
	
	for(auto i = var.begin(); i != var.end();i++)
		(*i)->Inc(NULL);
	
	freference.locals.push(var);
}

void Inc_Post::execute(){
	debug("executing Inc_Post");

	operation *op = freference.operations.getNext();
	error_conditional(!op || op->type != operation::VarPush, "trying to execute Inc_Post of no variable");

	op->execute();
	error_conditional(freference.identifier.look() != result_identifier_stack::local, "trying to execute Inc_Post after no variable");

	std::vector<variable *> var = freference.locals.pop();
	debug("executing Inc_Post of variable %s",var.front()->name.c_str());

	result &space = freference.results.push_result(var.size());

	auto space_iterator = space.begin();
	auto var_iterator = var.begin();

	while(var_iterator != var.end()){

		(*var_iterator)->clone(space_iterator);
		(*var_iterator)->Inc(NULL);

		var_iterator++;
		space_iterator++;
	}

}


void Dec_Pre::execute(){
	debug("executing Dec_pre");

	operation *op = freference.operations.getNext();
	error_conditional(!op || op->type != operation::VarPush, "trying to execute Dec_Pre of no variable");

	op->execute();
	error_conditional(freference.identifier.look() != result_identifier_stack::local, "trying to execute Dec_Pre after no variable");

	std::vector<variable *> var = freference.locals.pop();
	debug("executing Dec_Pre of variable %s",var.front()->name.c_str());
	
	for(auto i = var.begin(); i != var.end();i++)
		(*i)->Dec(NULL);
	
	freference.locals.push(var);
}

void Dec_Post::execute(){
	debug("executing Dec_Post");

	operation *op = freference.operations.getNext();
	error_conditional(!op || op->type != operation::VarPush, "trying to execute Dec_Post of no variable");

	op->execute();
	error_conditional(freference.identifier.look() != result_identifier_stack::local, "trying to execute Dec_Post after no variable");

	std::vector<variable *> var = freference.locals.pop();
	debug("executing Dec_Post of variable %s",var.front()->name.c_str());

	result &space = freference.results.push_result(var.size());

	auto space_iterator = space.begin();
	auto var_iterator = var.begin();

	while(var_iterator != var.end()){

		(*var_iterator)->clone(space_iterator);
		(*var_iterator)->Dec(NULL);

		var_iterator++;
		space_iterator++;
	}

}

void Neg::execute(){
	debug("executing Neg");

	operation *op = freference.operations.getNext();
	error_conditional(!op, "trying to execute Dec_Post of no variable");

	op->execute();

	if(freference.identifier.look() == result_identifier_stack::local){
		debug("Neg operation of variable");
		
		std::vector<variable *> var = freference.locals.pop();
		result &space = freference.results.push_result(var.size());

		auto var_iterator = var.begin();
		auto space_iterator = space.begin();
		
		while(var_iterator != var.end()){

			(*var_iterator)->Neg(space_iterator);

			var_iterator++;
			space_iterator++;
		}


	}else{
		debug("Neg operation of result");

		result &space = freference.results.get_result(0);

		auto space_iterator = space.begin();

		while(space_iterator != space.end()){

			space_iterator->Neg(NULL);

			space_iterator++;
		}



	}

}






