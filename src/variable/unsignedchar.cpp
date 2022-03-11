#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>

unsignedchar::unsignedchar(const std::string &s,unsigned char v) : variable(s){
	type = variable::unsignedchar;
	size = sizeof(unsigned char);
	value.unsignedchar = v;
	debug("creating an unsignedchar");
}

unsignedchar::unsignedchar(const variable *v) : variable(v->name) {
	debug("constructing unsignedchar from variable");
	size = sizeof(unsigned char);
	type = variable::unsignedchar;
	value.unsignedchar = v->value.unsignedchar;
}

unsignedchar::~unsignedchar(){
	debug("destructing unsignedchar object");
}

void unsignedchar::And(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::And what is NULL");

	if(where == this || !where){
		debug("unsignedchar::And where == this");
		value.unsignedchar &= what->value.unsignedchar;
	}else{
		debug("unsignedchar::And where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar & what->value.unsignedchar));
	}
}
void unsignedchar::Or(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Or what is NULL");

	if(where == this || !where){
		debug("unsignedchar::Or where == this");
		value.unsignedchar |= what->value.unsignedchar;
	}else{
		debug("unsignedchar::Or where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar | what->value.unsignedchar));
	}
}
void unsignedchar::Xor(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Xor what is NULL");

	if(where == this || !where){
		debug("unsignedchar::Xor where == this");
		value.unsignedchar ^= what->value.unsignedchar;
	}else{
		debug("unsignedchar::Xor where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar ^ what->value.unsignedchar));
	}
}

void unsignedchar::Neg(variable *where){
	debug("unsignedchar::Neg");
	if(where == this || !where){
		debug("unsignedchar::Dec where == this");
		value.unsignedchar = ~value.unsignedchar;
	}else{
		debug("unsignedchar::Dec where != this");
		new (where) unsignedchar("", ~value.unsignedchar);
	}
}

void unsignedchar::Equal(variable *what){
	debug("unsignedchar::Equal");
	error_conditional(!what, "in unsignedchar::Equal what is NULL");

	value.unsignedchar = what->value.unsignedchar;
}
#include <new>
#include <float.h>
#include <cmath>
#include <limits.h>

void check_plus_overflow(unsigned char v1,unsigned char v2, unsigned char &where){ // returns 0 if no overflow
	if(v1 + v2 < v1 || v1 + v2 < v2){
		where = UCHAR_MAX;
		return;
	}
	where = v1 + v2;
}

void check_mul_overflow(unsigned char v1,unsigned char v2,unsigned char &where){ 
	if(v1 > 0 && v2 > 0 && (v1 * v2 < v1 || v1 * v2 < v2)){
		where = UCHAR_MAX;
		return;
	}
	where = v1 * v2;
}

void check_divide_overflow(unsigned char v1, unsigned char v2, unsigned char &where){
	if(v2 < 1 && v1 >= 1 && (v1 / v2) < v1){
		where = UCHAR_MAX;
		return;
	}
	where = v1 / v2;
}

void check_minus_overflow(unsigned char v1, unsigned char v2, unsigned char &where){
	if(v2 > v1){
		where = 0;
		return;
	}
	where = v1 - v2;
}



void unsignedchar::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Plus what is NULL");

	unsigned char new_value;
	check_plus_overflow(value.unsignedchar, what->value.unsignedchar, new_value);

	if(where == this || !where){
		debug("unsignedchar::Plus where == this");
		
		value.unsignedchar = new_value;
	}else{
		debug("unsignedchar::Plus where != this");
		new (where) unsignedchar("",  new_value);
	}
}

void unsignedchar::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Minus what is NULL");

	unsigned char new_value;
	check_minus_overflow(value.unsignedchar, what->value.unsignedchar, new_value);

	if(where == this || !where){
		debug("unsignedchar::Plus where == this");
		
		value.unsignedchar = new_value;
	}else{
		debug("unsignedchar::Plus where != this");
		new (where) unsignedchar("",  new_value);
	}
}

void unsignedchar::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Times what is NULL");

	unsigned char new_value;
	check_mul_overflow(value.unsignedchar, what->value.unsignedchar, new_value);

	if(where == this || !where){
		debug("unsignedchar::Plus where == this");
		
		value.unsignedchar = new_value;
	}else{
		debug("unsignedchar::Plus where != this");
		new (where) unsignedchar("",  new_value);
	}
}

void unsignedchar::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Divide what is NULL");

	unsigned char new_value;
	check_divide_overflow(value.unsignedchar, what->value.unsignedchar, new_value);

	if(where == this || !where){
		debug("unsignedchar::Plus where == this");
		
		value.unsignedchar = new_value;
	}else{
		debug("unsignedchar::Plus where != this");
		new (where) unsignedchar("",  new_value);
	}
}

void unsignedchar::Inc(variable *where){
	debug("unsignedchar::Inc");
	if(where == this || !where){
		debug("unsignedchar::Inc where == this");
		if(value.unsignedchar != UCHAR_MAX)
			value.unsignedchar++;
	}else{
		debug("unsignedchar::Inc where != this");
		if(value.unsignedchar != UCHAR_MAX)
			new (where) unsignedchar("",  (value.unsignedchar) + 1);
		else
			new (where) unsignedchar("",  (value.unsignedchar));
	}
}
void unsignedchar::Dec(variable *where){
	debug("unsignedchar::Dec");
	if(where == this || !where){
		debug("unsignedchar::Dec where == this");
		if(value.unsignedchar != 0)
			value.unsignedchar--;
	}else{
		debug("unsignedchar::Dec where != this");
		if(value.unsignedchar != 0)
			new (where) unsignedchar("",  (value.unsignedchar) - 1);
		else
			new (where) unsignedchar("",  (value.unsignedchar));
	}
}


