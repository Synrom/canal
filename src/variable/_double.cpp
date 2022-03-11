#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>
#include <float.h>
#include <cmath>

void check_plus_overflow(double v1,double v2, double &where){ // returns 0 if no overflow
	if(v1 > 0 && v2 > 0 && (v1 + v2 < v1 || v1 + v2 < v2)){
		where = DBL_MAX;
		return;
	}
	if(v1 < 0 && v2 < 0 && (v1 + v2 > v1 || v1 + v2 > v2)){
		where = DBL_MIN;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(double v1,double v2,double &where){ 
	if(v1 > 0 && v2 > 0 && (std::abs(v1 * v2) < std::abs(v1) || std::abs(v1 * v2) < std::abs(v2))){
		where = DBL_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(double v1, double v2, double &where){
	if(v2 < 1 && v2 > -1 && (v1 >= 1 || v1 <= -1) && (std::abs(v1 / v2) < std::abs(v1))){
		where = DBL_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(double v1, double v2, double &where){
	if(v1 < 0 && v2 > 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = DBL_MIN;
		return;
	}
	if(v1 > 0 && v2 < 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = DBL_MAX;
		return;
	}
	where = v1 - v2;
}

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

	double new_value;
	check_plus_overflow(value._double, what->value._double, new_value);

	if(where == this || !where){
		debug("_double::Plus where == this");
		value._double = new_value;
	}else{
		new (where) _double("", new_value);
	}
}

void _double::Minus(variable *where, variable *what){
	error_conditional(!what, "in _double::Minus what is NULL");

	double new_value;
	check_minus_overflow(value._double, what->value._double, new_value);

	if(where == this || !where){
		debug("_double::Minus where == this");
		value._double = new_value;
	}else{
		debug("_double::Minus where != this");
		new (where) _double("",  new_value);
	}
}
void _double::Times(variable *where, variable *what){
	error_conditional(!what, "in _double::Times what is NULL");

	double new_value;
	check_mul_overflow(value._double, what->value._double, new_value);
	
	if(where == this || !where){
		debug("_double::Times where == this");
		value._double = new_value;
	}else{
		debug("_double::Times where != this");
		new (where) _double("", new_value);
	}
}
void _double::Divide(variable *where, variable *what){
	error_conditional(!what, "in _double::Divide what is NULL");

	double new_value;
	check_divide_overflow(value._double, what->value._double, new_value);

	if(where == this || !where){
		debug("_double::Divide where == this");
		value._double = new_value;
	}else{
		debug("_double::Divide where != this");
		new (where) _double("", new_value);
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
void _double::Inc(variable *where){
	debug("_double::Inc");
	if(where == this || !where){
		debug("_double::Inc where == this");
		if(value._double != DBL_MAX)
			value._double++;
	}else{
		debug("_double::Inc where != this");
		if(value._double != DBL_MAX)
			new (where) _double("", (double) (value._double) + 1);
		else
			new (where) _double("", (double) (value._double));
	}
}
void _double::Dec(variable *where){
	debug("_double::Dec");
	if(where == this || !where){
		debug("_double::Dec where == this");
		if(value._double != DBL_MIN)
			value._double--;
	}else{
		debug("_double::Dec where != this");
		if(value._double != DBL_MIN)
			new (where) _double("", (double) (value._double) - 1);
		else
			new (where) _double("", (double) (value._double));
	}
}

void _double::Neg(variable *where){
	warning("calling double::Neg which is really weird");
	debug("_double::Neg");
	if(where == this || !where){
		debug("_double::Dec where == this");
	}else{
		debug("_double::Dec where != this");
		new (where) _double("", (double) (value._double));
	}
}

void _double::Equal(variable *what){
	debug("_double::Equal");
	error_conditional(!what, "in _double::Equal what is NULL");

	value._double = what->value._double;
}

