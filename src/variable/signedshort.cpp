#include <canal/variable.h>

signedshort::signedshort(Types _type, signed short c): variable(_type,c){
	size = sizeof(signed short);
}

variable *signedshort::Plus(variable *v){
	return new signedshort(rvalue, value.signedshort + v->value.signedshort);
}

variable *signedshort::Minus(variable *v){
	return new signedshort(rvalue, value.signedshort - v->value.signedshort);
}

variable *signedshort::Times(variable *v){
	return new signedshort(rvalue, value.signedshort * v->value.signedshort);
}

variable *signedshort::Divide(variable *v){
	return new signedshort(rvalue, value.signedshort / v->value.signedshort);
}

variable *signedshort::And(variable *v){
	return new signedshort(rvalue, value.signedshort & v->value.signedshort);
}

variable *signedshort::Or(variable *v){
	return new signedshort(rvalue, value.signedshort | v->value.signedshort);
}

variable *signedshort::Xor(variable *v){
	return new signedshort(rvalue, value.signedshort ^ v->value.signedshort);
}

variable *signedshort::Inc(){
	value.signedshort++;
	return this;
}

variable *signedshort::Dec(){
	value.signedshort--;
	return this;
}

variable *signedshort::Neg(){
	return new signedshort(rvalue, ~(value.signedshort));
}

