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

void unsignedchar::Plus(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Plus what is NULL");

	if(where == this || !where){
		debug("unsignedchar::Plus where == this");
		value.unsignedchar += what->value.unsignedchar;
	}else{
		debug("unsignedchar::Plus where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar + what->value.unsignedchar));
	}
}
void unsignedchar::Minus(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Minus what is NULL");

	if(where == this || !where){
		debug("unsignedchar::Minus where == this");
		value.unsignedchar -= what->value.unsignedchar;
	}else{
		debug("unsignedchar::Minus where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar - what->value.unsignedchar));
	}
}
void unsignedchar::Times(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Times what is NULL");

	if(where == this || !where){
		debug("unsignedchar::Times where == this");
		value.unsignedchar *= what->value.unsignedchar;
	}else{
		debug("unsignedchar::Times where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar * what->value.unsignedchar));
	}
}
void unsignedchar::Divide(variable *where, variable *what){
	error_conditional(!what, "in unsignedchar::Divide what is NULL");

	if(where == this || !where){
		debug("unsignedchar::Divide where == this");
		value.unsignedchar /= what->value.unsignedchar;
	}else{
		debug("unsignedchar::Divide where != this");
		new (where) unsignedchar("", (unsigned char) (value.unsignedchar / what->value.unsignedchar));
	}
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
void unsignedchar::Inc(variable *where){
	debug("unsignedchar::Inc");
	if(where == this || !where){
		debug("unsignedchar::Inc where == this");
		value.unsignedchar++;
	}else{
		debug("unsignedchar::Inc where != this");
		new (where) unsignedchar("",  (value.unsignedchar) + 1);
	}
}

void unsignedchar::Dec(variable *where){
	debug("unsignedchar::Dec");
	if(where == this || !where){
		debug("unsignedchar::Dec where == this");
		value.unsignedchar--;
	}else{
		debug("unsignedchar::Dec where != this");
		new (where) unsignedchar("", (value.unsignedchar) - 1);
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
