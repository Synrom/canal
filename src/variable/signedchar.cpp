#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>
#include <float.h>
#include <cmath>
#include <limits.h>

signedchar::signedchar(const std::string &s,signed char v) : variable(s){
	type = variable::signedchar;
	size = sizeof(signed char);
	value.signedchar = v;
	debug("creating an signedchar");
}

signedchar::signedchar(const variable *v) : variable(v->name) {
	debug("constructing signedchar from variable");
	size = sizeof(signed char);
	type = variable::signedchar;
	value.signedchar = v->value.signedchar;
}

signedchar::~signedchar(){
	debug("destructing signedchar object");
}

void signedchar::And(variable *where, variable *what){
	error_conditional(!what, "in signedchar::And what is NULL");

	if(where == this || !where){
		debug("signedchar::And where == this");
		value.signedchar &= what->value.signedchar;
	}else{
		debug("signedchar::And where != this");
		new (where) signedchar("", (signed char) (value.signedchar & what->value.signedchar));
	}
}
void signedchar::Or(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Or what is NULL");

	if(where == this || !where){
		debug("signedchar::Or where == this");
		value.signedchar |= what->value.signedchar;
	}else{
		debug("signedchar::Or where != this");
		new (where) signedchar("", (signed char) (value.signedchar | what->value.signedchar));
	}
}
void signedchar::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Xor what is NULL");

	if(where == this || !where){
		debug("signedchar::Xor where == this");
		value.signedchar ^= what->value.signedchar;
	}else{
		debug("signedchar::Xor where != this");
		new (where) signedchar("", (signed char) (value.signedchar ^ what->value.signedchar));
	}
}

void signedchar::Neg(variable *where){
	debug("signedchar::Neg");
	if(where == this || !where){
		debug("signedchar::Dec where == this");
		value.signedchar = ~value.signedchar;
	}else{
		debug("signedchar::Dec where != this");
		new (where) signedchar("", ~value.signedchar);
	}
}

void signedchar::Equal(variable *what){
	debug("signedchar::Equal");
	error_conditional(!what, "in signedchar::Equal what is NULL");

	value.signedchar = what->value.signedchar;
}


void check_plus_overflow(signed char v1,signed char v2, signed char &where){ // returns 0 if no overflow
	if(v1 > 0 && v2 > 0 && (v1 + v2 < v1 || v1 + v2 < v2)){
		where = SCHAR_MAX;
		return;
	}
	if(v1 < 0 && v2 < 0 && (v1 + v2 > v1 || v1 + v2 > v2)){
		where = SCHAR_MIN;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(signed char v1,signed char v2,signed char &where){ 
	if(v1 > 0 && v2 > 0 && (std::abs(v1 * v2) < std::abs(v1) || std::abs(v1 * v2) < std::abs(v2))){
		where = SCHAR_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(signed char v1, signed char v2, signed char &where){
	if(v2 < 1 && v2 > -1 && (v1 >= 1 || v1 <= -1) && (std::abs(v1 / v2) < std::abs(v1))){
		where = SCHAR_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(signed char v1, signed char v2, signed char &where){
	if(v1 < 0 && v2 > 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = SCHAR_MIN;
		return;
	}
	if(v1 > 0 && v2 < 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = SCHAR_MAX;
		return;
	}
	where = v1 - v2;
}




void signedchar::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Plus what is NULL");

	signed char new_value;
	check_plus_overflow(value.signedchar, what->value.signedchar, new_value);

	if(where == this || !where){
		debug("signedchar::Plus where == this");
		value.signedchar = new_value;
	}else{
		new (where) signedchar("", new_value);
	}
}

void signedchar::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Minus what is NULL");

	signed char new_value;
	check_minus_overflow(value.signedchar, what->value.signedchar, new_value);

	if(where == this || !where){
		debug("signedchar::Minus where == this");
		value.signedchar = new_value;
	}else{
		debug("signedchar::Minus where != this");
		new (where) signedchar("",  new_value);
	}
}
void signedchar::Times(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Times what is NULL");

	signed char new_value;
	check_mul_overflow(value.signedchar, what->value.signedchar, new_value);
	
	if(where == this || !where){
		debug("signedchar::Times where == this");
		value.signedchar = new_value;
	}else{
		debug("signedchar::Times where != this");
		new (where) signedchar("", new_value);
	}
}
void signedchar::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedchar::Divide what is NULL");

	signed char new_value;
	check_divide_overflow(value.signedchar, what->value.signedchar, new_value);

	if(where == this || !where){
		debug("signedchar::Divide where == this");
		value.signedchar = new_value;
	}else{
		debug("signedchar::Divide where != this");
		new (where) signedchar("", new_value);
	}
}
void signedchar::Inc(variable *where){
	debug("signedchar::Inc");
	if(where == this || !where){
		debug("signedchar::Inc where == this");
		if(value.signedchar != SCHAR_MAX)
			value.signedchar++;
	}else{
		debug("signedchar::Inc where != this");
		if(value.signedchar != SCHAR_MAX)
			new (where) signedchar("", (signed char) (value.signedchar) + 1);
		else
			new (where) signedchar("", (signed char) (value.signedchar));
	}
}
void signedchar::Dec(variable *where){
	debug("signedchar::Dec");
	if(where == this || !where){
		debug("signedchar::Dec where == this");
		if(value.signedchar != SCHAR_MIN)
			value.signedchar--;
	}else{
		debug("signedchar::Dec where != this");
		if(value.signedchar != SCHAR_MIN)
			new (where) signedchar("", (signed char) (value.signedchar) - 1);
		else
			new (where) signedchar("", (signed char) (value.signedchar));
	}
}


