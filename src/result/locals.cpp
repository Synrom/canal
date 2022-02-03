#include <vector>

#include <canal/debugger.h>
#include <canal/result.h>

void local_stack::set_identifier(result_identifier_stack *identifier_stack){
	debug("setting identifier_stack of local_stack to %p",identifier_stack);
	identifiers = identifier_stack;
}

void local_stack::push(const std::vector<variable *> &v){
	debug("pushing variable vector of %s to local_stack",v.front()->name.c_str());
	stack.push_back(v);
	identifiers->push(result_identifier_stack::local);
}

std::vector<variable *> local_stack::pop(){
	debug("poping variable vector of %s from local_stack",stack.back().front()->name.c_str());

	std::vector<variable *> ret(std::move(stack.back()));
	stack.pop_back();
	identifiers->pop();

	return ret;
}
