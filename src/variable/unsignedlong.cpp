#include <canal/variable.h>
#include <canal/debugger.h>

unsignedlong::unsignedlong(Types _type, unsigned long c): variable(_type,c){
	debug("constructing unsignedlong");
	size = sizeof(unsigned long);
}

variable *unsignedlong::Plus(variable *v){
	debug("> unsignedlong::Plus");
	error_conditional(!v,"v is NULL in unsignedlong::Plus");
	return new unsignedlong(rvalue, value.unsignedlong + v->value.unsignedlong);
}

variable *unsignedlong::Minus(variable *v){
	debug("> unsignedlong::Minus");
	error_conditional(!v,"v is NULL in unsignedlong::Minus");
	return new unsignedlong(rvalue, value.unsignedlong - v->value.unsignedlong);
}

variable *unsignedlong::Times(variable *v){
	debug("> unsignedlong::Times");
	error_conditional(!v,"v is NULL in unsignedlong::Times");
	return new unsignedlong(rvalue, value.unsignedlong * v->value.unsignedlong);
}

variable *unsignedlong::Divide(variable *v){
	debug("> unsignedlong::Divide");
	error_conditional(!v,"v is NULL in unsignedlong::Divide");
	return new unsignedlong(rvalue, value.unsignedlong / v->value.unsignedlong);
}

variable *unsignedlong::And(variable *v){
	debug("> unsignedlong::And");
	error_conditional(!v,"v is NULL in unsignedlong::And");
	return new unsignedlong(rvalue, value.unsignedlong & v->value.unsignedlong);
}

variable *unsignedlong::Or(variable *v){
	debug("> unsignedlong::Or");
	error_conditional(!v,"v is NULL in unsignedlong::Or");
	return new unsignedlong(rvalue, value.unsignedlong | v->value.unsignedlong);
}

variable *unsignedlong::Xor(variable *v){
	debug("> unsignedlong::Xor");
	error_conditional(!v,"v is NULL in unsignedlong::Xor");
	return new unsignedlong(rvalue, value.unsignedlong ^ v->value.unsignedlong);
}

variable *unsignedlong::Inc(){
	debug("> unsignedlong::Inc");
	value.unsignedlong++;
	return this;
}

variable *unsignedlong::Dec(){
	debug("> unsignedlong::Dec");
	value.unsignedlong--;
	return this;
}

variable *unsignedlong::Neg(){
	debug("> unsignedlong::Neg");
	return new unsignedlong(rvalue, ~(value.unsignedlong));
}


bool unsignedlong::operator > (variable *v){
	debug("> unsignedlong::>");
	error_conditional(!v,"v is NULL in unsignedlong::>");
	return value.unsignedlong > v->value.unsignedlong;
}


void unsignedlong::copy_to_pointer(variable *place){
	debug("> unsignedlong::copy_to_pointer");
	error_conditional(!place,"place is NULL in unsignedlong::copy_to_pointer");
	new(place) unsignedlong(variable::rvalue,value.unsignedlong);
}
