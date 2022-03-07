#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedint::unsignedint(const std::string &s,unsigned int v) : variable(s){
	type = variable::unsignedint;
	size = sizeof(unsigned int);
	value.unsignedint = v;
	debug("creating an unsignedint");
}

unsignedint::unsignedint(const variable *v) : variable(v->name) {
	debug("constructing unsignedint from variable");
	size = sizeof(unsigned int);
	type = variable::unsignedint;
	value.unsignedint = v->value.unsignedint;
}

unsignedint::~unsignedint(){
	debug("destructing unsignedint object");
}

void unsignedint::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Plus what is NULL");

	if(where == this || !where){
		debug("unsignedint::Plus where == this");
		value.unsignedint += what->value.unsignedint;
	}else{
		debug("unsignedint::Plus where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint + what->value.unsignedint));
	}
}
void unsignedint::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Minus what is NULL");

	if(where == this || !where){
		debug("unsignedint::Minus where == this");
		value.unsignedint -= what->value.unsignedint;
	}else{
		debug("unsignedint::Minus where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint - what->value.unsignedint));
	}
}
void unsignedint::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Times what is NULL");

	if(where == this || !where){
		debug("unsignedint::Times where == this");
		value.unsignedint *= what->value.unsignedint;
	}else{
		debug("unsignedint::Times where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint * what->value.unsignedint));
	}
}
void unsignedint::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Divide what is NULL");

	if(where == this || !where){
		debug("unsignedint::Divide where == this");
		value.unsignedint /= what->value.unsignedint;
	}else{
		debug("unsignedint::Divide where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint / what->value.unsignedint));
	}
}
void unsignedint::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::And what is NULL");

	if(where == this || !where){
		debug("unsignedint::And where == this");
		value.unsignedint &= what->value.unsignedint;
	}else{
		debug("unsignedint::And where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint & what->value.unsignedint));
	}
}
void unsignedint::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Or what is NULL");

	if(where == this || !where){
		debug("unsignedint::Or where == this");
		value.unsignedint |= what->value.unsignedint;
	}else{
		debug("unsignedint::Or where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint | what->value.unsignedint));
	}
}
void unsignedint::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedint::Xor where == this");
		value.unsignedint ^= what->value.unsignedint;
	}else{
		debug("unsignedint::Xor where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint ^ what->value.unsignedint));
	}
}
void unsignedint::Inc(variable *where){
	debug("unsignedint::Inc");
	if(where == this || !where){
		debug("unsignedint::Inc where == this");
		value.unsignedint++;
	}else{
		debug("unsignedint::Inc where != this");
		new (where) unsignedint("",  value.unsignedint + 1);
	}
}

void unsignedint::Dec(variable *where){
	debug("unsignedint::Dec");
	if(where == this || !where){
		debug("unsignedint::Dec where == this");
		value.unsignedint--;
	}else{
		debug("unsignedint::Dec where != this");
		new (where) unsignedint("", value.unsignedint - 1);
	}
}
void unsignedint::Neg(variable *where){
	debug("unsignedint::Neg");
	if(where == this || !where){
		debug("unsignedint::Dec where == this");
		value.unsignedint = ~value.unsignedint;
	}else{
		debug("unsignedint::Dec where != this");
		new (where) unsignedint("", ~value.unsignedint);
	}
}

void unsignedint::Equal(variable *what){
	debug("unsignedint::Equal");
	error_conditional(!what, "in unsignedint::Equal what is NULL");

	value.unsignedint = what->value.unsignedint;
}
