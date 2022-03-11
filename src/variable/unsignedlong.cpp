#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedlong::unsignedlong(const std::string &s,unsigned long v) : variable(s){
	type = variable::unsignedlong;
	size = sizeof(unsigned long);
	value.unsignedlong = v;
	debug("creating an unsignedlong");
}

unsignedlong::unsignedlong(const variable *v) : variable(v->name) {
	debug("constructing unsignedlong from variable");
	size = sizeof(unsigned long);
	type = variable::unsignedlong;
	value.unsignedlong = v->value.unsignedlong;
}

unsignedlong::~unsignedlong(){
	debug("destructing unsignedlong object");
}

void unsignedlong::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::And what is NULL");

	if(where == this || !where){
		debug("unsignedlong::And where == this");
		value.unsignedlong &= what->value.unsignedlong;
	}else{
		debug("unsignedlong::And where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong & what->value.unsignedlong));
	}
}
void unsignedlong::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Or what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Or where == this");
		value.unsignedlong |= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Or where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong | what->value.unsignedlong));
	}
}
void unsignedlong::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedlong::Xor where == this");
		value.unsignedlong ^= what->value.unsignedlong;
	}else{
		debug("unsignedlong::Xor where != this");
		new (where) unsignedlong("", (unsigned long) (value.unsignedlong ^ what->value.unsignedlong));
	}
}

void unsignedlong::Neg(variable *where){
	debug("unsignedlong::Neg");
	if(where == this || !where){
		debug("unsignedlong::Dec where == this");
		value.unsignedlong = ~value.unsignedlong;
	}else{
		debug("unsignedlong::Dec where != this");
		new (where) unsignedlong("", ~value.unsignedlong);
	}
}

void unsignedlong::Equal(variable *what){
	debug("unsignedlong::Equal");
	error_conditional(!what, "in unsignedlong::Equal what is NULL");

	value.unsignedlong = what->value.unsignedlong;
}
#include <new>
#include <float.h>
#include <cmath>
#include <limits.h>

void check_plus_overflow(unsigned long v1,unsigned long v2, unsigned long &where){ // returns 0 if no overflow
	if(v1 + v2 < v1 || v1 + v2 < v2){
		where = ULONG_MAX;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(unsigned long v1,unsigned long v2,unsigned long &where){ 
	if(v1 > 0 && v2 > 0 && (v1 * v2 < v1 || v1 * v2 < v2)){
		where = ULONG_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(unsigned long v1, unsigned long v2, unsigned long &where){
	if(v2 < 1 && v1 >= 1 && (v1 / v2) < v1){
		where = ULONG_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(unsigned long v1, unsigned long v2, unsigned long &where){
	if(v2 > v1){
		where = 0;
		return;
	}
	where = v1 - v2;
}



void unsignedlong::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Plus what is NULL");

	unsigned long new_value;
	check_plus_overflow(value.unsignedlong, what->value.unsignedlong, new_value);

	if(where == this || !where){
		debug("unsignedlong::Plus where == this");
		
		value.unsignedlong = new_value;
	}else{
		debug("unsignedlong::Plus where != this");
		new (where) unsignedlong("",  new_value);
	}
}

void unsignedlong::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Minus what is NULL");

	unsigned long new_value;
	check_minus_overflow(value.unsignedlong, what->value.unsignedlong, new_value);

	if(where == this || !where){
		debug("unsignedlong::Plus where == this");
		
		value.unsignedlong = new_value;
	}else{
		debug("unsignedlong::Plus where != this");
		new (where) unsignedlong("",  new_value);
	}
}

void unsignedlong::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Times what is NULL");

	unsigned long new_value;
	check_mul_overflow(value.unsignedlong, what->value.unsignedlong, new_value);

	if(where == this || !where){
		debug("unsignedlong::Plus where == this");
		
		value.unsignedlong = new_value;
	}else{
		debug("unsignedlong::Plus where != this");
		new (where) unsignedlong("",  new_value);
	}
}

void unsignedlong::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedlong::Divide what is NULL");

	unsigned long new_value;
	check_divide_overflow(value.unsignedlong, what->value.unsignedlong, new_value);

	if(where == this || !where){
		debug("unsignedlong::Plus where == this");
		
		value.unsignedlong = new_value;
	}else{
		debug("unsignedlong::Plus where != this");
		new (where) unsignedlong("",  new_value);
	}
}

void unsignedlong::Inc(variable *where){
	debug("unsignedlong::Inc");
	if(where == this || !where){
		debug("unsignedlong::Inc where == this");
		if(value.unsignedlong != ULONG_MAX)
			value.unsignedlong++;
	}else{
		debug("unsignedlong::Inc where != this");
		if(value.unsignedlong != ULONG_MAX)
			new (where) unsignedlong("",  (value.unsignedlong) + 1);
		else
			new (where) unsignedlong("",  (value.unsignedlong));
	}
}
void unsignedlong::Dec(variable *where){
	debug("unsignedlong::Dec");
	if(where == this || !where){
		debug("unsignedlong::Dec where == this");
		if(value.unsignedlong != 0)
			value.unsignedlong--;
	}else{
		debug("unsignedlong::Dec where != this");
		if(value.unsignedlong != 0)
			new (where) unsignedlong("",  (value.unsignedlong) - 1);
		else
			new (where) unsignedlong("",  (value.unsignedlong));
	}
}


