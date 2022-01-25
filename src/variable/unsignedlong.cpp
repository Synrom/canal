#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedlong::unsignedlong(const std::string &s,unsigned long v) : variable(s){
	type = variable::unsignedlong;
	size = sizeof(unsigned long);
	value.unsignedlong = v;
	debug("creating an unsignedlong");
}

unsignedlong::unsignedlong(const variable *v) : variable(v->name) {
	debug("constructing unsignedlong from variable");
	size = sizeof(unsigned long);
	type = variable::unsignedlong;
	value.unsignedlong = v->value.unsignedlong;
}

unsignedlong::~unsignedlong(){
	debug("destructing unsignedlong object");
}

void unsignedlong::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Plus what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Plus where == this");
		value.unsignedlong += what->value.unsignedlong;
	}else{
		debug("unsignedlong::Plus where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong + what->value.unsignedlong));
	}
}
void unsignedlong::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Minus what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Minus where == this");
		value.unsignedlong -= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Minus where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong - what->value.unsignedlong));
	}
}
void unsignedlong::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Times what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Times where == this");
		value.unsignedlong *= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Times where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong * what->value.unsignedlong));
	}
}
void unsignedlong::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Divide what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Divide where == this");
		value.unsignedlong /= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Divide where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong / what->value.unsignedlong));
	}
}
void unsignedlong::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::And what is NULL");

	if(where == this || !where){
		debug("unsignedlong::And where == this");
		value.unsignedlong &= what->value.unsignedlong;
	}else{
		debug("unsignedlong::And where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong & what->value.unsignedlong));
	}
}
void unsignedlong::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Or what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Or where == this");
		value.unsignedlong |= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Or where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong | what->value.unsignedlong));
	}
}
void unsignedlong::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Xor where == this");
		value.unsignedlong ^= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Xor where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong ^ what->value.unsignedlong));
	}
}
void unsignedlong::Inc(){
	debug("unsignedlong::Inc");
	value.unsignedlong++;
}
void unsignedlong::Dec(){
	debug("unsignedlong::Dec");
	value.unsignedlong--;
}
void unsignedlong::Neg(variable *where){
	debug("unsignedlong::Neg");
	error_conditional(!where, "in unsignedlong::Neg where is NULL");

	new (where) unsignedlong("", (unsigned long) (~value.unsignedlong));
}

void unsignedlong::Equal(variable *what){
	debug("unsignedlong::Equal");
	error_conditional(!what, "in unsignedlong::Equal what is NULL");

	value.unsignedlong = what->value.unsignedlong;
}
