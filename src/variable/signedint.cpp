#include <canal/variable.h>

signedint::signedint(Types _type, signed int v) : variable(_type,v){
	size = sizeof(signed int);
}

variable *signedint::Plus(variable *v){
	return new signedint(rvalue, value.signedint + v->value.signedint);
}

variable *signedint::Minus(variable *v){
	return new signedint(rvalue, value.signedint - v->value.signedint);
}

variable *signedint::Times(variable *v){
	return new signedint(rvalue, value.signedint * v->value.signedint);
}

variable *signedint::Divide(variable *v){
	return new signedint(rvalue, value.signedint / v->value.signedint);
}

variable *signedint::And(variable *v){
	return new signedint(rvalue, value.signedint & v->value.signedint);
}

variable *signedint::Or(variable *v){
	return new signedint(rvalue, value.signedint | v->value.signedint);
}

variable *signedint::Xor(variable *v){
	return new signedint(rvalue, value.signedint ^ v->value.signedint);
}

variable *signedint::Inc(){
	value.signedint++;
	return this;
}

variable *signedint::Dec(){
	value.signedint--;
	return this;
}

variable *signedint::Neg(){
	return new signedint(rvalue, ~(value.signedint));
}

