#include <vector>

#include <canal/operation.h>
#include <canal/function.h>
#include <canal/debugger.h>

void Ret::execute(){

	debug("starting return operation");

	if(freference.caller == NULL){
		debug("returning from root caller function");
		return ;
	}
	
	operation *op = freference.operations.getNext();

	error_conditional(!op, "in Ret::execute pointer to follow up operation is NULL");

	op->execute();

	if(freference.identifier.look() == result_identifier_stack::local){

		debug("returning a variable");
		
		std::vector<variable *> var_values = freference.locals.pop();

		unsigned int pmax = 0,n = 0;
		variable *vmax = var_values.front();

		for(auto i = var_values.begin();i != var_values.end();i++,n++){
			if(vmax->isSmaller(*i)){
				vmax = *i;
				pmax = n;
			}
		}
		
		unsigned int pbegin = pmax - (pmax % freference.original_caller_quantity);

		debug("max value is between %u and %u with original_caller_quantity %u",pbegin,pmax,freference.original_caller_quantity);


		if(!(freference.hasAlreadyReturnedSomething)){
			result &results = freference.caller->results.push_result(freference.original_caller_quantity);
			freference.hasAlreadyReturnedSomething = true;
			debug("first return in function %s called by %s so we reserved the space %p",
					freference.name.c_str(),freference.caller->name.c_str(),&results);
		}

		result &results = freference.caller->results.get_result(0);
		debug("got pointer to results space %p with size %u",&results,results.get_size());

		auto value_iterator = var_values.begin();
		for(int i = 0;i < pbegin;i++){
			debug("incrementing value_iterator");
			value_iterator++;
		}
		
		auto space_iterator = results.begin();

		while(space_iterator != results.end()){
			(*value_iterator)->clone(space_iterator);
			value_iterator++;
			space_iterator++;
		}

	}else{
		
		debug("returning a return value");

		result var_values = freference.results.pop_result();

		unsigned int pmax = 0,n = 0;
		variable *vmax = var_values.begin();

		for(auto i = var_values.begin();i != var_values.end();i++,n++){
			if(vmax->isSmaller(i)){
				vmax = i;
				pmax = n;
			}
		}

		unsigned int pbegin = pmax - (pmax % freference.original_caller_quantity);

		debug("max value is between %u and %u with original_caller_quantity %u",pbegin,pmax,freference.original_caller_quantity);


		if(!(freference.hasAlreadyReturnedSomething)){
			result &results = (freference.caller->results.push_result(freference.original_caller_quantity));
			freference.hasAlreadyReturnedSomething = true;
			debug("first return in function %s called by %s so we reserved the space %p",
					freference.name.c_str(),freference.caller->name.c_str(),&results);
		}

		result &results = freference.caller->results.get_result(0);
		debug("got pointer to results space %p with size %u",&results,results.get_size());

		auto value_iterator = var_values.begin();
		for(int i = 0;i < pbegin;i++){
			debug("incrementing value_iterator");
			value_iterator++;
		}
		
		auto space_iterator = results.begin();

		while(space_iterator != results.end()){
			value_iterator->clone(space_iterator);
			value_iterator++;
			space_iterator++;
		}
	}

}
