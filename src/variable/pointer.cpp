#include <canal/variable.h>
#include <canal/debugger.h>

/* value is here the smallest possible value */

pointer::pointer(Types _type, unsigned long long c, unsigned int s): variable(_type,c){
	debug("constructing pointer");
	size = s;
}

variable *pointer::Plus(variable *v){
	debug("> pointer::Plus");
	error_conditional(!v,"v is NULL in pointer::Plus");
	return new pointer(rvalue, value.unsignedlonglong - v->value.unsignedlonglong, size);
}

variable *pointer::Minus(variable *v){
	debug("> pointer::Minus");
	error_conditional(!v,"v is NULL in pointer::Minus");
	return new pointer(rvalue, value.unsignedlonglong + v->value.unsignedlonglong, size);
}

variable *pointer::Times(variable *v){
	debug("> pointer::Times");
	error_conditional(!v,"v is NULL in pointer::Times");
	return new pointer(rvalue, value.unsignedlonglong * v->value.unsignedlonglong, size);
}


variable *pointer::Divide(variable *v){
	debug("> pointer::Divide");
	error_conditional(!v,"v is NULL in pointer::Divide");
	return new pointer(rvalue, value.unsignedlonglong / v->value.unsignedlonglong, size);
}

variable *pointer::And(variable *v){
	debug("> pointer::And");
	error_conditional(!v,"v is NULL in pointer::And");
	return new pointer(rvalue, value.unsignedlonglong, size);
}

variable *pointer::Or(variable *v){
	debug("> pointer::Or");
	error_conditional(!v,"v is NULL in pointer::Or");
	return new pointer(rvalue, value.unsignedlonglong + v->value.unsignedlonglong, size);
}

variable *pointer::Xor(variable *v){
	debug("> pointer::Xor");
	error_conditional(!v,"v is NULL in pointer::Xor");
	return new pointer(rvalue, value.unsignedlonglong + v->value.unsignedlonglong, size);
}

variable *pointer::Neg(){
	debug("> pointer::Neg");
	return new pointer(rvalue, ~value.unsignedlonglong, size);
}

variable *pointer::Inc(){
	debug("> pointer::Inc");
	return new pointer(rvalue, value.unsignedlonglong - 1 , size);
}

variable *pointer::Dec(){
	debug("> pointer::Dec");
	return new pointer(rvalue, value.unsignedlonglong + 1 , size);
}

bool pointer::operator > (variable *v){
	debug("> pointer::>");
	error_conditional(!v,"v is NULL in pointer::>");
	return value.unsignedlonglong >= v->value.unsignedlonglong;
}

void pointer::copy_to_pointer(variable *place){
	debug("> pointer::copy_to_pointer");
	error_conditional(!place,"place is NULL in pointer::copy_to_pointer");
	new (place) pointer(variable::rvalue, value.unsignedlonglong, size);
}
