#include <canal/variable.h>
#include <canal/debugger.h>

signedshort::signedshort(Types _type, signed short c): variable(_type,c){
	debug("constructing a signedshort");
	size = sizeof(signed short);
}

variable *signedshort::Plus(variable *v){
	debug("> signedshort::Plus");
	error_conditional(!v,"v is NULL in signedshort::Plus");
	return new signedshort(rvalue, value.signedshort + v->value.signedshort);
}

variable *signedshort::Minus(variable *v){
	debug("> signedshort::Minus");
	error_conditional(!v,"v is NULL in signedshort::Minus");
	return new signedshort(rvalue, value.signedshort - v->value.signedshort);
}

variable *signedshort::Times(variable *v){
	debug("> signedshort::Times");
	error_conditional(!v,"v is NULL in signedshort::Times");
	return new signedshort(rvalue, value.signedshort * v->value.signedshort);
}

variable *signedshort::Divide(variable *v){
	debug("> signedshort::Divide");
	error_conditional(!v,"v is NULL in signedshort::Divide");
	return new signedshort(rvalue, value.signedshort / v->value.signedshort);
}

variable *signedshort::And(variable *v){
	debug("> signedshort::And");
	error_conditional(!v,"v is NULL in signedshort::And");
	return new signedshort(rvalue, value.signedshort & v->value.signedshort);
}

variable *signedshort::Or(variable *v){
	debug("> signedshort::Or");
	error_conditional(!v,"v is NULL in signedshort::Or");
	return new signedshort(rvalue, value.signedshort | v->value.signedshort);
}

variable *signedshort::Xor(variable *v){
	debug("> signedshort::Xor");
	error_conditional(!v,"v is NULL in signedshort::Xor");
	return new signedshort(rvalue, value.signedshort ^ v->value.signedshort);
}

variable *signedshort::Inc(){
	debug("> signedshort::Inc");
	value.signedshort++;
	return this;
}

variable *signedshort::Dec(){
	debug("> signedshort::Dec");
	value.signedshort--;
	return this;
}

variable *signedshort::Neg(){
	debug("> signedshort::Neg");
	return new signedshort(rvalue, ~(value.signedshort));
}


bool signedshort::operator > (variable *v){
	debug("> signedshort::>");
	error_conditional(!v,"v is NULL in signedshort::>");
	return value.signedshort > v->value.signedshort;
}


void signedshort::copy_to_pointer(variable *place){
	debug("> signedshort::copy_to_pointer");
	error_conditional(!place,"place is NULL in signedshort::copy_to_pointer");
	new(place) signedshort(variable::rvalue,value.signedshort);
}
