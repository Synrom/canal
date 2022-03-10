#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>


pointer::pointer(const std::string &s, signed long long c, unsigned int si): variable(s){
	debug("constructing pointer");
	size = si;
	value.signedlonglong = c;
	type = variable::pointer;
}

pointer::pointer(const variable *cpy) : variable(cpy->name) {
	debug("constructing pointer from variable");
	size = cpy->size;
	type = variable::pointer;
	value.signedlonglong = cpy->signedlonglong;
}

pointer::~pointer(){
	debug("destructing pointer object");
}

void pointer::Plus(variable *where, variable *what){
	error_conditional(!what, "in pointer::Plus what is NULL");

	if(where == this || !where){
		debug("pointer::Plus where == this");
		value.signedlonglong -= (what->value.signedlonglong * size);
	}else{
		debug("pointer::Plus where != this");
		new (where) pointer("", (signed long long) (value.signedlonglong - (what->value.signedlonglong * size)), size);
	}
}
void pointer::Minus(variable *where, variable *what){
	error_conditional(!what, "in pointer::Minus what is NULL");

	if(where == this || !where){
		debug("pointer::Minus where == this");
		value.signedlonglong += (what->value.signedlonglong * size);
	}else{
		debug("pointer::Minus where != this");
		new (where) pointer("", (signed long long) (value.signedlonglong + (what->value.signedlonglong * size)), size);
	}
}
void pointer::Times(variable *where, variable *what){
	error_conditional(!what, "in pointer::Times what is NULL");
	warning("pointer::Times got called which is weird");

	if(where == this || !where){
		debug("pointer::Times where == this");
		value.signedlonglong *= what->value.signedlonglong;
	}else{
		debug("pointer::Times where != this");
		new (where) pointer("", (signed long long) (value.signedlonglong * what->value.signedlonglong), size);
	}
}
void pointer::Divide(variable *where, variable *what){
	error_conditional(!what, "in pointer::Divide what is NULL");
	warning("pointer::Divide got called which is weird");

	if(where == this || !where){
		debug("pointer::Divide where == this");
		value.signedlonglong /= what->value.signedlonglong;
	}else{
		debug("pointer::Divide where != this");
		new (where) pointer("", (signed long long) (value.signedlonglong / what->value.signedlonglong), size);
	}
}
void pointer::And(variable *where, variable *what){
	error_conditional(!what, "in pointer::And what is NULL");

	if(where == this || !where){
		debug("pointer::And where == this");
		value.signedlonglong -= ~(what->value.signedlonglong);
	}else{
		debug("pointer::And where != this");
		new (where) pointer("", (signed long long) (value.signedlonglong - ~(what->value.signedlonglong)), size);
	}
}
void pointer::Or(variable *where, variable *what){
	error_conditional(!what, "in pointer::Or what is NULL");

	if(where == this || !where){
		debug("pointer::Or where == this");
		value.signedlonglong += what->value.signedlonglong;
	}else{
		debug("pointer::Or where != this");
		new (where) pointer("", (signed long long) (value.signedlonglong + what->value.signedlonglong), size);
	}
}
void pointer::Xor(variable *where, variable *what){
	error_conditional(!what, "in pointer::Xor what is NULL");

	if(where == this || !where){
		debug("pointer::Xor where == this");
		value.signedlonglong ^= what->value.signedlonglong;
	}else{
		debug("pointer::Xor where != this");
		new (where) pointer("", (signed long long) (value.signedlonglong ^ what->value.signedlonglong), size);
	}
}

void pointer::Inc(variable *where){
	debug("pointer::Inc");
	if(where == this || !where){
		debug("pointer::Inc where == this");
		value.signedlonglong++;
	}else{
		debug("pointer::Inc where != this");
		new (where) pointer("",  (value.signedlonglong) + 1, size);
	}
}

void pointer::Dec(variable *where){
	debug("pointer::Dec");
	if(where == this || !where){
		debug("pointer::Dec where == this");
		value.signedlonglong--;
	}else{
		debug("pointer::Dec where != this");
		new (where) pointer("", (value.signedlonglong) - 1,size);
	}
}
void pointer::Neg(variable *where){
	debug("pointer::Neg");
	if(where == this || !where){
		debug("pointer::Dec where == this");
		value.signedlonglong = ~value.signedlonglong;
	}else{
		debug("pointer::Dec where != this");
		new (where) pointer("", ~value.signedlonglong,size);
	}
}

void pointer::Equal(variable *what){
	debug("pointer::Equal");
	error_conditional(!what, "in pointer::Equal what is NULL");

	value.signedlonglong = what->value.signedlonglong;
}
