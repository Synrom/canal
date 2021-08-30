#include <canal/variable.h>

unsignedint::unsignedint(Types _type, unsigned int v) : variable(_type,v){
	size = sizeof(unsigned int);
}

variable *unsignedint::Plus(variable *v){
	return new unsignedint(rvalue, value.unsignedint + v->value.unsignedint);
}

variable *unsignedint::Minus(variable *v){
	return new unsignedint(rvalue, value.unsignedint - v->value.unsignedint);
}

variable *unsignedint::Times(variable *v){
	return new unsignedint(rvalue, value.unsignedint * v->value.unsignedint);
}

variable *unsignedint::Divide(variable *v){
	return new unsignedint(rvalue, value.unsignedint / v->value.unsignedint);
}

variable *unsignedint::And(variable *v){
	return new unsignedint(rvalue, value.unsignedint & v->value.unsignedint);
}

variable *unsignedint::Or(variable *v){
	return new unsignedint(rvalue, value.unsignedint | v->value.unsignedint);
}

variable *unsignedint::Xor(variable *v){
	return new unsignedint(rvalue, value.unsignedint ^ v->value.unsignedint);
}

variable *unsignedint::Inc(){
	value.unsignedint++;
	return this;
}

variable *unsignedint::Dec(){
	value.unsignedint--;
	return this;
}

variable *unsignedint::Neg(){
	return new unsignedint(rvalue, ~(value.unsignedint));
}

