#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedint::signedint(const std::string &s,signed int v) : variable(s){
	type = variable::signedint;
	size = sizeof(signed int);
	value.signedint = v;
	debug("creating an signedint");
}

signedint::signedint(const variable *v) : variable(v->name) {
	debug("constructing signedint from variable");
	size = sizeof(signed int);
	type = variable::signedint;
	value.signedint = v->value.signedint;
}

signedint::~signedint(){
	debug("destructing signedint object");
}

void signedint::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedint::Plus what is NULL");

	if(where == this || !where){
		debug("signedint::Plus where == this");
		value.signedint += what->value.signedint;
	}else{
		debug("signedint::Plus where != this");
		new (where) signedint("", (signed int) (value.signedint + what->value.signedint));
	}
}
void signedint::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedint::Minus what is NULL");

	if(where == this || !where){
		debug("signedint::Minus where == this");
		value.signedint -= what->value.signedint;
	}else{
		debug("signedint::Minus where != this");
		new (where) signedint("", (signed int) (value.signedint - what->value.signedint));
	}
}
void signedint::Times(variable *where, variable *what){
	error_conditional(!what, "in signedint::Times what is NULL");

	if(where == this || !where){
		debug("signedint::Times where == this");
		value.signedint *= what->value.signedint;
	}else{
		debug("signedint::Times where != this");
		new (where) signedint("", (signed int) (value.signedint * what->value.signedint));
	}
}
void signedint::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedint::Divide what is NULL");

	if(where == this || !where){
		debug("signedint::Divide where == this");
		value.signedint /= what->value.signedint;
	}else{
		debug("signedint::Divide where != this");
		new (where) signedint("", (signed int) (value.signedint / what->value.signedint));
	}
}
void signedint::And(variable *where, variable *what){
	error_conditional(!what, "in signedint::And what is NULL");

	if(where == this || !where){
		debug("signedint::And where == this");
		value.signedint &= what->value.signedint;
	}else{
		debug("signedint::And where != this");
		new (where) signedint("", (signed int) (value.signedint & what->value.signedint));
	}
}
void signedint::Or(variable *where, variable *what){
	error_conditional(!what, "in signedint::Or what is NULL");

	if(where == this || !where){
		debug("signedint::Or where == this");
		value.signedint |= what->value.signedint;
	}else{
		debug("signedint::Or where != this");
		new (where) signedint("", (signed int) (value.signedint | what->value.signedint));
	}
}
void signedint::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedint::Xor what is NULL");

	if(where == this || !where){
		debug("signedint::Xor where == this");
		value.signedint ^= what->value.signedint;
	}else{
		debug("signedint::Xor where != this");
		new (where) signedint("", (signed int) (value.signedint ^ what->value.signedint));
	}
}
void signedint::Inc(){
	debug("signedint::Inc");
	value.signedint++;
}
void signedint::Dec(){
	debug("signedint::Dec");
	value.signedint--;
}
void signedint::Neg(variable *where){
	debug("signedint::Neg");
	error_conditional(!where, "in signedint::Neg where is NULL");

	new (where) signedint("", (signed int) (~value.signedint));
}
