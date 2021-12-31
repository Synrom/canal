#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedlong::signedlong(const std::string &s,signed long v) : variable(s){
	type = variable::signedlong;
	size = sizeof(signed long);
	value.signedlong = v;
	debug("creating an signedlong");
}

signedlong::signedlong(const variable *v) : variable(v->name) {
	debug("constructing signedlong from variable");
	size = sizeof(signed long);
	type = variable::signedlong;
	value.signedlong = v->value.signedlong;
}

signedlong::~signedlong(){
	debug("destructing signedlong object");
}

void signedlong::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Plus what is NULL");

	if(where == this || !where){
		debug("signedlong::Plus where == this");
		value.signedlong += what->value.signedlong;
	}else{
		debug("signedlong::Plus where != this");
		new (where) signedlong("", (signed long) (value.signedlong + what->value.signedlong));
	}
}
void signedlong::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Minus what is NULL");

	if(where == this || !where){
		debug("signedlong::Minus where == this");
		value.signedlong -= what->value.signedlong;
	}else{
		debug("signedlong::Minus where != this");
		new (where) signedlong("", (signed long) (value.signedlong - what->value.signedlong));
	}
}
void signedlong::Times(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Times what is NULL");

	if(where == this || !where){
		debug("signedlong::Times where == this");
		value.signedlong *= what->value.signedlong;
	}else{
		debug("signedlong::Times where != this");
		new (where) signedlong("", (signed long) (value.signedlong * what->value.signedlong));
	}
}
void signedlong::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Divide what is NULL");

	if(where == this || !where){
		debug("signedlong::Divide where == this");
		value.signedlong /= what->value.signedlong;
	}else{
		debug("signedlong::Divide where != this");
		new (where) signedlong("", (signed long) (value.signedlong / what->value.signedlong));
	}
}
void signedlong::And(variable *where, variable *what){
	error_conditional(!what, "in signedlong::And what is NULL");

	if(where == this || !where){
		debug("signedlong::And where == this");
		value.signedlong &= what->value.signedlong;
	}else{
		debug("signedlong::And where != this");
		new (where) signedlong("", (signed long) (value.signedlong & what->value.signedlong));
	}
}
void signedlong::Or(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Or what is NULL");

	if(where == this || !where){
		debug("signedlong::Or where == this");
		value.signedlong |= what->value.signedlong;
	}else{
		debug("signedlong::Or where != this");
		new (where) signedlong("", (signed long) (value.signedlong | what->value.signedlong));
	}
}
void signedlong::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Xor what is NULL");

	if(where == this || !where){
		debug("signedlong::Xor where == this");
		value.signedlong ^= what->value.signedlong;
	}else{
		debug("signedlong::Xor where != this");
		new (where) signedlong("", (signed long) (value.signedlong ^ what->value.signedlong));
	}
}
void signedlong::Inc(){
	debug("signedlong::Inc");
	value.signedlong++;
}
void signedlong::Dec(){
	debug("signedlong::Dec");
	value.signedlong--;
}
void signedlong::Neg(variable *where){
	debug("signedlong::Neg");
	error_conditional(!where, "in signedlong::Neg where is NULL");

	new (where) signedlong("", (signed long) (~value.signedlong));
}
