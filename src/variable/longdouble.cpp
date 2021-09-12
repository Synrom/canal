#include <canal/variable.h>
#include <canal/debugger.h>

longdouble::longdouble(Types _type,long double c): variable(_type,c){
	debug("constructing longdouble");
	size = sizeof(long double);
}

longdouble::longdouble(Types _type,unsigned int c): variable(_type,c){
	debug("constructing longdouble");
	size = sizeof(long double);
}

variable *longdouble::Plus(variable *v){
	debug("> longdoube::Plus");
	error_conditional(!v,"v is NULL in longdouble::Plus");
	return new longdouble(rvalue, value.longdouble + v->value.longdouble);
}

variable *longdouble::Minus(variable *v){
	debug("> longdoube::Minus");
	error_conditional(!v,"v is NULL in longdouble::Minus");
	return new longdouble(rvalue, value.longdouble - v->value.longdouble);
}

variable *longdouble::Times(variable *v){
	debug("> longdoube::Times");
	error_conditional(!v,"v is NULL in longdouble::Times");
	return new longdouble(rvalue, value.longdouble * v->value.longdouble);
}

variable *longdouble::Divide(variable *v){
	debug("> longdoube::Divide");
	error_conditional(!v,"v is NULL in longdouble::Divide");
	return new longdouble(rvalue, value.longdouble / v->value.longdouble);
}

variable *longdouble::And(variable *v){
	debug("> longdoube::And");
	error_conditional(!v,"v is NULL in longdouble::And");
	return new longdouble(rvalue, value.unsignedint & v->value.unsignedint);
}

variable *longdouble::Or(variable *v){
	debug("> longdoube::Or");
	error_conditional(!v,"v is NULL in longdouble::Or");
	return new longdouble(rvalue, value.unsignedint | v->value.unsignedint);
}

variable *longdouble::Xor(variable *v){
	debug("> longdoube::Xor");
	error_conditional(!v,"v is NULL in longdouble::Xor");
	return new longdouble(rvalue, value.unsignedint ^ v->value.unsignedint);
}

variable *longdouble::Inc(){
	debug("> longdoube::Inc");
	value.longdouble++;
	return this;
}

variable *longdouble::Dec(){
	debug("> longdoube::Dec");
	value.longdouble--;
	return this;
}

variable *longdouble::Neg(){
	debug("> longdoube::Neg");
	return new longdouble(rvalue, ~(value.unsignedint));
}


bool longdouble::operator > (variable *v){
	debug("> longdoube::>");
	error_conditional(!v,"v is NULL in longdouble::>");
	return value.longdouble > v->value.longdouble;
}


void longdouble::copy_to_pointer(variable *place){
	debug("> longdoube::copy_to_pointer");
	error_conditional(!place,"place is NULL in longdouble::copy_to_pointer");
	new(place) longdouble(variable::rvalue,value.longdouble);
}
