#include <canal/variable.h>
#include <canal/debugger.h>

unsignedint::unsignedint(Types _type, unsigned int v) : variable(_type,v){
	debug("constructing unsignedint");
	size = sizeof(unsigned int);
}

variable *unsignedint::Plus(variable *v){
	debug("> unsignedint::Plus");
	error_conditional(!v,"v is NULL in unsignedint::Plus");
	return new unsignedint(rvalue, value.unsignedint + v->value.unsignedint);
}

variable *unsignedint::Minus(variable *v){
	debug("> unsignedint::Minus");
	error_conditional(!v,"v is NULL in unsignedint::Minus");
	return new unsignedint(rvalue, value.unsignedint - v->value.unsignedint);
}

variable *unsignedint::Times(variable *v){
	debug("> unsignedint::Times");
	error_conditional(!v,"v is NULL in unsignedint::Times");
	return new unsignedint(rvalue, value.unsignedint * v->value.unsignedint);
}

variable *unsignedint::Divide(variable *v){
	debug("> unsignedint::Divide");
	error_conditional(!v,"v is NULL in unsignedint::Divide");
	return new unsignedint(rvalue, value.unsignedint / v->value.unsignedint);
}

variable *unsignedint::And(variable *v){
	debug("> unsignedint::And");
	error_conditional(!v,"v is NULL in unsignedint::And");
	return new unsignedint(rvalue, value.unsignedint & v->value.unsignedint);
}

variable *unsignedint::Or(variable *v){
	debug("> unsignedint::Or");
	error_conditional(!v,"v is NULL in unsignedint::Or");
	return new unsignedint(rvalue, value.unsignedint | v->value.unsignedint);
}

variable *unsignedint::Xor(variable *v){
	debug("> unsignedint::Xor");
	error_conditional(!v,"v is NULL in unsignedint::Xor");
	return new unsignedint(rvalue, value.unsignedint ^ v->value.unsignedint);
}

variable *unsignedint::Inc(){
	debug("> unsignedint::Inc");
	value.unsignedint++;
	return this;
}

variable *unsignedint::Dec(){
	debug("> unsignedint::Dec");
	value.unsignedint--;
	return this;
}

variable *unsignedint::Neg(){
	debug("> unsignedint::Neg");
	return new unsignedint(rvalue, ~(value.unsignedint));
}


bool unsignedint::operator > (variable *v){
	debug("> unsignedint::>");
	error_conditional(!v,"v is NULL in unsignedint::>");
	return value.unsignedint > v->value.unsignedint;
}


void unsignedint::copy_to_pointer(variable *place){
	debug("> unsignedint::copy_to_pointer");
	error_conditional(!place,"place is NULL in unsignedint::copy_to_pointer");
	new(place) unsignedint(variable::rvalue,value.unsignedint);
}
