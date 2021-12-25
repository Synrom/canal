#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

unsignedlong::unsignedlong(const std::string &s,unsigned long v) : variable(s){
	type = variable::unsignedlong;
	size = sizeof(unsigned long);
	value.unsignedlong = v;
	debug("creating an unsignedlong");
}

unsignedlong::unsignedlong(const variable *v) : variable(v->name) {
	debug("constructing unsignedlong from variable");
	size = sizeof(unsigned long);
	type = variable::unsignedlong;
	value.unsignedlong = v->value.unsignedlong;
}

