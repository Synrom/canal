#include <canal/variable.h>
#include <canal/debugger.h>

_double::_double(Types _type, double c): variable(_type,c){
	debug("constructing _double");
	size = sizeof(double);
}

_double::_double(Types _type, unsigned int c): variable(_type,c){
	debug("constructing _double");
	size = sizeof(double);
}

variable *_double::Plus(variable *v){
	debug("> _double::Plus");
	error_conditional(!v, "v is NULL in _double::Plus");
	return new _double(rvalue, value._double + v->value._double);
}

variable *_double::Minus(variable *v){
	debug("> _double::Minus");
	error_conditional(!v, "v is NULL in _double::Minus");
	return new _double(rvalue, value._double - v->value._double);
}

variable *_double::Times(variable *v){
	debug("> _double::Times");
	error_conditional(!v, "v is NULL in _double::Times");
	return new _double(rvalue, value._double * v->value._double);
}

variable *_double::Divide(variable *v){
	debug("> _double::Divide");
	error_conditional(!v, "v is NULL in _double::Divide");
	return new _double(rvalue, value._double / v->value._double);
}

variable *_double::And(variable *v){
	debug("> _double::And");
	error_conditional(!v, "v is NULL in _double::And");
	return new _double(rvalue, value.unsignedint & v->value.unsignedint);
}

variable *_double::Or(variable *v){
	debug("> _double::Or");
	error_conditional(!v, "v is NULL in _double::Or");
	return new _double(rvalue, value.unsignedint | v->value.unsignedint);
}

variable *_double::Xor(variable *v){
	debug("> _double::Xor");
	error_conditional(!v, "v is NULL in _double::Xor");
	return new _double(rvalue, value.unsignedint ^ v->value.unsignedint);
}

variable *_double::Inc(){
	debug("> _double::Inc");
	value._double++;
	return this;
}

variable *_double::Dec(){
	debug("> _double::Dec");
	value._double--;
	return this;
}

variable *_double::Neg(){
	debug("> _double::Neg");
	return new _double(rvalue, ~(value.unsignedint));
}



bool _double::operator > (variable *v){
	debug("> _double::>");
	error_conditional(!v,"v is NULL in _double::operator >");
	return value._double > v->value._double;
}


void _double::copy_to_pointer(variable *place){
	debug("> _double::copy_to_pointer");
	error_conditional(!v,"place is NULL in _double::copy_to_pointer");
	new(place) _double(variable::rvalue,value._double);
}
