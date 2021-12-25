#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>


variable::variable(const std::string &s) : name(s){
	debug("constructing variable");
}

variable::~variable(){
	debug("destructing variable");
}
