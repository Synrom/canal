#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>
#include <float.h>
#include <cmath>

void check_plus_overflow(long double v1,long double v2, long double &where){ // returns 0 if no overflow
	if(v1 > 0 && v2 > 0 && (v1 + v2 < v1 || v1 + v2 < v2)){
		where = LDBL_MAX;
		return;
	}
	if(v1 < 0 && v2 < 0 && (v1 + v2 > v1 || v1 + v2 > v2)){
		where = LDBL_MIN;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(long double v1,long double v2,long double &where){ 
	if(v1 > 0 && v2 > 0 && (std::abs(v1 * v2) < std::abs(v1) || std::abs(v1 * v2) < std::abs(v2))){
		where = LDBL_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(long double v1, long double v2, long double &where){
	if(v2 < 1 && v2 > -1 && (v1 > 1 || v1 < -1) && (std::abs(v1 / v2) < std::abs(v1))){
		where = LDBL_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(long double v1, long double v2, long double &where){
	if(v1 < 0 && v2 > 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = LDBL_MIN;
		return;
	}
	if(v1 > 0 && v2 < 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = LDBL_MAX;
		return;
	}
	where = v1 - v2;
}

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

	long double new_value;
	check_plus_overflow(value.longdouble, what->value.longdouble, new_value);

	if(where == this || !where){
		debug("longdouble::Plus where == this");
		value.longdouble = new_value;
	}else{
		new (where) longdouble("", new_value);
	}
}

void longdouble::Minus(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Minus what is NULL");

	long double new_value;
	check_minus_overflow(value.longdouble, what->value.longdouble, new_value);

	if(where == this || !where){
		debug("longdouble::Minus where == this");
		value.longdouble = new_value;
	}else{
		debug("longdouble::Minus where != this");
		new (where) longdouble("",  new_value);
	}
}
void longdouble::Times(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Times what is NULL");

	long double new_value;
	check_mul_overflow(value.longdouble, what->value.longdouble, new_value);
	
	if(where == this || !where){
		debug("longdouble::Times where == this");
		value.longdouble = new_value;
	}else{
		debug("longdouble::Times where != this");
		new (where) longdouble("", new_value);
	}
}
void longdouble::Divide(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Divide what is NULL");

	long double new_value;
	check_divide_overflow(value.longdouble, what->value.longdouble, new_value);

	if(where == this || !where){
		debug("longdouble::Divide where == this");
		value.longdouble = new_value;
	}else{
		debug("longdouble::Divide where != this");
		new (where) longdouble("", new_value);
	}
}
void longdouble::And(variable *where, variable *what){
	error_conditional(!what, "in longdouble::And what is NULL");
	warning("calling long double::And which is really weird");

	if(where == this || !where){
		debug("longdouble::And where == this");
	}else{
		debug("longdouble::And where != this");
		new (where) longdouble("", (long double) (value.longdouble));
	}
}
void longdouble::Or(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Or what is NULL");
	warning("calling long double::Or which is really weird");

	if(where == this || !where){
		debug("longdouble::Or where == this");
	}else{
		debug("longdouble::Or where != this");
		new (where) longdouble("", (long double) (value.longdouble));
	}
}
void longdouble::Xor(variable *where, variable *what){
	error_conditional(!what, "in longdouble::Xor what is NULL");
	warning("calling long double::Xor which is really weird");

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
		if(value.longdouble != LDBL_MAX)
			value.longdouble++;
	}else{
		debug("longdouble::Inc where != this");
		if(value.longdouble != LDBL_MAX)
			new (where) longdouble("", (long double) (value.longdouble) + 1);
		else
			new (where) longdouble("", (long double) (value.longdouble));
	}
}
void longdouble::Dec(variable *where){
	debug("longdouble::Dec");
	if(where == this || !where){
		debug("longdouble::Dec where == this");
		if(value.longdouble != LDBL_MIN)
			value.longdouble--;
	}else{
		debug("longdouble::Dec where != this");
		if(value.longdouble != LDBL_MIN)
			new (where) longdouble("", (long double) (value.longdouble) - 1);
		else
			new (where) longdouble("", (long double) (value.longdouble));
	}
}

void longdouble::Neg(variable *where){
	warning("calling long double::Neg which is really weird");
	debug("longdouble::Neg");
	if(where == this || !where){
		debug("longdouble::Dec where == this");
	}else{
		debug("longdouble::Dec where != this");
		new (where) longdouble("", (long double) (value.longdouble));
	}
}

void longdouble::Equal(variable *what){
	debug("longdouble::Equal");
	error_conditional(!what, "in longdouble::Equal what is NULL");

	value.longdouble = what->value.longdouble;
}

