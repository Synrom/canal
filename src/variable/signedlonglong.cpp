#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedlonglong::signedlonglong(const std::string &s,signed long long v) : variable(s){
	type = variable::signedlonglong;
	size = sizeof(signed long long);
	value.signedlonglong = v;
	debug("creating an signedlonglong");
}

signedlonglong::signedlonglong(const variable *v) : variable(v->name) {
	debug("constructing signedlonglong from variable");
	size = sizeof(signed long long);
	type = variable::signedlonglong;
	value.signedlonglong = v->value.signedlonglong;
}

signedlonglong::~signedlonglong(){
	debug("destructing signedlonglong object");
}

void signedlonglong::And(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::And what is NULL");

	if(where == this || !where){
		debug("signedlonglong::And where == this");
		value.signedlonglong &= what->value.signedlonglong;
	}else{
		debug("signedlonglong::And where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong & what->value.signedlonglong));
	}
}
void signedlonglong::Or(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Or what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Or where == this");
		value.signedlonglong |= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Or where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong | what->value.signedlonglong));
	}
}
void signedlonglong::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Xor what is NULL");

	if(where == this || !where){
		debug("signedlonglong::Xor where == this");
		value.signedlonglong ^= what->value.signedlonglong;
	}else{
		debug("signedlonglong::Xor where != this");
		new (where) signedlonglong("", (signed long long) (value.signedlonglong ^ what->value.signedlonglong));
	}
}

void signedlonglong::Neg(variable *where){
	debug("signedlonglong::Neg");
	if(where == this || !where){
		debug("signedlonglong::Dec where == this");
		value.signedlonglong = ~value.signedlonglong;
	}else{
		debug("signedlonglong::Dec where != this");
		new (where) signedlonglong("", ~value.signedlonglong);
	}
}

void signedlonglong::Equal(variable *what){
	debug("signedlonglong::Equal");
	error_conditional(!what, "in signedlonglong::Equal what is NULL");

	value.signedlonglong = what->value.signedlonglong;
}

#include <float.h>
#include <cmath>
#include <limits.h>


void check_plus_overflow(signed long long v1,signed long long v2, signed long long &where){ // returns 0 if no overflow
	if(v1 > 0 && v2 > 0 && (v1 + v2 < v1 || v1 + v2 < v2)){
		where = LLONG_MAX;
		return;
	}
	if(v1 < 0 && v2 < 0 && (v1 + v2 > v1 || v1 + v2 > v2)){
		where = LLONG_MIN;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(signed long long v1,signed long long v2,signed long long &where){ 
	if(v1 > 0 && v2 > 0 && (std::abs(v1 * v2) < std::abs(v1) || std::abs(v1 * v2) < std::abs(v2))){
		where = LLONG_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(signed long long v1, signed long long v2, signed long long &where){
	if(v2 < 1 && v2 > -1 && (v1 >= 1 || v1 <= -1) && (std::abs(v1 / v2) < std::abs(v1))){
		where = LLONG_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(signed long long v1, signed long long v2, signed long long &where){
	if(v1 < 0 && v2 > 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = LLONG_MIN;
		return;
	}
	if(v1 > 0 && v2 < 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = LLONG_MAX;
		return;
	}
	where = v1 - v2;
}




void signedlonglong::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Plus what is NULL");

	signed long long new_value;
	check_plus_overflow(value.signedlonglong, what->value.signedlonglong, new_value);

	if(where == this || !where){
		debug("signedlonglong::Plus where == this");
		value.signedlonglong = new_value;
	}else{
		new (where) signedlonglong("", new_value);
	}
}

void signedlonglong::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Minus what is NULL");

	signed long long new_value;
	check_minus_overflow(value.signedlonglong, what->value.signedlonglong, new_value);

	if(where == this || !where){
		debug("signedlonglong::Minus where == this");
		value.signedlonglong = new_value;
	}else{
		debug("signedlonglong::Minus where != this");
		new (where) signedlonglong("",  new_value);
	}
}
void signedlonglong::Times(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Times what is NULL");

	signed long long new_value;
	check_mul_overflow(value.signedlonglong, what->value.signedlonglong, new_value);
	
	if(where == this || !where){
		debug("signedlonglong::Times where == this");
		value.signedlonglong = new_value;
	}else{
		debug("signedlonglong::Times where != this");
		new (where) signedlonglong("", new_value);
	}
}
void signedlonglong::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedlonglong::Divide what is NULL");

	signed long long new_value;
	check_divide_overflow(value.signedlonglong, what->value.signedlonglong, new_value);

	if(where == this || !where){
		debug("signedlonglong::Divide where == this");
		value.signedlonglong = new_value;
	}else{
		debug("signedlonglong::Divide where != this");
		new (where) signedlonglong("", new_value);
	}
}
void signedlonglong::Inc(variable *where){
	debug("signedlonglong::Inc");
	if(where == this || !where){
		debug("signedlonglong::Inc where == this");
		if(value.signedlonglong != LLONG_MAX)
			value.signedlonglong++;
	}else{
		debug("signedlonglong::Inc where != this");
		if(value.signedlonglong != LLONG_MAX)
			new (where) signedlonglong("", (signed long long) (value.signedlonglong) + 1);
		else
			new (where) signedlonglong("", (signed long long) (value.signedlonglong));
	}
}
void signedlonglong::Dec(variable *where){
	debug("signedlonglong::Dec");
	if(where == this || !where){
		debug("signedlonglong::Dec where == this");
		if(value.signedlonglong != LLONG_MIN)
			value.signedlonglong--;
	}else{
		debug("signedlonglong::Dec where != this");
		if(value.signedlonglong != LLONG_MIN)
			new (where) signedlonglong("", (signed long long) (value.signedlonglong) - 1);
		else
			new (where) signedlonglong("", (signed long long) (value.signedlonglong));
	}
}


