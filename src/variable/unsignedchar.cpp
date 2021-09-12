#include <canal/variable.h>
#include <canal/debugger.h>

unsignedchar::unsignedchar(Types _type, unsigned char c): variable(_type,c){
	debug("constructing an unsignedchar");
	size = sizeof(unsigned char);
}

variable *unsignedchar::Plus(variable *v){
	debug("> unsignedchar::Plus");
	error_conditional(!v,"v is NULL in unsignedchar::Plus");
	return new unsignedchar(rvalue, value.unsignedchar + v->value.unsignedchar);
}

variable *unsignedchar::Minus(variable *v){
	debug("> unsignedchar::Minus");
	error_conditional(!v,"v is NULL in unsignedchar::Minus");
	return new unsignedchar(rvalue, value.unsignedchar - v->value.unsignedchar);
}

variable *unsignedchar::Times(variable *v){
	debug("> unsignedchar::Times");
	error_conditional(!v,"v is NULL in unsignedchar::Times");
	return new unsignedchar(rvalue, value.unsignedchar * v->value.unsignedchar);
}

variable *unsignedchar::Divide(variable *v){
	debug("> unsignedchar::Divide");
	error_conditional(!v,"v is NULL in unsignedchar::Divide");
	return new unsignedchar(rvalue, value.unsignedchar / v->value.unsignedchar);
}

variable *unsignedchar::And(variable *v){
	debug("> unsignedchar::And");
	error_conditional(!v,"v is NULL in unsignedchar::And");
	return new unsignedchar(rvalue, value.unsignedchar & v->value.unsignedchar);
}

variable *unsignedchar::Or(variable *v){
	debug("> unsignedchar::Or");
	error_conditional(!v,"v is NULL in unsignedchar::Or");
	return new unsignedchar(rvalue, value.unsignedchar | v->value.unsignedchar);
}

variable *unsignedchar::Xor(variable *v){
	debug("> unsignedchar::Xor");
	error_conditional(!v,"v is NULL in unsignedchar::Xor");
	return new unsignedchar(rvalue, value.unsignedchar ^ v->value.unsignedchar);
}

variable *unsignedchar::Inc(){
	debug("> unsignedchar::Inc");
	value.unsignedchar++;
	return this;
}

variable *unsignedchar::Dec(){
	debug("> unsignedchar::Dec");
	value.unsignedchar--;
	return this;
}

variable *unsignedchar::Neg(){
	debug("> unsignedchar::Neg");
	return new unsignedchar(rvalue, ~(value.unsignedchar));
}


bool unsignedchar::operator > (variable *v){
	debug("> unsignedchar::>");
	error_conditional(!v,"v is NULL in unsignedchar::>");
	return value.unsignedchar > v->value.unsignedchar;
}


void unsignedchar::copy_to_pointer(variable *place){
	debug("> unsignedchar::copy_to_pointer");
	error_conditional(!place,"place is NULL in unsignedchar::copy_to_pointer");
	new(place) unsignedchar(variable::rvalue,value.unsignedchar);
}
