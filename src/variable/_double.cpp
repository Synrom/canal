#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

_double::_double(const std::string &s,double v) : variable(s){
	type = variable::_double;
	size = sizeof(double);
	value._double = v;
	debug("creating an _double");
}

_double::_double(const variable *v) : variable(v->name) {
	debug("constructing _double from variable");
	size = sizeof(double);
	type = variable::_double;
	value._double = v->value._double;
}

_double::~_double(){
	debug("destructing _double object");
}

void _double::Plus(variable *where, variable *what){
	error_conditional(!what, "in _double::Plus what is NULL");

	if(where == this || !where){
		debug("_double::Plus where == this");
		value._double += what->value._double;
	}else{
		debug("_double::Plus where != this");
		new (where) _double("", (double) (value._double + what->value._double));
	}
}
void _double::Minus(variable *where, variable *what){
	error_conditional(!what, "in _double::Minus what is NULL");

	if(where == this || !where){
		debug("_double::Minus where == this");
		value._double -= what->value._double;
	}else{
		debug("_double::Minus where != this");
		new (where) _double("", (double) (value._double - what->value._double));
	}
}
void _double::Times(variable *where, variable *what){
	error_conditional(!what, "in _double::Times what is NULL");

	if(where == this || !where){
		debug("_double::Times where == this");
		value._double *= what->value._double;
	}else{
		debug("_double::Times where != this");
		new (where) _double("", (double) (value._double * what->value._double));
	}
}
void _double::Divide(variable *where, variable *what){
	error_conditional(!what, "in _double::Divide what is NULL");

	if(where == this || !where){
		debug("_double::Divide where == this");
		value._double /= what->value._double;
	}else{
		debug("_double::Divide where != this");
		new (where) _double("", (double) (value._double / what->value._double));
	}
}
void _double::And(variable *where, variable *what){
	error_conditional(!what, "in _double::And what is NULL");
	warning("calling double::And which is really weird");

	if(where == this || !where){
		debug("_double::And where == this");
	}else{
		debug("_double::And where != this");
		new (where) _double("", (double) (value._double));
	}
}
void _double::Or(variable *where, variable *what){
	error_conditional(!what, "in _double::Or what is NULL");
	warning("calling double::Or which is really weird");

	if(where == this || !where){
		debug("_double::Or where == this");
	}else{
		debug("_double::Or where != this");
		new (where) _double("", (double) (value._double));
	}
}
void _double::Xor(variable *where, variable *what){
	error_conditional(!what, "in _double::Xor what is NULL");
	warning("calling double::Xor which is really weird");

	if(where == this || !where){
		debug("_double::Xor where == this");
	}else{
		debug("_double::Xor where != this");
		new (where) _double("", (double) (value._double));
	}
}
void _double::Inc(){
	debug("_double::Inc");
	value._double++;
}
void _double::Dec(){
	debug("_double::Dec");
	value._double--;
}
void _double::Neg(variable *where){
	debug("_double::Neg");
	error_conditional(!where, "in _double::Neg where is NULL");
	warning("calling double::Neg which is really weird");

	new (where) _double("", (double) (value._double));
}
