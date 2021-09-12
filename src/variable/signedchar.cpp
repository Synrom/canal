#include <canal/variable.h>
#include <canal/debugger.h>

signedchar::signedchar(Types _type, signed char c) : variable(_type,c){
	debug("constructing a signedchar");
	size = sizeof(signed char);
}

variable *signedchar::Plus(variable *v){
	debug("> signedchar::Plus");
	error_conditional(!v,"v is NULL in signedchar::Plus");
	return new signedchar(rvalue, value.signedchar + v->value.signedchar);
}

variable *signedchar::Minus(variable *v){
	debug("> signedchar::Minus");
	error_conditional(!v,"v is NULL in signedchar::Minus");
	return new signedchar(rvalue, value.signedchar - v->value.signedchar);
}

variable *signedchar::Times(variable *v){
	debug("> signedchar::Times");
	error_conditional(!v,"v is NULL in signedchar::Times");
	return new signedchar(rvalue, value.signedchar * v->value.signedchar);
}

variable *signedchar::Divide(variable *v){
	debug("> signedchar::Divide");
	error_conditional(!v,"v is NULL in signedchar::Divide");
	return new signedchar(rvalue, value.signedchar / v->value.signedchar);
}

variable *signedchar::And(variable *v){
	debug("> signedchar::And");
	error_conditional(!v,"v is NULL in signedchar::And");
	return new signedchar(rvalue, value.signedchar & v->value.signedchar);
}

variable *signedchar::Or(variable *v){
	debug("> signedchar::Or");
	error_conditional(!v,"v is NULL in signedchar::Or");
	return new signedchar(rvalue, value.signedchar | v->value.signedchar);
}

variable *signedchar::Xor(variable *v){
	debug("> signedchar::Xor");
	error_conditional(!v,"v is NULL in signedchar::Xor");
	return new signedchar(rvalue, value.signedchar ^ v->value.signedchar);
}

variable *signedchar::Inc(){
	debug("> signedchar::Inc");
	value.signedchar++;
	return this;
}

variable *signedchar::Dec(){
	debug("> signedchar::Dec");
	value.signedchar--;
	return this;
}

variable *signedchar::Neg(){
	debug("> signedchar::Neg");
	return new signedchar(rvalue, ~(value.signedchar));
}


bool signedchar::operator > (variable *v){
	debug("> signedchar::>");
	error_conditional(!v,"v is NULL in signedchar::>");
	return value.signedchar > v->value.signedchar;
}


void signedchar::copy_to_pointer(variable *place){
	debug("> signedchar::>");
	error_conditional(!place,"place is NULL in signedchar::copy_to_pointer");
	new(place) signedchar(variable::rvalue,value.signedchar);
}
