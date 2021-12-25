#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

_float::_float(const std::string &s,float v) : variable(s){
	type = variable::_float;
	size = sizeof(float);
	value._float = v;
	debug("creating an _float");
}

_float::_float(const variable *v) : variable(v->name) {
	debug("constructing _float from variable");
	size = sizeof(float);
	type = variable::_float;
	value._float = v->value._float;
}

