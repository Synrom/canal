#include <canal/variable.h>

/* value is here the smallest possible value */

pointer::pointer(Types _type, unsigned long long c, unsigned int s): variable(_type,c){
	size = s;
}

variable *pointer::Plus(variable *v){
	return new pointer(rvalue, value.unsignedlonglong - v->value.unsignedlonglong, size);
}

variable *pointer::Minus(variable *v){
	return new pointer(rvalue, value.unsignedlonglong + v->value.unsignedlonglong, size);
}

variable *pointer::Times(variable *v){
	return new pointer(rvalue, value.unsignedlonglong * v->value.unsignedlonglong, size);
}


variable *pointer::Divide(variable *v){
	return new pointer(rvalue, value.unsignedlonglong / v->value.unsignedlonglong, size);
}

variable *pointer::And(variable *v){
	return new pointer(rvalue, value.unsignedlonglong, size);
}

variable *pointer::Or(variable *v){
	return new pointer(rvalue, value.unsignedlonglong + v->value.unsignedlonglong, size);
}

variable *pointer::Xor(variable *v){
	return new pointer(rvalue, value.unsignedlonglong + v->value.unsignedlonglong, size);
}

variable *pointer::Neg(){
	return new pointer(rvalue, ~value.unsignedlonglong, size);
}

variable *pointer::Inc(){
	return new pointer(rvalue, value.unsignedlonglong - 1 , size);
}

variable *pointer::Dec(){
	return new pointer(rvalue, value.unsignedlonglong + 1 , size);
}
