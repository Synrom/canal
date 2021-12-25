#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

_double::_double(const std::string &s,double v) : variable(s){
	type = variable::_double;
	size = sizeof(double);
	value._double = v;
	debug("creating an _double");
}

_double::_double(const variable *v) : variable(v->name) {
	debug("constructing _double from variable");
	size = sizeof(double);
	type = variable::_double;
	value._double = v->value._double;
}

