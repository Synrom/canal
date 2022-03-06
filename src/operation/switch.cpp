#include <string>

#include <canal/debugger.h>
#include <canal/operation.h>

Add_Switch::Add_Switch(unsigned int v,function &f): operation(operation::Add_Switch, f){
	literal.unsignedint = v;
	debug("creating Add_Switch(%u)",literal.unsignedint);
}

Add_Switch::Add_Switch(const Add_Switch &cpy) : operation(operation::Add_Switch, cpy.freference){
	literal.unsignedint = cpy.literal.unsignedint;
	debug("creating Add_Switch operation cpy (%u)",literal.unsignedint);
}

Add_Switch::Add_Switch(operation *cpy) : operation(operation::Add_Switch, cpy->freference){
	literal.unsignedint = cpy->literal.unsignedint;
	debug("creating Add_Switch operation cpy (%u)",literal.unsignedint);
}

void Add_Switch::executeOperation(variable *left, variable *right, variable *where){
	warning("calling executeOperation of Add_Switch, which is really weird");
}

void Add_Switch::clone(operation *location) const {
	debug("cloning Add_Switch to %p",location);
	new (location) Add_Switch(literal.unsignedint, freference);
}

void Add_Switch::execute(){
	debug("executing Add_Switch operation");
	freference.add_switches(literal.unsignedint);
}

void Add_Switch::print(){
	printf("switch (%u) {\n",literal.unsignedint);
	operation *op = freference.operations.getNext();
	error_conditional(!op, "trying to print operation stack, which has an unfinished Switch Statement");
	while(op->type != operation::End_Switch){
		if(op->type == operation::Next_Switch){
			op->print();
		}else{
			printf("\t");
			op->print();
		}
		op = freference.operations.getNext();

		error_conditional(!op, "trying to print operation stack, which has an unfinished Switch Statement");
	}
	printf("}\n");
}

void Add_Switch::print_simple(){
	printf("add_switch(%u)\n",literal.unsignedint);
}


Next_Switch::Next_Switch(function &f): operation(operation::Next_Switch, f){
	debug("creating Next_Switch");
}

Next_Switch::Next_Switch(const Next_Switch &cpy) : operation(operation::Next_Switch, cpy.freference){
	debug("creating Next_Switch operation cpy");
}

Next_Switch::Next_Switch(operation *cpy) : operation(operation::Next_Switch, cpy->freference){
	debug("creating Next_Switch operation cpy");
}

void Next_Switch::executeOperation(variable *left, variable *right, variable *where){
	warning("calling executeOperation of Next_Switch, which is really weird");
}

void Next_Switch::clone(operation *location) const {
	debug("cloning Next_Switch to %p",location);
	new (location) Next_Switch(freference);
}

void Next_Switch::execute(){
	debug("executing Next_Switch operation");
	freference.next_switch();
}

void Next_Switch::print(){
	printf("}switch{\n");
}

void Next_Switch::print_simple(){
	printf("next_switch\n");
}

End_Switch::End_Switch(function &f): operation(operation::End_Switch, f){
	debug("creating End_Switch");
}

End_Switch::End_Switch(const End_Switch &cpy) : operation(operation::End_Switch, cpy.freference){
	debug("creating End_Switch operation cpy");
}

End_Switch::End_Switch(operation *cpy) : operation(operation::End_Switch, cpy->freference){
	debug("creating End_Switch operation cpy");
}

void End_Switch::executeOperation(variable *left, variable *right, variable *where){
	warning("calling executeOperation of End_Switch, which is really weird");
}

void End_Switch::clone(operation *location) const {
	debug("cloning End_Switch to %p",location);
	new (location) End_Switch(freference);
}

void End_Switch::execute(){
	debug("executing End_Switch operation");
	freference.end_switch();
}

void End_Switch::print(){
	printf("\n");
}

void End_Switch::print_simple(){
	printf("end_switch\n");
}

