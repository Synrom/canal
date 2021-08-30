#include <canal/variable.h>

unsignedlong::unsignedlong(Types _type, unsigned long c): variable(_type,c){
	size = sizeof(unsigned long);
}

variable *unsignedlong::Plus(variable *v){
	return new unsignedlong(rvalue, value.unsignedlong + v->value.unsignedlong);
}

variable *unsignedlong::Minus(variable *v){
	return new unsignedlong(rvalue, value.unsignedlong - v->value.unsignedlong);
}

variable *unsignedlong::Times(variable *v){
	return new unsignedlong(rvalue, value.unsignedlong * v->value.unsignedlong);
}

variable *unsignedlong::Divide(variable *v){
	return new unsignedlong(rvalue, value.unsignedlong / v->value.unsignedlong);
}

variable *unsignedlong::And(variable *v){
	return new unsignedlong(rvalue, value.unsignedlong & v->value.unsignedlong);
}

variable *unsignedlong::Or(variable *v){
	return new unsignedlong(rvalue, value.unsignedlong | v->value.unsignedlong);
}

variable *unsignedlong::Xor(variable *v){
	return new unsignedlong(rvalue, value.unsignedlong ^ v->value.unsignedlong);
}

variable *unsignedlong::Inc(){
	value.unsignedlong++;
	return this;
}

variable *unsignedlong::Dec(){
	value.unsignedlong--;
	return this;
}

variable *unsignedlong::Neg(){
	return new unsignedlong(rvalue, ~(value.unsignedlong));
}

