#include <canal/variable.h>

unsignedchar::unsignedchar(Types _type, unsigned char c): variable(_type,c){
	size = sizeof(unsigned char);
}

variable *unsignedchar::Plus(variable *v){
	return new unsignedchar(rvalue, value.unsignedchar + v->value.unsignedchar);
}

variable *unsignedchar::Minus(variable *v){
	return new unsignedchar(rvalue, value.unsignedchar - v->value.unsignedchar);
}

variable *unsignedchar::Times(variable *v){
	return new unsignedchar(rvalue, value.unsignedchar * v->value.unsignedchar);
}

variable *unsignedchar::Divide(variable *v){
	return new unsignedchar(rvalue, value.unsignedchar / v->value.unsignedchar);
}

variable *unsignedchar::And(variable *v){
	return new unsignedchar(rvalue, value.unsignedchar & v->value.unsignedchar);
}

variable *unsignedchar::Or(variable *v){
	return new unsignedchar(rvalue, value.unsignedchar | v->value.unsignedchar);
}

variable *unsignedchar::Xor(variable *v){
	return new unsignedchar(rvalue, value.unsignedchar ^ v->value.unsignedchar);
}

variable *unsignedchar::Inc(){
	value.unsignedchar++;
	return this;
}

variable *unsignedchar::Dec(){
	value.unsignedchar--;
	return this;
}

variable *unsignedchar::Neg(){
	return new unsignedchar(rvalue, ~(value.unsignedchar));
}

