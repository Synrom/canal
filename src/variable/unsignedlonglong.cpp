#include <canal/variable.h>

unsignedlonglong::unsignedlonglong(Types _type, unsigned long long c): variable(_type,c){
	size = sizeof(unsigned long long);
}

variable *unsignedlonglong::Plus(variable *v){
	return new unsignedlonglong(rvalue, value.unsignedlonglong + v->value.unsignedlonglong);
}

variable *unsignedlonglong::Minus(variable *v){
	return new unsignedlonglong(rvalue, value.unsignedlonglong - v->value.unsignedlonglong);
}

variable *unsignedlonglong::Times(variable *v){
	return new unsignedlonglong(rvalue, value.unsignedlonglong * v->value.unsignedlonglong);
}

variable *unsignedlonglong::Divide(variable *v){
	return new unsignedlonglong(rvalue, value.unsignedlonglong / v->value.unsignedlonglong);
}

variable *unsignedlonglong::And(variable *v){
	return new unsignedlonglong(rvalue, value.unsignedlonglong & v->value.unsignedlonglong);
}

variable *unsignedlonglong::Or(variable *v){
	return new unsignedlonglong(rvalue, value.unsignedlonglong | v->value.unsignedlonglong);
}

variable *unsignedlonglong::Xor(variable *v){
	return new unsignedlonglong(rvalue, value.unsignedlonglong ^ v->value.unsignedlonglong);
}

variable *unsignedlonglong::Inc(){
	value.unsignedlonglong++;
	return this;
}

variable *unsignedlonglong::Dec(){
	value.unsignedlonglong--;
	return this;
}

variable *unsignedlonglong::Neg(){
	return new unsignedlonglong(rvalue, ~(value.unsignedlonglong));
}

