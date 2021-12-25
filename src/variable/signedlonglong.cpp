#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

signedlonglong::signedlonglong(const std::string &s,signed long long v) : variable(s){
	type = variable::signedlonglong;
	size = sizeof(signed long long);
	value.signedlonglong = v;
	debug("creating an signedlonglong");
}

signedlonglong::signedlonglong(const variable *v) : variable(v->name) {
	debug("constructing signedlonglong from variable");
	size = sizeof(signed long long);
	type = variable::signedlonglong;
	value.signedlonglong = v->value.signedlonglong;
}

