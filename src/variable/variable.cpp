#include <canal/variable.h>

variable::variable(Types _type, signed char c){
	type = _type;
	value.unsignedlonglong = 0;
	value.signedchar = c;
}

variable::variable(Types _type, unsigned char c){
	type = _type;
	value.unsignedlonglong = 0;
	value.unsignedchar = c;
}

variable::variable(Types _type, signed short  c){
	type = _type;
	value.unsignedlonglong = 0;
	value.signedshort = c;
}

variable::variable(Types _type, unsigned short c){
	type = _type;
	value.unsignedlonglong = 0;
	value.unsignedshort = c;
}

variable::variable(Types _type, signed int  c){
	type = _type;
	value.unsignedlonglong = 0;
	value.signedint = c;
}

variable::variable(Types _type, unsigned int  c){
	type = _type;
	value.unsignedlonglong = 0;
	value.unsignedint = c;
}

variable::variable(Types _type, signed long  c){
	type = _type;
	value.unsignedlonglong = 0;
	value.signedlong = c;
}

variable::variable(Types _type, unsigned long  c){
	type = _type;
	value.unsignedlonglong = 0;
	value.unsignedlong = c;
}

variable::variable(Types _type, signed long long  c){
	type = _type;
	value.unsignedlonglong = 0;
	value.signedlonglong = c;
}

variable::variable(Types _type, unsigned long long  c){
	type = _type;
	value.unsignedlonglong = c;
}

variable::variable(Types _type, float  c){
	type = _type;
	value.unsignedlonglong = 0;
	value._float = c;
}

variable::variable(Types _type, double  c){
	type = _type;
	value.unsignedlonglong = 0;
	value._double = c;
}

variable::variable(Types _type, long double  c){
	type = _type;
	value.unsignedlonglong = 0;
	value.longdouble = c;
}

variable::~variable(){
}
