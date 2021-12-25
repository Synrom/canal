#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

longdouble::longdouble(const std::string &s,long double v) : variable(s){
	type = variable::longdouble;
	size = sizeof(long double);
	value.longdouble = v;
	debug("creating an longdouble");
}

longdouble::longdouble(const variable *v) : variable(v->name) {
	debug("constructing longdouble from variable");
	size = sizeof(long double);
	type = variable::longdouble;
	value.longdouble = v->value.longdouble;
}

