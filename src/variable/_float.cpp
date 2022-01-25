#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

_float::_float(const std::string &s,float v) : variable(s){
	type = variable::_float;
	size = sizeof(float);
	value._float = v;
	debug("creating an _float");
}

_float::_float(const variable *v) : variable(v->name) {
	debug("constructing _float from variable");
	size = sizeof(float);
	type = variable::_float;
	value._float = v->value._float;
}

_float::~_float(){
	debug("destructing _float object");
}

void _float::Plus(variable *where, variable *what){
	error_conditional(!what, "in _float::Plus what is NULL");

	if(where == this || !where){
		debug("_float::Plus where == this");
		value._float += what->value._float;
	}else{
		debug("_float::Plus where != this");
		new (where) _float("", (float) (value._float + what->value._float));
	}
}
void _float::Minus(variable *where, variable *what){
	error_conditional(!what, "in _float::Minus what is NULL");

	if(where == this || !where){
		debug("_float::Minus where == this");
		value._float -= what->value._float;
	}else{
		debug("_float::Minus where != this");
		new (where) _float("", (float) (value._float - what->value._float));
	}
}
void _float::Times(variable *where, variable *what){
	error_conditional(!what, "in _float::Times what is NULL");

	if(where == this || !where){
		debug("_float::Times where == this");
		value._float *= what->value._float;
	}else{
		debug("_float::Times where != this");
		new (where) _float("", (float) (value._float * what->value._float));
	}
}
void _float::Divide(variable *where, variable *what){
	error_conditional(!what, "in _float::Divide what is NULL");

	if(where == this || !where){
		debug("_float::Divide where == this");
		value._float /= what->value._float;
	}else{
		debug("_float::Divide where != this");
		new (where) _float("", (float) (value._float / what->value._float));
	}
}
void _float::And(variable *where, variable *what){
	error_conditional(!what, "in _float::And what is NULL");
	warning("calling float::And which is really weird");

	if(where == this || !where){
		debug("_float::And where == this");
	}else{
		debug("_float::And where != this");
		new (where) _float("", (float) (value._float));
	}
}
void _float::Or(variable *where, variable *what){
	error_conditional(!what, "in _float::Or what is NULL");
	warning("calling float::Or which is really weird");

	if(where == this || !where){
		debug("_float::Or where == this");
	}else{
		debug("_float::Or where != this");
		new (where) _float("", (float) (value._float));
	}
}
void _float::Xor(variable *where, variable *what){
	error_conditional(!what, "in _float::Xor what is NULL");
	warning("calling float::Xor which is really weird");

	if(where == this || !where){
		debug("_float::Xor where == this");
	}else{
		debug("_float::Xor where != this");
		new (where) _float("", (float) (value._float));
	}
}
void _float::Inc(){
	debug("_float::Inc");
	value._float++;
}
void _float::Dec(){
	debug("_float::Dec");
	value._float--;
}
void _float::Neg(variable *where){
	debug("_float::Neg");
	error_conditional(!where, "in _float::Neg where is NULL");
	warning("calling float::Neg which is really weird");

	new (where) _float("", (float) (value._float));
}

void _float::Equal(variable *what){
	debug("_float::Equal");
	error_conditional(!what, "in _float::Equal what is NULL");

	value._float = what->value._float;
}
