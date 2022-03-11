#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedlong::signedlong(const std::string &s,signed long v) : variable(s){
	type = variable::signedlong;
	size = sizeof(signed long);
	value.signedlong = v;
	debug("creating an signedlong");
}

signedlong::signedlong(const variable *v) : variable(v->name) {
	debug("constructing signedlong from variable");
	size = sizeof(signed long);
	type = variable::signedlong;
	value.signedlong = v->value.signedlong;
}

signedlong::~signedlong(){
	debug("destructing signedlong object");
}

void signedlong::And(variable *where, variable *what){
	error_conditional(!what, "in signedlong::And what is NULL");

	if(where == this || !where){
		debug("signedlong::And where == this");
		value.signedlong &= what->value.signedlong;
	}else{
		debug("signedlong::And where != this");
		new (where) signedlong("", (signed long) (value.signedlong & what->value.signedlong));
	}
}
void signedlong::Or(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Or what is NULL");

	if(where == this || !where){
		debug("signedlong::Or where == this");
		value.signedlong |= what->value.signedlong;
	}else{
		debug("signedlong::Or where != this");
		new (where) signedlong("", (signed long) (value.signedlong | what->value.signedlong));
	}
}
void signedlong::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Xor what is NULL");

	if(where == this || !where){
		debug("signedlong::Xor where == this");
		value.signedlong ^= what->value.signedlong;
	}else{
		debug("signedlong::Xor where != this");
		new (where) signedlong("", (signed long) (value.signedlong ^ what->value.signedlong));
	}
}

void signedlong::Neg(variable *where){
	debug("signedlong::Neg");
	if(where == this || !where){
		debug("signedlong::Dec where == this");
		value.signedlong = ~value.signedlong;
	}else{
		debug("signedlong::Dec where != this");
		new (where) signedlong("", ~value.signedlong);
	}
}

void signedlong::Equal(variable *what){
	debug("signedlong::Equal");
	error_conditional(!what, "in signedlong::Equal what is NULL");

	value.signedlong = what->value.signedlong;
}

#include <float.h>
#include <cmath>
#include <limits.h>


void check_plus_overflow(signed long v1,signed long v2, signed long &where){ // returns 0 if no overflow
	if(v1 > 0 && v2 > 0 && (v1 + v2 < v1 || v1 + v2 < v2)){
		where = LONG_MAX;
		return;
	}
	if(v1 < 0 && v2 < 0 && (v1 + v2 > v1 || v1 + v2 > v2)){
		where = LONG_MIN;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(signed long v1,signed long v2,signed long &where){ 
	if(v1 > 0 && v2 > 0 && (std::abs(v1 * v2) < std::abs(v1) || std::abs(v1 * v2) < std::abs(v2))){
		where = LONG_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(signed long v1, signed long v2, signed long &where){
	if(v2 < 1 && v2 > -1 && (v1 >= 1 || v1 <= -1) && (std::abs(v1 / v2) < std::abs(v1))){
		where = LONG_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(signed long v1, signed long v2, signed long &where){
	if(v1 < 0 && v2 > 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = LONG_MIN;
		return;
	}
	if(v1 > 0 && v2 < 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = LONG_MAX;
		return;
	}
	where = v1 - v2;
}




void signedlong::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Plus what is NULL");

	signed long new_value;
	check_plus_overflow(value.signedlong, what->value.signedlong, new_value);

	if(where == this || !where){
		debug("signedlong::Plus where == this");
		value.signedlong = new_value;
	}else{
		new (where) signedlong("", new_value);
	}
}

void signedlong::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Minus what is NULL");

	signed long new_value;
	check_minus_overflow(value.signedlong, what->value.signedlong, new_value);

	if(where == this || !where){
		debug("signedlong::Minus where == this");
		value.signedlong = new_value;
	}else{
		debug("signedlong::Minus where != this");
		new (where) signedlong("",  new_value);
	}
}
void signedlong::Times(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Times what is NULL");

	signed long new_value;
	check_mul_overflow(value.signedlong, what->value.signedlong, new_value);
	
	if(where == this || !where){
		debug("signedlong::Times where == this");
		value.signedlong = new_value;
	}else{
		debug("signedlong::Times where != this");
		new (where) signedlong("", new_value);
	}
}
void signedlong::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedlong::Divide what is NULL");

	signed long new_value;
	check_divide_overflow(value.signedlong, what->value.signedlong, new_value);

	if(where == this || !where){
		debug("signedlong::Divide where == this");
		value.signedlong = new_value;
	}else{
		debug("signedlong::Divide where != this");
		new (where) signedlong("", new_value);
	}
}
void signedlong::Inc(variable *where){
	debug("signedlong::Inc");
	if(where == this || !where){
		debug("signedlong::Inc where == this");
		if(value.signedlong != LONG_MAX)
			value.signedlong++;
	}else{
		debug("signedlong::Inc where != this");
		if(value.signedlong != LONG_MAX)
			new (where) signedlong("", (signed long) (value.signedlong) + 1);
		else
			new (where) signedlong("", (signed long) (value.signedlong));
	}
}
void signedlong::Dec(variable *where){
	debug("signedlong::Dec");
	if(where == this || !where){
		debug("signedlong::Dec where == this");
		if(value.signedlong != LONG_MIN)
			value.signedlong--;
	}else{
		debug("signedlong::Dec where != this");
		if(value.signedlong != LONG_MIN)
			new (where) signedlong("", (signed long) (value.signedlong) - 1);
		else
			new (where) signedlong("", (signed long) (value.signedlong));
	}
}


