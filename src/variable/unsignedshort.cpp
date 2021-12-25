#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

unsignedshort::unsignedshort(const std::string &s,unsigned short v) : variable(s){
	type = variable::unsignedshort;
	size = sizeof(unsigned short);
	value.unsignedshort = v;
	debug("creating an unsignedshort");
}

unsignedshort::unsignedshort(const variable *v) : variable(v->name) {
	debug("constructing unsignedshort from variable");
	size = sizeof(unsigned short);
	type = variable::unsignedshort;
	value.unsignedshort = v->value.unsignedshort;
}

