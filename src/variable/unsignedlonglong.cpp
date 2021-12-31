#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedlonglong::unsignedlonglong(const std::string &s,unsigned long long v) : variable(s){
	type = variable::unsignedlonglong;
	size = sizeof(unsigned long long);
	value.unsignedlonglong = v;
	debug("creating an unsignedlonglong");
}

unsignedlonglong::unsignedlonglong(const variable *v) : variable(v->name) {
	debug("constructing unsignedlonglong from variable");
	size = sizeof(unsigned long long);
	type = variable::unsignedlonglong;
	value.unsignedlonglong = v->value.unsignedlonglong;
}

unsignedlonglong::~unsignedlonglong(){
	debug("destructing unsignedlonglong object");
}

void unsignedlonglong::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Plus what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Plus where == this");
		value.unsignedlonglong += what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Plus where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong + what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Minus what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Minus where == this");
		value.unsignedlonglong -= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Minus where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong - what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Times what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Times where == this");
		value.unsignedlonglong *= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Times where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong * what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Divide what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Divide where == this");
		value.unsignedlonglong /= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Divide where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong / what->value.unsignedlonglong));
	}
}
void unsignedlonglong::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::And what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::And where == this");
		value.unsignedlonglong &= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::And where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong & what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Or what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Or where == this");
		value.unsignedlonglong |= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Or where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong | what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Xor where == this");
		value.unsignedlonglong ^= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Xor where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong ^ what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Inc(){
	debug("unsignedlonglong::Inc");
	value.unsignedlonglong++;
}
void unsignedlonglong::Dec(){
	debug("unsignedlonglong::Dec");
	value.unsignedlonglong--;
}
void unsignedlonglong::Neg(variable *where){
	debug("unsignedlonglong::Neg");
	error_conditional(!where, "in unsignedlonglong::Neg where is NULL");

	new (where) unsignedlonglong("", (unsigned long long) (~value.unsignedlonglong));
}
