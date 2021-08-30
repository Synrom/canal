#include <canal/variable.h>

_float::_float(Types _type, float c): variable(_type,c){
	size = sizeof(float);
}

_float::_float(Types _type, unsigned int c): variable(_type,c){
	size = sizeof(float);
}

variable *_float::Plus(variable *v){
	return new _float(rvalue, value._float + v->value._float);
}

variable *_float::Minus(variable *v){
	return new _float(rvalue, value._float - v->value._float);
}

variable *_float::Times(variable *v){
	return new _float(rvalue, value._float * v->value._float);
}

variable *_float::Divide(variable *v){
	return new _float(rvalue, value._float / v->value._float);
}

variable *_float::And(variable *v){
	return new _float(rvalue, value.unsignedint & v->value.unsignedint);
}

variable *_float::Or(variable *v){
	return new _float(rvalue, value.unsignedint | v->value.unsignedint);
}

variable *_float::Xor(variable *v){
	return new _float(rvalue, value.unsignedint ^ v->value.unsignedint);
}

variable *_float::Inc(){
	value._float++;
	return this;
}

variable *_float::Dec(){
	value._float--;
	return this;
}

variable *_float::Neg(){
	return new _float(rvalue, ~(value.unsignedint));
}

