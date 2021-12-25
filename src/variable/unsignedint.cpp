#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

unsignedint::unsignedint(const std::string &s,unsigned int v) : variable(s){
	type = variable::unsignedint;
	size = sizeof(unsigned int);
	value.unsignedint = v;
	debug("creating an unsignedint");
}

unsignedint::unsignedint(const variable *v) : variable(v->name) {
	debug("constructing unsignedint from variable");
	size = sizeof(unsigned int);
	type = variable::unsignedint;
	value.unsignedint = v->value.unsignedint;
}

