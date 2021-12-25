#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

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

