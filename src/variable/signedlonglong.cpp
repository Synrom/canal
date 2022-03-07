#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedlonglong::signedlonglong(const std::string &s,signed long long v) : variable(s){
	type = variable::signedlonglong;
	size = sizeof(signed long long);
	value.signedlonglong = v;
	debug("creating an signedlonglong");
}

signedlonglong::signedlonglong(const variable *v) : variable(v->name) {
	debug("constructing signedlonglong from variable");
	size = sizeof(signed long long);
	type = variable::signedlonglong;
	value.signedlonglong = v->value.signedlonglong;
}

signedlonglong::~signedlonglong(){
	debug("destructing signedlonglong object");
}

void signedlonglong::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Plus what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Plus where == this");
		value.signedlonglong += what->value.signedlonglong;
	}else{
		debug("signedlonglong::Plus where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong + what->value.signedlonglong));
	}
}
void signedlonglong::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Minus what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Minus where == this");
		value.signedlonglong -= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Minus where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong - what->value.signedlonglong));
	}
}
void signedlonglong::Times(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Times what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Times where == this");
		value.signedlonglong *= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Times where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong * what->value.signedlonglong));
	}
}
void signedlonglong::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Divide what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Divide where == this");
		value.signedlonglong /= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Divide where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong / what->value.signedlonglong));
	}
}
void signedlonglong::And(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::And what is NULL");

	if(where == this || !where){
		debug("signedlonglong::And where == this");
		value.signedlonglong &= what->value.signedlonglong;
	}else{
		debug("signedlonglong::And where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong & what->value.signedlonglong));
	}
}
void signedlonglong::Or(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Or what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Or where == this");
		value.signedlonglong |= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Or where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong | what->value.signedlonglong));
	}
}
void signedlonglong::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Xor what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Xor where == this");
		value.signedlonglong ^= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Xor where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong ^ what->value.signedlonglong));
	}
}
void signedlonglong::Inc(variable *where){
	debug("signedlonglong::Inc");
	if(where == this || !where){
		debug("signedlonglong::Inc where == this");
		value.signedlonglong++;
	}else{
		debug("signedlonglong::Inc where != this");
		new (where) signedlonglong("", (double) (value.signedlonglong) + 1);
	}
}

void signedlonglong::Dec(variable *where){
	debug("signedlonglong::Dec");
	if(where == this || !where){
		debug("signedlonglong::Dec where == this");
		value.signedlonglong--;
	}else{
		debug("signedlonglong::Dec where != this");
		new (where) signedlonglong("", (double) (value.signedlonglong) - 1);
	}
}
void signedlonglong::Neg(variable *where){
	debug("signedlonglong::Neg");
	if(where == this || !where){
		debug("signedlonglong::Dec where == this");
		value.signedlonglong = ~value.signedlonglong;
	}else{
		debug("signedlonglong::Dec where != this");
		new (where) signedlonglong("", ~value.signedlonglong);
	}
}

void signedlonglong::Equal(variable *what){
	debug("signedlonglong::Equal");
	error_conditional(!what, "in signedlonglong::Equal what is NULL");

	value.signedlonglong = what->value.signedlonglong;
}
