#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedint::signedint(const std::string &s,signed int v) : variable(s){
	type = variable::signedint;
	size = sizeof(signed int);
	value.signedint = v;
	debug("creating an signedint");
}

signedint::signedint(const variable *v) : variable(v->name) {
	debug("constructing signedint from variable");
	size = sizeof(signed int);
	type = variable::signedint;
	value.signedint = v->value.signedint;
}

signedint::~signedint(){
	debug("destructing signedint object");
}

void signedint::And(variable *where, variable *what){
	error_conditional(!what, "in signedint::And what is NULL");

	if(where == this || !where){
		debug("signedint::And where == this");
		value.signedint &= what->value.signedint;
	}else{
		debug("signedint::And where != this");
		new (where) signedint("", (signed int) (value.signedint & what->value.signedint));
	}
}
void signedint::Or(variable *where, variable *what){
	error_conditional(!what, "in signedint::Or what is NULL");

	if(where == this || !where){
		debug("signedint::Or where == this");
		value.signedint |= what->value.signedint;
	}else{
		debug("signedint::Or where != this");
		new (where) signedint("", (signed int) (value.signedint | what->value.signedint));
	}
}
void signedint::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedint::Xor what is NULL");

	if(where == this || !where){
		debug("signedint::Xor where == this");
		value.signedint ^= what->value.signedint;
	}else{
		debug("signedint::Xor where != this");
		new (where) signedint("", (signed int) (value.signedint ^ what->value.signedint));
	}
}
void signedint::Neg(variable *where){
	debug("signedint::Neg");
	if(where == this || !where){
		debug("signedint::Dec where == this");
		value.signedint = ~value.signedint;
	}else{
		debug("signedint::Dec where != this");
		new (where) signedint("", ~value.signedint);
	}
}

void signedint::Equal(variable *what){
	debug("signedint::Equal");
	error_conditional(!what, "in signedint::Equal what is NULL");

	value.signedint = what->value.signedint;
}
#include <float.h>
#include <cmath>
#include <limits.h>


void check_plus_overflow(signed int v1,signed int v2, signed int &where){ // returns 0 if no overflow
	if(v1 > 0 && v2 > 0 && (v1 + v2 < v1 || v1 + v2 < v2)){
		where = INT_MAX;
		return;
	}
	if(v1 < 0 && v2 < 0 && (v1 + v2 > v1 || v1 + v2 > v2)){
		where = INT_MIN;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(signed int v1,signed int v2,signed int &where){ 
	if(v1 > 0 && v2 > 0 && (std::abs(v1 * v2) < std::abs(v1) || std::abs(v1 * v2) < std::abs(v2))){
		where = INT_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(signed int v1, signed int v2, signed int &where){
	if(v2 < 1 && v2 > -1 && (v1 >= 1 || v1 <= -1) && (std::abs(v1 / v2) < std::abs(v1))){
		where = INT_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(signed int v1, signed int v2, signed int &where){
	if(v1 < 0 && v2 > 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = INT_MIN;
		return;
	}
	if(v1 > 0 && v2 < 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = INT_MAX;
		return;
	}
	where = v1 - v2;
}




void signedint::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedint::Plus what is NULL");

	signed int new_value;
	check_plus_overflow(value.signedint, what->value.signedint, new_value);

	if(where == this || !where){
		debug("signedint::Plus where == this");
		value.signedint = new_value;
	}else{
		new (where) signedint("", new_value);
	}
}

void signedint::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedint::Minus what is NULL");

	signed int new_value;
	check_minus_overflow(value.signedint, what->value.signedint, new_value);

	if(where == this || !where){
		debug("signedint::Minus where == this");
		value.signedint = new_value;
	}else{
		debug("signedint::Minus where != this");
		new (where) signedint("",  new_value);
	}
}
void signedint::Times(variable *where, variable *what){
	error_conditional(!what, "in signedint::Times what is NULL");

	signed int new_value;
	check_mul_overflow(value.signedint, what->value.signedint, new_value);
	
	if(where == this || !where){
		debug("signedint::Times where == this");
		value.signedint = new_value;
	}else{
		debug("signedint::Times where != this");
		new (where) signedint("", new_value);
	}
}
void signedint::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedint::Divide what is NULL");

	signed int new_value;
	check_divide_overflow(value.signedint, what->value.signedint, new_value);

	if(where == this || !where){
		debug("signedint::Divide where == this");
		value.signedint = new_value;
	}else{
		debug("signedint::Divide where != this");
		new (where) signedint("", new_value);
	}
}
void signedint::Inc(variable *where){
	debug("signedint::Inc");
	if(where == this || !where){
		debug("signedint::Inc where == this");
		if(value.signedint != INT_MAX)
			value.signedint++;
	}else{
		debug("signedint::Inc where != this");
		if(value.signedint != INT_MAX)
			new (where) signedint("", (signed int) (value.signedint) + 1);
		else
			new (where) signedint("", (signed int) (value.signedint));
	}
}
void signedint::Dec(variable *where){
	debug("signedint::Dec");
	if(where == this || !where){
		debug("signedint::Dec where == this");
		if(value.signedint != INT_MIN)
			value.signedint--;
	}else{
		debug("signedint::Dec where != this");
		if(value.signedint != INT_MIN)
			new (where) signedint("", (signed int) (value.signedint) - 1);
		else
			new (where) signedint("", (signed int) (value.signedint));
	}
}


