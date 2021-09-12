#include <canal/variable.h>
#include <canal/debugger.h>

signedlong::signedlong(Types _type, signed long c): variable(_type,c){
	debug("constructing signedlong");
	size = sizeof(signed long);
}

variable *signedlong::Plus(variable *v){
	debug("> signedlong::Plus");
	error_conditional(!v,"v is NULL in signedlong::Plus");
	return new signedlong(rvalue, value.signedlong + v->value.signedlong);
}

variable *signedlong::Minus(variable *v){
	debug("> signedlong::Minus");
	error_conditional(!v,"v is NULL in signedlong::Minus");
	return new signedlong(rvalue, value.signedlong - v->value.signedlong);
}

variable *signedlong::Times(variable *v){
	debug("> signedlong::Times");
	error_conditional(!v,"v is NULL in signedlong::Times");
	return new signedlong(rvalue, value.signedlong * v->value.signedlong);
}

variable *signedlong::Divide(variable *v){
	debug("> signedlong::Divide");
	error_conditional(!v,"v is NULL in signedlong::Divide");
	return new signedlong(rvalue, value.signedlong / v->value.signedlong);
}

variable *signedlong::And(variable *v){
	debug("> signedlong::And");
	error_conditional(!v,"v is NULL in signedlong::And");
	return new signedlong(rvalue, value.signedlong & v->value.signedlong);
}

variable *signedlong::Or(variable *v){
	debug("> signedlong::Or");
	error_conditional(!v,"v is NULL in signedlong::Or");
	return new signedlong(rvalue, value.signedlong | v->value.signedlong);
}

variable *signedlong::Xor(variable *v){
	debug("> signedlong::Xor");
	error_conditional(!v,"v is NULL in signedlong::Xor");
	return new signedlong(rvalue, value.signedlong ^ v->value.signedlong);
}

variable *signedlong::Inc(){
	debug("> signedlong::Inc");
	value.signedlong++;
	return this;
}

variable *signedlong::Dec(){
	debug("> signedlong::Dec");
	value.signedlong--;
	return this;
}

variable *signedlong::Neg(){
	debug("> signedlong::Neg");
	return new signedlong(rvalue, ~(value.signedlong));
}


bool signedlong::operator > (variable *v){
	debug("> signedlong::>");
	error_conditional(!v,"v is NULL in signedlong::>");
	return value.signedlong > v->value.signedlong;
}


void signedlong::copy_to_pointer(variable *place){
	debug("> signedlong::copy_to_pointer");
	error_conditional(!place,"place is NULL in signedlong::copy_to_pointer");
	new(place) signedlong(variable::rvalue,value.signedlong);
}
