#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

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

