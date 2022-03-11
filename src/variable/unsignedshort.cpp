#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedshort::unsignedshort(const std::string &s,unsigned short v) : variable(s){
	type = variable::unsignedshort;
	size = sizeof(unsigned short);
	value.unsignedshort = v;
	debug("creating an unsignedshort");
}

unsignedshort::unsignedshort(const variable *v) : variable(v->name) {
	debug("constructing unsignedshort from variable");
	size = sizeof(unsigned short);
	type = variable::unsignedshort;
	value.unsignedshort = v->value.unsignedshort;
}

unsignedshort::~unsignedshort(){
	debug("destructing unsignedshort object");
}

void unsignedshort::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::And what is NULL");

	if(where == this || !where){
		debug("unsignedshort::And where == this");
		value.unsignedshort &= what->value.unsignedshort;
	}else{
		debug("unsignedshort::And where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort & what->value.unsignedshort));
	}
}
void unsignedshort::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Or what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Or where == this");
		value.unsignedshort |= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Or where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort | what->value.unsignedshort));
	}
}
void unsignedshort::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedshort::Xor where == this");
		value.unsignedshort ^= what->value.unsignedshort;
	}else{
		debug("unsignedshort::Xor where != this");
		new (where) unsignedshort("", (unsigned short) (value.unsignedshort ^ what->value.unsignedshort));
	}
}

void unsignedshort::Neg(variable *where){
	debug("unsignedshort::Neg");
	if(where == this || !where){
		debug("unsignedshort::Dec where == this");
		value.unsignedshort = ~value.unsignedshort;
	}else{
		debug("unsignedshort::Dec where != this");
		new (where) unsignedshort("", ~value.unsignedshort);
	}
}

void unsignedshort::Equal(variable *what){
	debug("unsignedshort::Equal");
	error_conditional(!what, "in unsignedshort::Equal what is NULL");

	value.unsignedshort = what->value.unsignedshort;
}
#include <new>
#include <float.h>
#include <cmath>
#include <limits.h>

void check_plus_overflow(unsigned short v1,unsigned short v2, unsigned short &where){ // returns 0 if no overflow
	if(v1 + v2 < v1 || v1 + v2 < v2){
		where = USHRT_MAX;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(unsigned short v1,unsigned short v2,unsigned short &where){ 
	if(v1 > 0 && v2 > 0 && (v1 * v2 < v1 || v1 * v2 < v2)){
		where = USHRT_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(unsigned short v1, unsigned short v2, unsigned short &where){
	if(v2 < 1 && v1 >= 1 && (v1 / v2) < v1){
		where = USHRT_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(unsigned short v1, unsigned short v2, unsigned short &where){
	if(v2 > v1){
		where = 0;
		return;
	}
	where = v1 - v2;
}



void unsignedshort::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Plus what is NULL");

	unsigned short new_value;
	check_plus_overflow(value.unsignedshort, what->value.unsignedshort, new_value);

	if(where == this || !where){
		debug("unsignedshort::Plus where == this");
		
		value.unsignedshort = new_value;
	}else{
		debug("unsignedshort::Plus where != this");
		new (where) unsignedshort("",  new_value);
	}
}

void unsignedshort::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Minus what is NULL");

	unsigned short new_value;
	check_minus_overflow(value.unsignedshort, what->value.unsignedshort, new_value);

	if(where == this || !where){
		debug("unsignedshort::Plus where == this");
		
		value.unsignedshort = new_value;
	}else{
		debug("unsignedshort::Plus where != this");
		new (where) unsignedshort("",  new_value);
	}
}

void unsignedshort::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Times what is NULL");

	unsigned short new_value;
	check_mul_overflow(value.unsignedshort, what->value.unsignedshort, new_value);

	if(where == this || !where){
		debug("unsignedshort::Plus where == this");
		
		value.unsignedshort = new_value;
	}else{
		debug("unsignedshort::Plus where != this");
		new (where) unsignedshort("",  new_value);
	}
}

void unsignedshort::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedshort::Divide what is NULL");

	unsigned short new_value;
	check_divide_overflow(value.unsignedshort, what->value.unsignedshort, new_value);

	if(where == this || !where){
		debug("unsignedshort::Plus where == this");
		
		value.unsignedshort = new_value;
	}else{
		debug("unsignedshort::Plus where != this");
		new (where) unsignedshort("",  new_value);
	}
}

void unsignedshort::Inc(variable *where){
	debug("unsignedshort::Inc");
	if(where == this || !where){
		debug("unsignedshort::Inc where == this");
		if(value.unsignedshort != USHRT_MAX)
			value.unsignedshort++;
	}else{
		debug("unsignedshort::Inc where != this");
		if(value.unsignedshort != USHRT_MAX)
			new (where) unsignedshort("",  (value.unsignedshort) + 1);
		else
			new (where) unsignedshort("",  (value.unsignedshort));
	}
}
void unsignedshort::Dec(variable *where){
	debug("unsignedshort::Dec");
	if(where == this || !where){
		debug("unsignedshort::Dec where == this");
		if(value.unsignedshort != 0)
			value.unsignedshort--;
	}else{
		debug("unsignedshort::Dec where != this");
		if(value.unsignedshort != 0)
			new (where) unsignedshort("",  (value.unsignedshort) - 1);
		else
			new (where) unsignedshort("",  (value.unsignedshort));
	}
}


