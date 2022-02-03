#include <vector>

#include <canal/operation.h>
#include <canal/function.h>
#include <canal/debugger.h>

void Equal::execute(){
	debug("Equal execute");

	freference.operations.getNext()->execute();
	error_conditional(freference.identifier.look() == result_identifier_stack::result, "in equal::execute left is a result which is weird");

	std::vector<variable *> left_var = freference.locals.pop();
	debug("Equal execute gets %s from current_vstance",left_var.front()->name.c_str());	

	freference.operations.getNext()->execute();
	if(freference.identifier.look() == result_identifier_stack::result){

		result right_result = freference.results.pop_result();

		error_conditional(right_result.get_size() != left_var.size(), 
				"in equal::execute right_result size is %d and left_var size is %lu",
				right_result.get_size(),
				left_var.size()
		);

		std::vector<variable *>::iterator left_iterator = left_var.begin();
		variable *right_iterator = right_result.begin();

		while(left_iterator != left_var.end()){

			(*left_iterator)->Equal(right_iterator);

			left_iterator++;
			right_iterator++;
		}



	}else{

		std::vector<variable *> right_var = freference.locals.pop();
		debug("Equal execute gets %s from current_vstance",right_var.front()->name.c_str());	


		error_conditional(right_var.size() != left_var.size(), 
				"in equal::execute right_result size is %lu and left_var size is %lu",
				right_var.size(),
				left_var.size()
		);

		std::vector<variable *>::iterator left_iterator = left_var.begin();
		std::vector<variable *>::iterator right_iterator = right_var.begin();

		while(left_iterator != left_var.end()){

			(*left_iterator)->Equal(*right_iterator);

			left_iterator++;
			right_iterator++;
		}
		
	}

}


