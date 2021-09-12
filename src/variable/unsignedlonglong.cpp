#include <canal/variable.h>
#include <canal/debugger.h>

unsignedlonglong::unsignedlonglong(Types _type, unsigned long long c): variable(_type,c){
	debug("constructing unsignedlonglong");
	size = sizeof(unsigned long long);
}

variable *unsignedlonglong::Plus(variable *v){
	debug("> unsignedlonglong::Plus");
	error_conditional(!v,"v is NULL in unsignedlonglong::Plus");
	return new unsignedlonglong(rvalue, value.unsignedlonglong + v->value.unsignedlonglong);
}

variable *unsignedlonglong::Minus(variable *v){
	debug("> unsignedlonglong::Minus");
	error_conditional(!v,"v is NULL in unsignedlonglong::Minus");
	return new unsignedlonglong(rvalue, value.unsignedlonglong - v->value.unsignedlonglong);
}

variable *unsignedlonglong::Times(variable *v){
	debug("> unsignedlonglong::Times");
	error_conditional(!v,"v is NULL in unsignedlonglong::Times");
	return new unsignedlonglong(rvalue, value.unsignedlonglong * v->value.unsignedlonglong);
}

variable *unsignedlonglong::Divide(variable *v){
	debug("> unsignedlonglong::Divide");
	error_conditional(!v,"v is NULL in unsignedlonglong::Divide");
	return new unsignedlonglong(rvalue, value.unsignedlonglong / v->value.unsignedlonglong);
}

variable *unsignedlonglong::And(variable *v){
	debug("> unsignedlonglong::And");
	error_conditional(!v,"v is NULL in unsignedlonglong::And");
	return new unsignedlonglong(rvalue, value.unsignedlonglong & v->value.unsignedlonglong);
}

variable *unsignedlonglong::Or(variable *v){
	debug("> unsignedlonglong::Or");
	error_conditional(!v,"v is NULL in unsignedlonglong::Or");
	return new unsignedlonglong(rvalue, value.unsignedlonglong | v->value.unsignedlonglong);
}

variable *unsignedlonglong::Xor(variable *v){
	debug("> unsignedlonglong::Xor");
	error_conditional(!v,"v is NULL in unsignedlonglong::Xor");
	return new unsignedlonglong(rvalue, value.unsignedlonglong ^ v->value.unsignedlonglong);
}

variable *unsignedlonglong::Inc(){
	debug("> unsignedlonglong::Inc");
	value.unsignedlonglong++;
	return this;
}

variable *unsignedlonglong::Dec(){
	debug("> unsignedlonglong::Dec");
	value.unsignedlonglong--;
	return this;
}

variable *unsignedlonglong::Neg(){
	debug("> unsignedlonglong::Neg");
	return new unsignedlonglong(rvalue, ~(value.unsignedlonglong));
}


bool unsignedlonglong::operator > (variable *v){
	debug("> unsignedlonglong::>");
	error_conditional(!v,"v is NULL in unsignedlonglong::>");
	return value.unsignedlonglong > v->value.unsignedlonglong;
}


void unsignedlonglong::copy_to_pointer(variable *place){
	debug("> unsignedlonglong::copy_to_pointer");
	error_conditional(!place,"place is NULL in unsignedlonglong::copy_to_pointer");
	new(place) unsignedlonglong(variable::rvalue,value.unsignedlonglong);
}
