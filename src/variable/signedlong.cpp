#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

signedlong::signedlong(const std::string &s,signed long v) : variable(s){
	type = variable::signedlong;
	size = sizeof(signed long);
	value.signedlong = v;
	debug("creating an signedlong");
}

signedlong::signedlong(const variable *v) : variable(v->name) {
	debug("constructing signedlong from variable");
	size = sizeof(signed long);
	type = variable::signedlong;
	value.signedlong = v->value.signedlong;
}

