#include <canal/variable.h>

signedlonglong::signedlonglong(Types _type, signed long long c): variable(_type,c){
	size = sizeof(signed long long);
}

variable *signedlonglong::Plus(variable *v){
	return new signedlonglong(rvalue, value.signedlonglong + v->value.signedlonglong);
}

variable *signedlonglong::Minus(variable *v){
	return new signedlonglong(rvalue, value.signedlonglong - v->value.signedlonglong);
}

variable *signedlonglong::Times(variable *v){
	return new signedlonglong(rvalue, value.signedlonglong * v->value.signedlonglong);
}

variable *signedlonglong::Divide(variable *v){
	return new signedlonglong(rvalue, value.signedlonglong / v->value.signedlonglong);
}

variable *signedlonglong::And(variable *v){
	return new signedlonglong(rvalue, value.signedlonglong & v->value.signedlonglong);
}

variable *signedlonglong::Or(variable *v){
	return new signedlonglong(rvalue, value.signedlonglong | v->value.signedlonglong);
}

variable *signedlonglong::Xor(variable *v){
	return new signedlonglong(rvalue, value.signedlonglong ^ v->value.signedlonglong);
}

variable *signedlonglong::Inc(){
	value.signedlonglong++;
	return this;
}

variable *signedlonglong::Dec(){
	value.signedlonglong--;
	return this;
}

variable *signedlonglong::Neg(){
	return new signedlonglong(rvalue, ~(value.signedlonglong));
}

