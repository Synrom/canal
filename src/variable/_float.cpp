#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>
#include <float.h>
#include <cmath>

void check_plus_overflow(float v1,float v2, float &where){ // returns 0 if no overflow
	if(v1 + v2 < v1 || v1 + v2 < v2){
		where = FLT_MAX;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(float v1,float v2,float &where){ 
	if(v1 > 0 && v2 > 0 && (v1 * v2 < v1 || v1 * v2 < v2)){
		where = FLT_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(float v1, float v2, float &where){
	if(v2 < 1 && v1 >= 1 && (v1 / v2) < v1){
		where = FLT_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(float v1, float v2, float &where){
	if(v2 > v1){
		where = FLT_MIN;
		return;
	}
	where = v1 - v2;
}

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

	float new_value;
	check_plus_overflow(value._float, what->value._float, new_value);

	if(where == this || !where){
		debug("_float::Plus where == this");
		
		value._float = new_value;
	}else{
		debug("_float::Plus where != this");
		new (where) _float("",  new_value);
	}
}

void _float::Minus(variable *where, variable *what){
	error_conditional(!what, "in _float::Minus what is NULL");

	float new_value;
	check_minus_overflow(value._float, what->value._float, new_value);

	if(where == this || !where){
		debug("_float::Plus where == this");
		
		value._float = new_value;
	}else{
		debug("_float::Plus where != this");
		new (where) _float("",  new_value);
	}
}

void _float::Times(variable *where, variable *what){
	error_conditional(!what, "in _float::Times what is NULL");

	float new_value;
	check_mul_overflow(value._float, what->value._float, new_value);

	if(where == this || !where){
		debug("_float::Plus where == this");
		
		value._float = new_value;
	}else{
		debug("_float::Plus where != this");
		new (where) _float("",  new_value);
	}
}

void _float::Divide(variable *where, variable *what){
	error_conditional(!what, "in _float::Divide what is NULL");

	float new_value;
	check_divide_overflow(value._float, what->value._float, new_value);

	if(where == this || !where){
		debug("_float::Plus where == this");
		
		value._float = new_value;
	}else{
		debug("_float::Plus where != this");
		new (where) _float("",  new_value);
	}
}
void _float::And(variable *where, variable *what){
	error_conditional(!what, "in _float::And what is NULL");
	warning("calling double::And which is really weird");

	if(where == this || !where){
		debug("_float::And where == this");
	}else{
		debug("_float::And where != this");
		new (where) _float("",  (value._float));
	}
}
void _float::Or(variable *where, variable *what){
	error_conditional(!what, "in _float::Or what is NULL");
	warning("calling double::Or which is really weird");

	if(where == this || !where){
		debug("_float::Or where == this");
	}else{
		debug("_float::Or where != this");
		new (where) _float("",  (value._float));
	}
}
void _float::Xor(variable *where, variable *what){
	error_conditional(!what, "in _float::Xor what is NULL");
	warning("calling double::Xor which is really weird");

	if(where == this || !where){
		debug("_float::Xor where == this");
	}else{
		debug("_float::Xor where != this");
		new (where) _float("",  (value._float));
	}
}
void _float::Inc(variable *where){
	debug("_float::Inc");
	if(where == this || !where){
		debug("_float::Inc where == this");
		if(value._float != FLT_MAX)
			value._float++;
	}else{
		debug("_float::Inc where != this");
		if(value._float != FLT_MAX)
			new (where) _float("",  (value._float) + 1);
		else
			new (where) _float("",  (value._float));
	}
}
void _float::Dec(variable *where){
	debug("_float::Dec");
	if(where == this || !where){
		debug("_float::Dec where == this");
		if(value._float != FLT_MIN)
			value._float--;
	}else{
		debug("_float::Dec where != this");
		if(value._float != FLT_MIN)
			new (where) _float("",  (value._float) - 1);
		else
			new (where) _float("",  (value._float));
	}
}

void _float::Neg(variable *where){
	warning("calling double::Neg which is really weird");
	debug("_float::Neg");
	if(where == this || !where){
		debug("_float::Dec where == this");
	}else{
		debug("_float::Dec where != this");
		new (where) _float("",  (value._float));
	}
}

void _float::Equal(variable *what){
	debug("_float::Equal");
	error_conditional(!what, "in _float::Equal what is NULL");

	value._float = what->value._float;
}

