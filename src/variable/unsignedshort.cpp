#include <canal/variable.h>
#include <canal/debugger.h>

unsignedshort::unsignedshort(Types _type, unsigned short c): variable(_type,c){
	debug("constructing unsignedshort");
	size = sizeof(unsigned short);
}

variable *unsignedshort::Plus(variable *v){
	debug("> unsignedshort::Plus");
	error_conditional(!v,"v is NULL in unsignedshort::Plus");
	return new unsignedshort(rvalue, value.unsignedshort + v->value.unsignedshort);
}

variable *unsignedshort::Minus(variable *v){
	debug("> unsignedshort::Minus");
	error_conditional(!v,"v is NULL in unsignedshort::Minus");
	return new unsignedshort(rvalue, value.unsignedshort - v->value.unsignedshort);
}

variable *unsignedshort::Times(variable *v){
	debug("> unsignedshort::Times");
	error_conditional(!v,"v is NULL in unsignedshort::Times");
	return new unsignedshort(rvalue, value.unsignedshort * v->value.unsignedshort);
}

variable *unsignedshort::Divide(variable *v){
	debug("> unsignedshort::Divide");
	error_conditional(!v,"v is NULL in unsignedshort::Divide");
	return new unsignedshort(rvalue, value.unsignedshort / v->value.unsignedshort);
}

variable *unsignedshort::And(variable *v){
	debug("> unsignedshort::And");
	error_conditional(!v,"v is NULL in unsignedshort::And");
	return new unsignedshort(rvalue, value.unsignedshort & v->value.unsignedshort);
}

variable *unsignedshort::Or(variable *v){ debug("> unsignedshort::Or");
	error_conditional(!v,"v is NULL in unsignedshort::Or");
	return new unsignedshort(rvalue, value.unsignedshort | v->value.unsignedshort);
}

variable *unsignedshort::Xor(variable *v){
	debug("> unsignedshort::Xor");
	error_conditional(!v,"v is NULL in unsignedshort::Xor");
	return new unsignedshort(rvalue, value.unsignedshort ^ v->value.unsignedshort);
}

variable *unsignedshort::Inc(){
	debug("> unsignedshort::Inc");
	value.unsignedshort++;
	return this;
}

variable *unsignedshort::Dec(){
	debug("> unsignedshort::Dec");
	value.unsignedshort--;
	return this;
}

variable *unsignedshort::Neg(){
	debug("> unsignedshort::Neg");
	return new unsignedshort(rvalue, ~(value.unsignedshort));
}


bool unsignedshort::operator > (variable *v){
	debug("> unsignedshort::>");
	error_conditional(!v,"v is NULL in unsignedshort::>");
	return value.unsignedshort > v->value.unsignedshort;
}


void unsignedshort::copy_to_pointer(variable *place){
	debug("> unsignedshort::copy_to_pointer");
	error_conditional(!place,"place is NULL in unsignedshort::copy_to_pointer");
	new(place) unsignedshort(variable::rvalue,value.unsignedshort);
}
