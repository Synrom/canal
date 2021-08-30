#include <canal/variable.h>

signedlong::signedlong(Types _type, signed long c): variable(_type,c){
	size = sizeof(signed long);
}

variable *signedlong::Plus(variable *v){
	return new signedlong(rvalue, value.signedlong + v->value.signedlong);
}

variable *signedlong::Minus(variable *v){
	return new signedlong(rvalue, value.signedlong - v->value.signedlong);
}

variable *signedlong::Times(variable *v){
	return new signedlong(rvalue, value.signedlong * v->value.signedlong);
}

variable *signedlong::Divide(variable *v){
	return new signedlong(rvalue, value.signedlong / v->value.signedlong);
}

variable *signedlong::And(variable *v){
	return new signedlong(rvalue, value.signedlong & v->value.signedlong);
}

variable *signedlong::Or(variable *v){
	return new signedlong(rvalue, value.signedlong | v->value.signedlong);
}

variable *signedlong::Xor(variable *v){
	return new signedlong(rvalue, value.signedlong ^ v->value.signedlong);
}

variable *signedlong::Inc(){
	value.signedlong++;
	return this;
}

variable *signedlong::Dec(){
	value.signedlong--;
	return this;
}

variable *signedlong::Neg(){
	return new signedlong(rvalue, ~(value.signedlong));
}

