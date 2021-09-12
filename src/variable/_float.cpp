#include <canal/variable.h>
#include <canal/debugger.h>

_float::_float(Types _type, float c): variable(_type,c){
	debug("creating a _float");
	size = sizeof(float);
}

_float::_float(Types _type, unsigned int c): variable(_type,c){
	debug("creating a _float");
	size = sizeof(float);
}

variable *_float::Plus(variable *v){
	debug("> _float::Plus");
	error_conditional(!v,"v is NULL in _float::Plus");
	return new _float(rvalue, value._float + v->value._float);
}

variable *_float::Minus(variable *v){
	debug("> _float::Minus");
	error_conditional(!v,"v is NULL in _float::Minus");
	return new _float(rvalue, value._float - v->value._float);
}

variable *_float::Times(variable *v){
	debug("> _float::Times");
	error_conditional(!v,"v is NULL in _float::Times");
	return new _float(rvalue, value._float * v->value._float);
}

variable *_float::Divide(variable *v){
	debug("> _float::Divide");
	error_conditional(!v,"v is NULL in _float::Divide");
	return new _float(rvalue, value._float / v->value._float);
}

variable *_float::And(variable *v){
	debug("> _float::And");
	error_conditional(!v,"v is NULL in _float::And");
	return new _float(rvalue, value.unsignedint & v->value.unsignedint);
}

variable *_float::Or(variable *v){
	debug("> _float::Or");
	error_conditional(!v,"v is NULL in _float::Or");
	return new _float(rvalue, value.unsignedint | v->value.unsignedint);
}

variable *_float::Xor(variable *v){
	debug("> _float::Xor");
	error_conditional(!v,"v is NULL in _float::Xor");
	return new _float(rvalue, value.unsignedint ^ v->value.unsignedint);
}

variable *_float::Inc(){
	debug("> _float::Inc");
	value._float++;
	return this;
}

variable *_float::Dec(){
	debug("> _float::Dec");
	value._float--;
	return this;
}

variable *_float::Neg(){
	debug("> _float::Neg");
	return new _float(rvalue, ~(value.unsignedint));
}


bool _float::operator > (variable *v){
	debug("> _float::>");
	return value._float > v->value._float;
}


void _float::copy_to_pointer(variable *place){
	debug("> _float::copy_to_pointer");
	error_conditional(!place,"place is NULL in _float::copy_to_pointer");
	new(place) _float(variable::rvalue,value._float);
}
