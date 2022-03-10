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
void signedlong::Inc(variable *where){
	debug("signedlong::Inc");
	if(where == this || !where){
		debug("signedlong::Inc where == this");
		value.signedlong++;
	}else{
		debug("signedlong::Inc where != this");
		new (where) signedlong("", (value.signedlong) + 1);
	}
}

void signedlong::Dec(variable *where){
	debug("signedlong::Dec");
	if(where == this || !where){
		debug("signedlong::Dec where == this");
		value.signedlong--;
	}else{
		debug("signedlong::Dec where != this");
		new (where) signedlong("", (value.signedlong) - 1);
	}
}
void signedlong::Neg(variable *where){
	debug("signedlong::Neg");
	if(where == this || !where){
		debug("signedlong::Dec where == this");
		value.signedlong = ~value.signedlong;
	}else{
		debug("signedlong::Dec where != this");
		new (where) signedlong("", ~value.signedlong);
	}
}

void signedlong::Equal(variable *what){
	debug("signedlong::Equal");
	error_conditional(!what, "in signedlong::Equal what is NULL");

	value.signedlong = what->value.signedlong;
}
