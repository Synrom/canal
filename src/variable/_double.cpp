#include <canal/variable.h>

_double::_double(Types _type, double c): variable(_type,c){
	size = sizeof(double);
}

_double::_double(Types _type, unsigned int c): variable(_type,c){
	size = sizeof(double);
}

variable *_double::Plus(variable *v){
	return new _double(rvalue, value._double + v->value._double);
}

variable *_double::Minus(variable *v){
	return new _double(rvalue, value._double - v->value._double);
}

variable *_double::Times(variable *v){
	return new _double(rvalue, value._double * v->value._double);
}

variable *_double::Divide(variable *v){
	return new _double(rvalue, value._double / v->value._double);
}

variable *_double::And(variable *v){
	return new _double(rvalue, value.unsignedint & v->value.unsignedint);
}

variable *_double::Or(variable *v){
	return new _double(rvalue, value.unsignedint | v->value.unsignedint);
}

variable *_double::Xor(variable *v){
	return new _double(rvalue, value.unsignedint ^ v->value.unsignedint);
}

variable *_double::Inc(){
	value._double++;
	return this;
}

variable *_double::Dec(){
	value._double--;
	return this;
}

variable *_double::Neg(){
	return new _double(rvalue, ~(value.unsignedint));
}

