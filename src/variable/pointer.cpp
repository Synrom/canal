#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>


pointer::pointer(const std::string &s, unsigned long long c, unsigned int si): variable(s){
	debug("constructing pointer");
	size = si;
	value.unsignedlonglong = c;
	type = variable::pointer;
}

pointer::pointer(const variable *cpy) : variable(cpy->name) {
	debug("constructing pointer from variable");
	size = cpy->size;
	type = variable::pointer;
	value.unsignedlonglong = cpy->unsignedlonglong;
}

