#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>

unsignedlonglong::unsignedlonglong(const std::string &s,unsigned long long v) : variable(s){
	type = variable::unsignedlonglong;
	size = sizeof(unsigned long long);
	value.unsignedlonglong = v;
	debug("creating an unsignedlonglong");
}

unsignedlonglong::unsignedlonglong(const variable *v) : variable(v->name) {
	debug("constructing unsignedlonglong from variable");
	size = sizeof(unsigned long long);
	type = variable::unsignedlonglong;
	value.unsignedlonglong = v->value.unsignedlonglong;
}

