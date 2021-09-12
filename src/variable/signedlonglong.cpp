#include <canal/variable.h>
#include <canal/debugger.h>

signedlonglong::signedlonglong(Types _type, signed long long c): variable(_type,c){
	debug("constructing signedlonglong");
	size = sizeof(signed long long);
}

variable *signedlonglong::Plus(variable *v){
	debug("> signedlonglong::Plus");
	error_conditional(!v,"v is NULL in signedlonglong::Plus");
	return new signedlonglong(rvalue, value.signedlonglong + v->value.signedlonglong);
}

variable *signedlonglong::Minus(variable *v){
	debug("> signedlonglong::Minus");
	error_conditional(!v,"v is NULL in signedlonglong::Minus");
	return new signedlonglong(rvalue, value.signedlonglong - v->value.signedlonglong);
}

variable *signedlonglong::Times(variable *v){
	debug("> signedlonglong::Times");
	error_conditional(!v,"v is NULL in signedlonglong::Times");
	return new signedlonglong(rvalue, value.signedlonglong * v->value.signedlonglong);
}

variable *signedlonglong::Divide(variable *v){
	debug("> signedlonglong::Divide");
	error_conditional(!v,"v is NULL in signedlonglong::Divide");
	return new signedlonglong(rvalue, value.signedlonglong / v->value.signedlonglong);
}

variable *signedlonglong::And(variable *v){
	debug("> signedlonglong::And");
	error_conditional(!v,"v is NULL in signedlonglong::And");
	return new signedlonglong(rvalue, value.signedlonglong & v->value.signedlonglong);
}

variable *signedlonglong::Or(variable *v){
	debug("> signedlonglong::Or");
	error_conditional(!v,"v is NULL in signedlonglong::Or");
	return new signedlonglong(rvalue, value.signedlonglong | v->value.signedlonglong);
}

variable *signedlonglong::Xor(variable *v){
	debug("> signedlonglong::Xor");
	error_conditional(!v,"v is NULL in signedlonglong::Xor");
	return new signedlonglong(rvalue, value.signedlonglong ^ v->value.signedlonglong);
}

variable *signedlonglong::Inc(){
	debug("> signedlonglong::Inc");
	value.signedlonglong++;
	return this;
}

variable *signedlonglong::Dec(){
	debug("> signedlonglong::Dec");
	value.signedlonglong--;
	return this;
}

variable *signedlonglong::Neg(){
	debug("> signedlonglong::Neg");
	return new signedlonglong(rvalue, ~(value.signedlonglong));
}


bool signedlonglong::operator > (variable *v){
	debug("> signedlonglong::>");
	error_conditional(!v,"v is NULL in signedlonglong::>");
	return value.signedlonglong > v->value.signedlonglong;
}


void signedlonglong::copy_to_pointer(variable *place){
	debug("> signedlonglong::copy_to_pointer");
	error_conditional(!place,"place is NULL in signedlonglong::copy_to_pointer");
	new(place) signedlonglong(variable::rvalue,value.signedlonglong);
}
