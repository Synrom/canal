#include <canal/variable.h>

unsignedshort::unsignedshort(Types _type, unsigned short c): variable(_type,c){
	size = sizeof(unsigned short);
}

variable *unsignedshort::Plus(variable *v){
	return new unsignedshort(rvalue, value.unsignedshort + v->value.unsignedshort);
}

variable *unsignedshort::Minus(variable *v){
	return new unsignedshort(rvalue, value.unsignedshort - v->value.unsignedshort);
}

variable *unsignedshort::Times(variable *v){
	return new unsignedshort(rvalue, value.unsignedshort * v->value.unsignedshort);
}

variable *unsignedshort::Divide(variable *v){
	return new unsignedshort(rvalue, value.unsignedshort / v->value.unsignedshort);
}

variable *unsignedshort::And(variable *v){
	return new unsignedshort(rvalue, value.unsignedshort & v->value.unsignedshort);
}

variable *unsignedshort::Or(variable *v){
	return new unsignedshort(rvalue, value.unsignedshort | v->value.unsignedshort);
}

variable *unsignedshort::Xor(variable *v){
	return new unsignedshort(rvalue, value.unsignedshort ^ v->value.unsignedshort);
}

variable *unsignedshort::Inc(){
	value.unsignedshort++;
	return this;
}

variable *unsignedshort::Dec(){
	value.unsignedshort--;
	return this;
}

variable *unsignedshort::Neg(){
	return new unsignedshort(rvalue, ~(value.unsignedshort));
}

