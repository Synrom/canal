#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedlonglong::unsignedlonglong(const std::string &s,unsigned long long v) : variable(s){
	type = variable::unsignedlonglong;
	size = sizeof(unsigned long long);
	value.unsignedlonglong = v;
	debug("creating an unsignedlonglong");
}

unsignedlonglong::unsignedlonglong(const variable *v) : variable(v->name) {
	debug("constructing unsignedlonglong from variable");
	size = sizeof(unsigned long long);
	type = variable::unsignedlonglong;
	value.unsignedlonglong = v->value.unsignedlonglong;
}

unsignedlonglong::~unsignedlonglong(){
	debug("destructing unsignedlonglong object");
}

void unsignedlonglong::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::And what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::And where == this");
		value.unsignedlonglong &= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::And where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong & what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Or what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Or where == this");
		value.unsignedlonglong |= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Or where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong | what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedlonglong::Xor where == this");
		value.unsignedlonglong ^= what->value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Xor where != this");
		new (where) unsignedlonglong("", (unsigned long long) (value.unsignedlonglong ^ what->value.unsignedlonglong));
	}
}
void unsignedlonglong::Neg(variable *where){
	debug("unsignedlonglong::Neg");
	if(where == this || !where){
		debug("unsignedlonglong::Dec where == this");
		value.unsignedlonglong = ~value.unsignedlonglong;
	}else{
		debug("unsignedlonglong::Dec where != this");
		new (where) unsignedlonglong("", ~value.unsignedlonglong);
	}
}

void unsignedlonglong::Equal(variable *what){
	debug("unsignedlonglong::Equal");
	error_conditional(!what, "in unsignedlonglong::Equal what is NULL");

	value.unsignedlonglong = what->value.unsignedlonglong;
}

#include <new>
#include <float.h>
#include <cmath>
#include <limits.h>

void check_plus_overflow(unsigned long long v1,unsigned long long v2, unsigned long long &where){ // returns 0 if no overflow
	if(v1 + v2 < v1 || v1 + v2 < v2){
		where = ULLONG_MAX;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(unsigned long long v1,unsigned long long v2,unsigned long long &where){ 
	if(v1 > 0 && v2 > 0 && (v1 * v2 < v1 || v1 * v2 < v2)){
		where = ULLONG_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(unsigned long long v1, unsigned long long v2, unsigned long long &where){
	if(v2 < 1 && v1 >= 1 && (v1 / v2) < v1){
		where = ULLONG_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(unsigned long long v1, unsigned long long v2, unsigned long long &where){
	if(v2 > v1){
		where = 0;
		return;
	}
	where = v1 - v2;
}



void unsignedlonglong::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Plus what is NULL");

	unsigned long long new_value;
	check_plus_overflow(value.unsignedlonglong, what->value.unsignedlonglong, new_value);

	if(where == this || !where){
		debug("unsignedlonglong::Plus where == this");
		
		value.unsignedlonglong = new_value;
	}else{
		debug("unsignedlonglong::Plus where != this");
		new (where) unsignedlonglong("",  new_value);
	}
}

void unsignedlonglong::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Minus what is NULL");

	unsigned long long new_value;
	check_minus_overflow(value.unsignedlonglong, what->value.unsignedlonglong, new_value);

	if(where == this || !where){
		debug("unsignedlonglong::Plus where == this");
		
		value.unsignedlonglong = new_value;
	}else{
		debug("unsignedlonglong::Plus where != this");
		new (where) unsignedlonglong("",  new_value);
	}
}

void unsignedlonglong::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Times what is NULL");

	unsigned long long new_value;
	check_mul_overflow(value.unsignedlonglong, what->value.unsignedlonglong, new_value);

	if(where == this || !where){
		debug("unsignedlonglong::Plus where == this");
		
		value.unsignedlonglong = new_value;
	}else{
		debug("unsignedlonglong::Plus where != this");
		new (where) unsignedlonglong("",  new_value);
	}
}

void unsignedlonglong::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedlonglong::Divide what is NULL");

	unsigned long long new_value;
	check_divide_overflow(value.unsignedlonglong, what->value.unsignedlonglong, new_value);

	if(where == this || !where){
		debug("unsignedlonglong::Plus where == this");
		
		value.unsignedlonglong = new_value;
	}else{
		debug("unsignedlonglong::Plus where != this");
		new (where) unsignedlonglong("",  new_value);
	}
}

void unsignedlonglong::Inc(variable *where){
	debug("unsignedlonglong::Inc");
	if(where == this || !where){
		debug("unsignedlonglong::Inc where == this");
		if(value.unsignedlonglong != ULLONG_MAX)
			value.unsignedlonglong++;
	}else{
		debug("unsignedlonglong::Inc where != this");
		if(value.unsignedlonglong != ULLONG_MAX)
			new (where) unsignedlonglong("",  (value.unsignedlonglong) + 1);
		else
			new (where) unsignedlonglong("",  (value.unsignedlonglong));
	}
}
void unsignedlonglong::Dec(variable *where){
	debug("unsignedlonglong::Dec");
	if(where == this || !where){
		debug("unsignedlonglong::Dec where == this");
		if(value.unsignedlonglong != 0)
			value.unsignedlonglong--;
	}else{
		debug("unsignedlonglong::Dec where != this");
		if(value.unsignedlonglong != 0)
			new (where) unsignedlonglong("",  (value.unsignedlonglong) - 1);
		else
			new (where) unsignedlonglong("",  (value.unsignedlonglong));
	}
}


