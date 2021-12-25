#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

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

