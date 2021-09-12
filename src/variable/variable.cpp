#include <canal/variable.h>
#include <canal/debugger.h>

variable::variable(Types _type, signed char c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.signedchar = c;
}

variable::variable(Types _type, unsigned char c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.unsignedchar = c;
}

variable::variable(Types _type, signed short  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.signedshort = c;
}

variable::variable(Types _type, unsigned short c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.unsignedshort = c;
}

variable::variable(Types _type, signed int  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.signedint = c;
}

variable::variable(Types _type, unsigned int  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.unsignedint = c;
}

variable::variable(Types _type, signed long  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.signedlong = c;
}

variable::variable(Types _type, unsigned long  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.unsignedlong = c;
}

variable::variable(Types _type, signed long long  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.signedlonglong = c;
}

variable::variable(Types _type, unsigned long long  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = c;
}

variable::variable(Types _type, float  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value._float = c;
}

variable::variable(Types _type, double  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value._double = c;
}

variable::variable(Types _type, long double  c){
	debug("constructing variable");
	type = _type;
	value.unsignedlonglong = 0;
	value.longdouble = c;
}

variable::~variable(){
}
