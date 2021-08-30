#include <canal/variable.h>

longdouble::longdouble(Types _type,long double c): variable(_type,c){
	size = sizeof(long double);
}

longdouble::longdouble(Types _type,unsigned int c): variable(_type,c){
	size = sizeof(long double);
}

variable *longdouble::Plus(variable *v){
	return new longdouble(rvalue, value.longdouble + v->value.longdouble);
}

variable *longdouble::Minus(variable *v){
	return new longdouble(rvalue, value.longdouble - v->value.longdouble);
}

variable *longdouble::Times(variable *v){
	return new longdouble(rvalue, value.longdouble * v->value.longdouble);
}

variable *longdouble::Divide(variable *v){
	return new longdouble(rvalue, value.longdouble / v->value.longdouble);
}

variable *longdouble::And(variable *v){
	return new longdouble(rvalue, value.unsignedint & v->value.unsignedint);
}

variable *longdouble::Or(variable *v){
	return new longdouble(rvalue, value.unsignedint | v->value.unsignedint);
}

variable *longdouble::Xor(variable *v){
	return new longdouble(rvalue, value.unsignedint ^ v->value.unsignedint);
}

variable *longdouble::Inc(){
	value.longdouble++;
	return this;
}

variable *longdouble::Dec(){
	value.longdouble--;
	return this;
}

variable *longdouble::Neg(){
	return new longdouble(rvalue, ~(value.unsignedint));
}

