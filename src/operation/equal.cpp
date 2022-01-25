#include <vector>

#include <canal/operation.h>
#include <canal/function.h>
#include <canal/debugger.h>

void Equal::execute(){
	debug("Equal execute");

	warning_conditional(left == "", "in equal::execute left=\"\" which is weird");

	debug("Equal execute gets %s from current_vstance",left.c_str());	
	std::vector<variable *> left_var = freference.current_vstance->get_var(left);

	if(right == ""){
		debug("Equal execute has to execute and then pop result from operation stack");

		freference.operations.getNext()->execute();
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
		debug("Equal execute gets %s from current_vstance",right.c_str());	

		std::vector<variable *> right_var = freference.current_vstance->get_var(right);

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


