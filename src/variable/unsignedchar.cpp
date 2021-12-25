#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

unsignedchar::unsignedchar(const std::string &s,unsigned char v) : variable(s){
	type = variable::unsignedchar;
	size = sizeof(unsigned char);
	value.unsignedchar = v;
	debug("creating an unsignedchar");
}

unsignedchar::unsignedchar(const variable *v) : variable(v->name) {
	debug("constructing unsignedchar from variable");
	size = sizeof(unsigned char);
	type = variable::unsignedchar;
	value.unsignedchar = v->value.unsignedchar;
}

