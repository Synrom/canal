#include <canal/variable.h>

signedchar::signedchar(Types _type, signed char c) : variable(_type,c){
	size = sizeof(signed char);
}

variable *signedchar::Plus(variable *v){
	return new signedchar(rvalue, value.signedchar + v->value.signedchar);
}

variable *signedchar::Minus(variable *v){
	return new signedchar(rvalue, value.signedchar - v->value.signedchar);
}

variable *signedchar::Times(variable *v){
	return new signedchar(rvalue, value.signedchar * v->value.signedchar);
}

variable *signedchar::Divide(variable *v){
	return new signedchar(rvalue, value.signedchar / v->value.signedchar);
}

variable *signedchar::And(variable *v){
	return new signedchar(rvalue, value.signedchar & v->value.signedchar);
}

variable *signedchar::Or(variable *v){
	return new signedchar(rvalue, value.signedchar | v->value.signedchar);
}

variable *signedchar::Xor(variable *v){
	return new signedchar(rvalue, value.signedchar ^ v->value.signedchar);
}

variable *signedchar::Inc(){
	value.signedchar++;
	return this;
}

variable *signedchar::Dec(){
	value.signedchar--;
	return this;
}

variable *signedchar::Neg(){
	return new signedchar(rvalue, ~(value.signedchar));
}

