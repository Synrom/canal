#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedshort::signedshort(const std::string &s,signed short v) : variable(s){
	type = variable::signedshort;
	size = sizeof(signed short);
	value.signedshort = v;
	debug("creating an signedshort");
}

signedshort::signedshort(const variable *v) : variable(v->name) {
	debug("constructing signedshort from variable");
	size = sizeof(signed short);
	type = variable::signedshort;
	value.signedshort = v->value.signedshort;
}

signedshort::~signedshort(){
	debug("destructing signedshort object");
}

void signedshort::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Plus what is NULL");

	if(where == this || !where){
		debug("signedshort::Plus where == this");
		value.signedshort += what->value.signedshort;
	}else{
		debug("signedshort::Plus where != this");
		new (where) signedshort("", (signed short) (value.signedshort + what->value.signedshort));
	}
}
void signedshort::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Minus what is NULL");

	if(where == this || !where){
		debug("signedshort::Minus where == this");
		value.signedshort -= what->value.signedshort;
	}else{
		debug("signedshort::Minus where != this");
		new (where) signedshort("", (signed short) (value.signedshort - what->value.signedshort));
	}
}
void signedshort::Times(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Times what is NULL");

	if(where == this || !where){
		debug("signedshort::Times where == this");
		value.signedshort *= what->value.signedshort;
	}else{
		debug("signedshort::Times where != this");
		new (where) signedshort("", (signed short) (value.signedshort * what->value.signedshort));
	}
}
void signedshort::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Divide what is NULL");

	if(where == this || !where){
		debug("signedshort::Divide where == this");
		value.signedshort /= what->value.signedshort;
	}else{
		debug("signedshort::Divide where != this");
		new (where) signedshort("", (signed short) (value.signedshort / what->value.signedshort));
	}
}
void signedshort::And(variable *where, variable *what){
	error_conditional(!what, "in signedshort::And what is NULL");

	if(where == this || !where){
		debug("signedshort::And where == this");
		value.signedshort &= what->value.signedshort;
	}else{
		debug("signedshort::And where != this");
		new (where) signedshort("", (signed short) (value.signedshort & what->value.signedshort));
	}
}
void signedshort::Or(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Or what is NULL");

	if(where == this || !where){
		debug("signedshort::Or where == this");
		value.signedshort |= what->value.signedshort;
	}else{
		debug("signedshort::Or where != this");
		new (where) signedshort("", (signed short) (value.signedshort | what->value.signedshort));
	}
}
void signedshort::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Xor what is NULL");

	if(where == this || !where){
		debug("signedshort::Xor where == this");
		value.signedshort ^= what->value.signedshort;
	}else{
		debug("signedshort::Xor where != this");
		new (where) signedshort("", (signed short) (value.signedshort ^ what->value.signedshort));
	}
}
void signedshort::Inc(){
	debug("signedshort::Inc");
	value.signedshort++;
}
void signedshort::Dec(){
	debug("signedshort::Dec");
	value.signedshort--;
}
void signedshort::Neg(variable *where){
	debug("signedshort::Neg");
	error_conditional(!where, "in signedshort::Neg where is NULL");

	new (where) signedshort("", (signed short) (~value.signedshort));
}

void signedshort::Equal(variable *what){
	debug("signedshort::Equal");
	error_conditional(!what, "in signedshort::Equal what is NULL");

	value.signedshort = what->value.signedshort;
}
