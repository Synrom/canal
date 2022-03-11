#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedint::unsignedint(const std::string &s,unsigned int v) : variable(s){
	type = variable::unsignedint;
	size = sizeof(unsigned int);
	value.unsignedint = v;
	debug("creating an unsignedint");
}

unsignedint::unsignedint(const variable *v) : variable(v->name) {
	debug("constructing unsignedint from variable");
	size = sizeof(unsigned int);
	type = variable::unsignedint;
	value.unsignedint = v->value.unsignedint;
}

unsignedint::~unsignedint(){
	debug("destructing unsignedint object");
}

void unsignedint::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::And what is NULL");

	if(where == this || !where){
		debug("unsignedint::And where == this");
		value.unsignedint &= what->value.unsignedint;
	}else{
		debug("unsignedint::And where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint & what->value.unsignedint));
	}
}
void unsignedint::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Or what is NULL");

	if(where == this || !where){
		debug("unsignedint::Or where == this");
		value.unsignedint |= what->value.unsignedint;
	}else{
		debug("unsignedint::Or where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint | what->value.unsignedint));
	}
}
void unsignedint::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedint::Xor where == this");
		value.unsignedint ^= what->value.unsignedint;
	}else{
		debug("unsignedint::Xor where != this");
		new (where) unsignedint("", (unsigned int) (value.unsignedint ^ what->value.unsignedint));
	}
}
void unsignedint::Neg(variable *where){
	debug("unsignedint::Neg");
	if(where == this || !where){
		debug("unsignedint::Dec where == this");
		value.unsignedint = ~value.unsignedint;
	}else{
		debug("unsignedint::Dec where != this");
		new (where) unsignedint("", ~value.unsignedint);
	}
}

void unsignedint::Equal(variable *what){
	debug("unsignedint::Equal");
	error_conditional(!what, "in unsignedint::Equal what is NULL");

	value.unsignedint = what->value.unsignedint;
}

#include <new>
#include <float.h>
#include <cmath>
#include <limits.h>

void check_plus_overflow(unsigned int v1,unsigned int v2, unsigned int &where){ // returns 0 if no overflow
	if(v1 + v2 < v1 || v1 + v2 < v2){
		where = UINT_MAX;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(unsigned int v1,unsigned int v2,unsigned int &where){ 
	if(v1 > 0 && v2 > 0 && (v1 * v2 < v1 || v1 * v2 < v2)){
		where = UINT_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(unsigned int v1, unsigned int v2, unsigned int &where){
	if(v2 < 1 && v1 >= 1 && (v1 / v2) < v1){
		where = UINT_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(unsigned int v1, unsigned int v2, unsigned int &where){
	if(v2 > v1){
		where = 0;
		return;
	}
	where = v1 - v2;
}



void unsignedint::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Plus what is NULL");

	unsigned int new_value;
	check_plus_overflow(value.unsignedint, what->value.unsignedint, new_value);

	if(where == this || !where){
		debug("unsignedint::Plus where == this");
		
		value.unsignedint = new_value;
	}else{
		debug("unsignedint::Plus where != this");
		new (where) unsignedint("",  new_value);
	}
}

void unsignedint::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Minus what is NULL");

	unsigned int new_value;
	check_minus_overflow(value.unsignedint, what->value.unsignedint, new_value);

	if(where == this || !where){
		debug("unsignedint::Plus where == this");
		
		value.unsignedint = new_value;
	}else{
		debug("unsignedint::Plus where != this");
		new (where) unsignedint("",  new_value);
	}
}

void unsignedint::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Times what is NULL");

	unsigned int new_value;
	check_mul_overflow(value.unsignedint, what->value.unsignedint, new_value);

	if(where == this || !where){
		debug("unsignedint::Plus where == this");
		
		value.unsignedint = new_value;
	}else{
		debug("unsignedint::Plus where != this");
		new (where) unsignedint("",  new_value);
	}
}

void unsignedint::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedint::Divide what is NULL");

	unsigned int new_value;
	check_divide_overflow(value.unsignedint, what->value.unsignedint, new_value);

	if(where == this || !where){
		debug("unsignedint::Plus where == this");
		
		value.unsignedint = new_value;
	}else{
		debug("unsignedint::Plus where != this");
		new (where) unsignedint("",  new_value);
	}
}

void unsignedint::Inc(variable *where){
	debug("unsignedint::Inc");
	if(where == this || !where){
		debug("unsignedint::Inc where == this");
		if(value.unsignedint != UINT_MAX)
			value.unsignedint++;
	}else{
		debug("unsignedint::Inc where != this");
		if(value.unsignedint != UINT_MAX)
			new (where) unsignedint("",  (value.unsignedint) + 1);
		else
			new (where) unsignedint("",  (value.unsignedint));
	}
}
void unsignedint::Dec(variable *where){
	debug("unsignedint::Dec");
	if(where == this || !where){
		debug("unsignedint::Dec where == this");
		if(value.unsignedint != 0)
			value.unsignedint--;
	}else{
		debug("unsignedint::Dec where != this");
		if(value.unsignedint != 0)
			new (where) unsignedint("",  (value.unsignedint) - 1);
		else
			new (where) unsignedint("",  (value.unsignedint));
	}
}


