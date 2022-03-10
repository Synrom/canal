#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

longdouble::longdouble(const std::string &s,long double v) : variable(s){
	type = variable::longdouble;
	size = sizeof(long double);
	value.longdouble = v;
	debug("creating an longdouble");
}

longdouble::longdouble(const variable *v) : variable(v->name) {
	debug("constructing longdouble from variable");
	size = sizeof(long double);
	type = variable::longdouble;
	value.longdouble = v->value.longdouble;
}

longdouble::~longdouble(){
	debug("destructing longdouble object");
}

void longdouble::Plus(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Plus what is NULL");

	if(where == this || !where){
		debug("longdouble::Plus where == this");
		value.longdouble += what->value.longdouble;
	}else{
		debug("longdouble::Plus where != this");
		new (where) longdouble("", (long double) (value.longdouble + what->value.longdouble));
	}
}
void longdouble::Minus(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Minus what is NULL");

	if(where == this || !where){
		debug("longdouble::Minus where == this");
		value.longdouble -= what->value.longdouble;
	}else{
		debug("longdouble::Minus where != this");
		new (where) longdouble("", (long double) (value.longdouble - what->value.longdouble));
	}
}
void longdouble::Times(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Times what is NULL");

	if(where == this || !where){
		debug("longdouble::Times where == this");
		value.longdouble *= what->value.longdouble;
	}else{
		debug("longdouble::Times where != this");
		new (where) longdouble("", (long double) (value.longdouble * what->value.longdouble));
	}
}
void longdouble::Divide(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Divide what is NULL");

	if(where == this || !where){
		debug("longdouble::Divide where == this");
		value.longdouble /= what->value.longdouble;
	}else{
		debug("longdouble::Divide where != this");
		new (where) longdouble("", (long double) (value.longdouble / what->value.longdouble));
	}
}
void longdouble::And(variable *where, variable *what){
	error_conditional(!what, "in longdouble::And what is NULL");
	warning("calling longdouble::And which is really weird");

	if(where == this || !where){
		debug("longdouble::And where == this");
	}else{
		debug("longdouble::And where != this");
		new (where) longdouble("", (long double) (value.longdouble));
	}
}
void longdouble::Or(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Or what is NULL");
	warning("calling longdouble::Or which is really weird");

	if(where == this || !where){
		debug("longdouble::Or where == this");
	}else{
		debug("longdouble::Or where != this");
		new (where) longdouble("", (long double) (value.longdouble));
	}
}
void longdouble::Xor(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Xor what is NULL");
	warning("calling longdouble::Xor which is really weird");

	if(where == this || !where){
		debug("longdouble::Xor where == this");
	}else{
		debug("longdouble::Xor where != this");
		new (where) longdouble("", (long double) (value.longdouble));
	}
}

void longdouble::Inc(variable *where){
	debug("longdouble::Inc");
	if(where == this || !where){
		debug("longdouble::Inc where == this");
		value.longdouble++;
	}else{
		debug("longdouble::Inc where != this");
		new (where) longdouble("", (value.longdouble) + 1);
	}
}

void longdouble::Dec(variable *where){
	debug("longdouble::Dec");
	if(where == this || !where){
		debug("longdouble::Dec where == this");
		value.longdouble--;
	}else{
		debug("longdouble::Dec where != this");
		new (where) longdouble("", (value.longdouble) - 1);
	}
}

void longdouble::Neg(variable *where){
	warning("calling longdouble::Neg which is really weird");
	debug("longdouble::Neg");
	if(where == this || !where){
		debug("longdouble::Dec where == this");
		value.longdouble = value.longdouble;
	}else{
		debug("longdouble::Dec where != this");
		new (where) longdouble("", value.longdouble);
	}
}

void longdouble::Equal(variable *what){
	debug("longdouble::Equal");
	error_conditional(!what, "in longdouble::Equal what is NULL");

	value.longdouble = what->value.longdouble;
}
