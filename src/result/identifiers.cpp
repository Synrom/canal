#include <canal/debugger.h>
#include <canal/result.h>

result_identifier_stack::result_identifier result_identifier_stack::look(){
	debug("looking up the result identifier from result_identifier_stack");
	error_conditional(stack.size() == 0, "trying to look into empty result_identifier_stack");
	return stack.back();
}

void result_identifier_stack::push(result_identifier_stack::result_identifier identifier){
	debug("pushing result identifier to result_identifier_stack");
	stack.push_back(identifier);
}

void result_identifier_stack::pop(){
	debug("poping last element from result_identifier_stack");
	stack.pop_back();
}

void result_identifier_stack::reset(){
	debug("resetting result_identifier_stack");

	while(stack.size() > 0)
		stack.pop_back();
}

void result_identifier_stack::print(){
	for(auto i = stack.begin();i < stack.end();i++){
		switch(*i){
			case result_identifier_stack::local:
				printf("local ");
				break;
			case result_identifier_stack::result:
				printf("result ");
				break;
		}
	}
	printf("\n");
}
