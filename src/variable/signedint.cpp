#include <canal/variable.h>
#include <canal/debugger.h>

signedint::signedint(Types _type, signed int v) : variable(_type,v){
	debug("constructing signedint");
	size = sizeof(signed int);
}

variable *signedint::Plus(variable *v){
	debug("> signedint::Plus");
	error_conditional(!v,"v is NULL in signedint::Plus");
	return new signedint(rvalue, value.signedint + v->value.signedint);
}

variable *signedint::Minus(variable *v){
	debug("> signedint::Minus");
	error_conditional(!v,"v is NULL in signedint::Minus");
	return new signedint(rvalue, value.signedint - v->value.signedint);
}

variable *signedint::Times(variable *v){
	debug("> signedint::Times");
	error_conditional(!v,"v is NULL in signedint::Times");
	return new signedint(rvalue, value.signedint * v->value.signedint);
}

variable *signedint::Divide(variable *v){
	debug("> signedint::Divide");
	error_conditional(!v,"v is NULL in signedint::Divide");
	return new signedint(rvalue, value.signedint / v->value.signedint);
}

variable *signedint::And(variable *v){
	debug("> signedint::And");
	error_conditional(!v,"v is NULL in signedint::And");
	return new signedint(rvalue, value.signedint & v->value.signedint);
}

variable *signedint::Or(variable *v){
	debug("> signedint::Or");
	error_conditional(!v,"v is NULL in signedint::Or");
	return new signedint(rvalue, value.signedint | v->value.signedint);
}

variable *signedint::Xor(variable *v){
	debug("> signedint::Xor");
	error_conditional(!v,"v is NULL in signedint::Xor");
	return new signedint(rvalue, value.signedint ^ v->value.signedint);
}

variable *signedint::Inc(){
	debug("> signedint::Inc");
	value.signedint++;
	return this;
}

variable *signedint::Dec(){
	debug("> signedint::Dec");
	value.signedint--;
	return this;
}

variable *signedint::Neg(){
	debug("> signedint::Neg");
	return new signedint(rvalue, ~(value.signedint));
}


bool signedint::operator > (variable *v){
	debug("> signedint::>");
	error_conditional(!v,"v is NULL in signedint::>");
	return value.signedint > v->value.signedint;
}


void signedint::copy_to_pointer(variable *place){
	debug("> signedint::copy_to_pointer");
	error_conditional(!place,"place is NULL in signedint::copy_to_pointer");
	new(place) signedint(variable::rvalue,value.signedint);
}
