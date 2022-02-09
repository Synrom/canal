#include <vector>

#include <canal/operation.h>
#include <canal/function.h>
#include <canal/debugger.h>

void Call::execute(){
	unsigned int container_size = freference.current_vstance->container_quantity();
	debug("call::execute creating %d container for called function",container_size);

	warning_conditional(call->current_vstance->container_quantity() != 1, 
			"container_quantity of called function is %d != 1",call->current_vstance->container_quantity());

	while(call->current_vstance->container_quantity() < container_size)
		call->current_vstance->add_new_container();
	
	debug("called function has container quantity %d and caller function has %d",
			call->current_vstance->container_quantity(),
			freference.current_vstance->container_quantity()
	     );

	for(auto argument = call->pvariables.begin();argument != call->pvariables.end();argument++){

		debug("getting value for argument %s",(*argument).c_str());

		operation *next = freference.operations.getNext();
		error_conditional(!next, "next operation in Call::execute %s calls %s is NULL",
				call->name.c_str(),
				freference.name.c_str()
				);

		next->execute();

		if(freference.identifier.look() == result_identifier_stack::local){

			debug("argument is variable");

			std::vector<variable *> argument_values = freference.locals.pop();
			std::vector<variable *> argument_space = call->current_vstance->get_var(*argument);

			error_conditional(argument_values.size() != argument_space.size(), 
					"in Call::execute are the sizes of argument_values %ld and argument_space %ld different",
					argument_values.size(), argument_space.size()
					);

			auto value_iterator = argument_values.begin();
			auto space_iterator = argument_space.begin();

			while(value_iterator != argument_values.end()){
				(*space_iterator)->Equal(*value_iterator);
				value_iterator++;
				space_iterator++;
			}


		}else{

			debug("argument is rvalue");

			result argument_values = freference.results.pop_result();
			std::vector<variable *> argument_space = call->current_vstance->get_var(*argument);

			error_conditional(argument_values.get_size() != argument_space.size(), 
					"in Call::execute are the sizes of argument_values %d and argument_space %ld different",
					argument_values.get_size(), argument_space.size()
					);

			auto value_iterator = argument_values.begin();
			auto space_iterator = argument_space.begin();

			while(space_iterator != argument_space.end()){
				(*space_iterator)->Equal(value_iterator);
				value_iterator++;
				space_iterator++;
			}

		}

	}

	call->original_caller_quantity = freference.current_vstance->container_quantity();
	call->caller = &freference;
	call->hasAlreadyReturnedSomething = false;
	call->execute();

	call->reset();

}
