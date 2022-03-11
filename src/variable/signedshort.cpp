#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

signedshort::signedshort(const std::string &s,signed short v) : variable(s){
	type = variable::signedshort;
	size = sizeof(signed short);
	value.signedshort = v;
	debug("creating an signedshort");
}

signedshort::signedshort(const variable *v) : variable(v->name) {
	debug("constructing signedshort from variable");
	size = sizeof(signed short);
	type = variable::signedshort;
	value.signedshort = v->value.signedshort;
}

signedshort::~signedshort(){
	debug("destructing signedshort object");
}

void signedshort::And(variable *where, variable *what){
	error_conditional(!what, "in signedshort::And what is NULL");

	if(where == this || !where){
		debug("signedshort::And where == this");
		value.signedshort &= what->value.signedshort;
	}else{
		debug("signedshort::And where != this");
		new (where) signedshort("", (signed short) (value.signedshort & what->value.signedshort));
	}
}
void signedshort::Or(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Or what is NULL");

	if(where == this || !where){
		debug("signedshort::Or where == this");
		value.signedshort |= what->value.signedshort;
	}else{
		debug("signedshort::Or where != this");
		new (where) signedshort("", (signed short) (value.signedshort | what->value.signedshort));
	}
}
void signedshort::Xor(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Xor what is NULL");

	if(where == this || !where){
		debug("signedshort::Xor where == this");
		value.signedshort ^= what->value.signedshort;
	}else{
		debug("signedshort::Xor where != this");
		new (where) signedshort("", (signed short) (value.signedshort ^ what->value.signedshort));
	}
}
void signedshort::Neg(variable *where){
	debug("signedshort::Neg");
	if(where == this || !where){
		debug("signedshort::Dec where == this");
		value.signedshort = ~value.signedshort;
	}else{
		debug("signedshort::Dec where != this");
		new (where) signedshort("", ~value.signedshort);
	}
}

void signedshort::Equal(variable *what){
	debug("signedshort::Equal");
	error_conditional(!what, "in signedshort::Equal what is NULL");

	value.signedshort = what->value.signedshort;
}
#include <float.h>
#include <cmath>
#include <limits.h>


void check_plus_overflow(signed short v1,signed short v2, signed short &where){ // returns 0 if no overflow
	if(v1 > 0 && v2 > 0 && (v1 + v2 < v1 || v1 + v2 < v2)){
		where = SHRT_MAX;
		return;
	}
	if(v1 < 0 && v2 < 0 && (v1 + v2 > v1 || v1 + v2 > v2)){
		where = SHRT_MIN;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(signed short v1,signed short v2,signed short &where){ 
	if(v1 > 0 && v2 > 0 && (std::abs(v1 * v2) < std::abs(v1) || std::abs(v1 * v2) < std::abs(v2))){
		where = SHRT_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(signed short v1, signed short v2, signed short &where){
	if(v2 < 1 && v2 > -1 && (v1 >= 1 || v1 <= -1) && (std::abs(v1 / v2) < std::abs(v1))){
		where = SHRT_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(signed short v1, signed short v2, signed short &where){
	if(v1 < 0 && v2 > 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = SHRT_MIN;
		return;
	}
	if(v1 > 0 && v2 < 0 && (std::abs(v1 - v2) < std::abs(v1) || std::abs(v1 - v2) < std::abs(v2))){
		where = SHRT_MAX;
		return;
	}
	where = v1 - v2;
}




void signedshort::Plus(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Plus what is NULL");

	signed short new_value;
	check_plus_overflow(value.signedshort, what->value.signedshort, new_value);

	if(where == this || !where){
		debug("signedshort::Plus where == this");
		value.signedshort = new_value;
	}else{
		new (where) signedshort("", new_value);
	}
}

void signedshort::Minus(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Minus what is NULL");

	signed short new_value;
	check_minus_overflow(value.signedshort, what->value.signedshort, new_value);

	if(where == this || !where){
		debug("signedshort::Minus where == this");
		value.signedshort = new_value;
	}else{
		debug("signedshort::Minus where != this");
		new (where) signedshort("",  new_value);
	}
}
void signedshort::Times(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Times what is NULL");

	signed short new_value;
	check_mul_overflow(value.signedshort, what->value.signedshort, new_value);
	
	if(where == this || !where){
		debug("signedshort::Times where == this");
		value.signedshort = new_value;
	}else{
		debug("signedshort::Times where != this");
		new (where) signedshort("", new_value);
	}
}
void signedshort::Divide(variable *where, variable *what){
	error_conditional(!what, "in signedshort::Divide what is NULL");

	signed short new_value;
	check_divide_overflow(value.signedshort, what->value.signedshort, new_value);

	if(where == this || !where){
		debug("signedshort::Divide where == this");
		value.signedshort = new_value;
	}else{
		debug("signedshort::Divide where != this");
		new (where) signedshort("", new_value);
	}
}
void signedshort::Inc(variable *where){
	debug("signedshort::Inc");
	if(where == this || !where){
		debug("signedshort::Inc where == this");
		if(value.signedshort != SHRT_MAX)
			value.signedshort++;
	}else{
		debug("signedshort::Inc where != this");
		if(value.signedshort != SHRT_MAX)
			new (where) signedshort("", (signed short) (value.signedshort) + 1);
		else
			new (where) signedshort("", (signed short) (value.signedshort));
	}
}
void signedshort::Dec(variable *where){
	debug("signedshort::Dec");
	if(where == this || !where){
		debug("signedshort::Dec where == this");
		if(value.signedshort != SHRT_MIN)
			value.signedshort--;
	}else{
		debug("signedshort::Dec where != this");
		if(value.signedshort != SHRT_MIN)
			new (where) signedshort("", (signed short) (value.signedshort) - 1);
		else
			new (where) signedshort("", (signed short) (value.signedshort));
	}
}


