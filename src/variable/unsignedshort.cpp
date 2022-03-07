#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedshort::unsignedshort(const std::string &s,unsigned short v) : variable(s){
	type = variable::unsignedshort;
	size = sizeof(unsigned short);
	value.unsignedshort = v;
	debug("creating an unsignedshort");
}

unsignedshort::unsignedshort(const variable *v) : variable(v->name) {
	debug("constructing unsignedshort from variable");
	size = sizeof(unsigned short);
	type = variable::unsignedshort;
	value.unsignedshort = v->value.unsignedshort;
}

unsignedshort::~unsignedshort(){
	debug("destructing unsignedshort object");
}

void unsignedshort::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Plus what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Plus where == this");
		value.unsignedshort += what->value.unsignedshort;
	}else{
		debug("unsignedshort::Plus where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort + what->value.unsignedshort));
	}
}
void unsignedshort::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Minus what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Minus where == this");
		value.unsignedshort -= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Minus where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort - what->value.unsignedshort));
	}
}
void unsignedshort::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Times what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Times where == this");
		value.unsignedshort *= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Times where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort * what->value.unsignedshort));
	}
}
void unsignedshort::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Divide what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Divide where == this");
		value.unsignedshort /= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Divide where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort / what->value.unsignedshort));
	}
}
void unsignedshort::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::And what is NULL");

	if(where == this || !where){
		debug("unsignedshort::And where == this");
		value.unsignedshort &= what->value.unsignedshort;
	}else{
		debug("unsignedshort::And where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort & what->value.unsignedshort));
	}
}
void unsignedshort::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Or what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Or where == this");
		value.unsignedshort |= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Or where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort | what->value.unsignedshort));
	}
}
void unsignedshort::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Xor where == this");
		value.unsignedshort ^= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Xor where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort ^ what->value.unsignedshort));
	}
}
void unsignedshort::Inc(variable *where){
	debug("unsignedshort::Inc");
	if(where == this || !where){
		debug("unsignedshort::Inc where == this");
		value.unsignedshort++;
	}else{
		debug("unsignedshort::Inc where != this");
		new (where) unsignedshort("", (double) (value.unsignedshort) + 1);
	}
}

void unsignedshort::Dec(variable *where){
	debug("unsignedshort::Dec");
	if(where == this || !where){
		debug("unsignedshort::Dec where == this");
		value.unsignedshort--;
	}else{
		debug("unsignedshort::Dec where != this");
		new (where) unsignedshort("", (double) (value.unsignedshort) - 1);
	}
}
void unsignedshort::Neg(variable *where){
	debug("unsignedshort::Neg");
	if(where == this || !where){
		debug("unsignedshort::Dec where == this");
		value.unsignedshort = ~value.unsignedshort;
	}else{
		debug("unsignedshort::Dec where != this");
		new (where) unsignedshort("", ~value.unsignedshort);
	}
}

void unsignedshort::Equal(variable *what){
	debug("unsignedshort::Equal");
	error_conditional(!what, "in unsignedshort::Equal what is NULL");

	value.unsignedshort = what->value.unsignedshort;
}
