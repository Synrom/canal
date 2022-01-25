#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedchar::signedchar(const std::string &s,signed char v) : variable(s){
	type = variable::signedchar;
	size = sizeof(signed char);
	value.signedchar = v;
	debug("creating an signedchar");
}

signedchar::signedchar(const variable *v) : variable(v->name) {
	debug("constructing signedchar from variable");
	size = sizeof(signed char);
	type = variable::signedchar;
	value.signedchar = v->value.signedchar;
}

signedchar::~signedchar(){
	debug("destructing signedchar object");
}

void signedchar::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Plus what is NULL");

	if(where == this || !where){
		debug("signedchar::Plus where == this");
		value.signedchar += what->value.signedchar;
	}else{
		debug("signedchar::Plus where != this");
		new (where) signedchar("", (signed char) (value.signedchar + what->value.signedchar));
	}
}
void signedchar::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Minus what is NULL");

	if(where == this || !where){
		debug("signedchar::Minus where == this");
		value.signedchar -= what->value.signedchar;
	}else{
		debug("signedchar::Minus where != this");
		new (where) signedchar("", (signed char) (value.signedchar - what->value.signedchar));
	}
}
void signedchar::Times(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Times what is NULL");

	if(where == this || !where){
		debug("signedchar::Times where == this");
		value.signedchar *= what->value.signedchar;
	}else{
		debug("signedchar::Times where != this");
		new (where) signedchar("", (signed char) (value.signedchar * what->value.signedchar));
	}
}
void signedchar::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Divide what is NULL");

	if(where == this || !where){
		debug("signedchar::Divide where == this");
		value.signedchar /= what->value.signedchar;
	}else{
		debug("signedchar::Divide where != this");
		new (where) signedchar("", (signed char) (value.signedchar / what->value.signedchar));
	}
}
void signedchar::And(variable *where, variable *what){
	error_conditional(!what, "in signedchar::And what is NULL");

	if(where == this || !where){
		debug("signedchar::And where == this");
		value.signedchar &= what->value.signedchar;
	}else{
		debug("signedchar::And where != this");
		new (where) signedchar("", (signed char) (value.signedchar & what->value.signedchar));
	}
}
void signedchar::Or(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Or what is NULL");

	if(where == this || !where){
		debug("signedchar::Or where == this");
		value.signedchar |= what->value.signedchar;
	}else{
		debug("signedchar::Or where != this");
		new (where) signedchar("", (signed char) (value.signedchar | what->value.signedchar));
	}
}
void signedchar::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Xor what is NULL");

	if(where == this || !where){
		debug("signedchar::Xor where == this");
		value.signedchar ^= what->value.signedchar;
	}else{
		debug("signedchar::Xor where != this");
		new (where) signedchar("", (signed char) (value.signedchar ^ what->value.signedchar));
	}
}
void signedchar::Inc(){
	debug("signedchar::Inc");
	value.signedchar++;
}
void signedchar::Dec(){
	debug("signedchar::Dec");
	value.signedchar--;
}
void signedchar::Neg(variable *where){
	debug("signedchar::Neg");
	error_conditional(!where, "in signedchar::Neg where is NULL");

	new (where) signedchar("", (signed char) (~value.signedchar));
}

void signedchar::Equal(variable *what){
	debug("signedchar::Equal");
	error_conditional(!what, "in signedchar::Equal what is NULL");

	value.signedchar = what->value.signedchar;
}
