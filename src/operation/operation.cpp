#include <canal/variable.h>
#include <canal/operation.h>
#include <canal/debugger.h>
#include <string>

operation::~operation(){
	debug("deconstructing operation");
}

operation::operation(Types _type,function &func): freference(func), type(_type) {
	debug("constructing operation");
}



operation::operation(Types _type, function *f, function &func): call(f) , freference(func), type(_type)  {
	debug("constructing operation");
}


Add::Add(function &f) : operation(operation::Add,f) { 
	debug("creating Add operation");
}

Add::Add(operation *cpy) : operation(operation::Add,cpy->freference) { 
	debug("creating Add operation");
}

Add::Add(const Add &cpy) : operation(operation::Add,cpy.freference) { 
	debug("creating Add operation");
}

void Add::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Add operation");
	left->Plus(where, right);
}

Minus::Minus(function &f) : operation(operation::Minus,f) { 
	debug("creating Minus operation");
}

Minus::Minus(const Minus &cpy) : operation(operation::Minus,cpy.freference) { 
	debug("creating Minus operation");
}

Minus::Minus(operation *cpy) : operation(operation::Minus,cpy->freference) { 
	debug("creating Minus operation");
}

void Minus::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Minus operation");
	left->Minus(where, right);
}

Times::Times(function &f) : operation(operation::Times,f) { 
	debug("creating Times operation");
}

Times::Times(const Times &cpy) : operation(operation::Times,cpy.freference) { 
	debug("creating Times operation");
}

Times::Times(operation *cpy) : operation(operation::Times,cpy->freference) { 
	debug("creating Times operation");
}

void Times::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Times operation");
	left->Times(where, right);
}

Divide::Divide(function &f) : operation(operation::Divide,f) { 
	debug("creating Divide operation");
}

Divide::Divide(const Divide &cpy) : operation(operation::Divide,cpy.freference) { 
	debug("creating Times operation");
}

Divide::Divide(operation *cpy) : operation(operation::Divide,cpy->freference) { 
	debug("creating Divide operation");
}

void Divide::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Divide operation");
	left->Divide(where, right);
}

And::And(function &f) : operation(operation::And,f) { 
	debug("creating And operation");
}

And::And(const And &cpy) : operation(operation::And,cpy.freference) { 
	debug("creating And operation");
}

And::And(operation *cpy) : operation(operation::And,cpy->freference) { 
	debug("creating And operation");
}

void And::executeOperation(variable *left, variable *right, variable *where){
	debug("calling And operation");
	left->And(where, right);
}

Or::Or(function &f) : operation(operation::Or,f) { 
	debug("creating Or operation");
}

Or::Or(const Or &cpy) : operation(operation::Or,cpy.freference) { 
	debug("creating Or operation");
}

Or::Or(operation *cpy) : operation(operation::Or,cpy->freference) { 
	debug("creating Or operation");
}

void Or::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Or operation");
	left->Or(where, right);
}

Xor::Xor(function &f) : operation(operation::Xor,f) { 
	debug("creating Xor operation");
}

Xor::Xor(const Xor &cpy) : operation(operation::Xor,cpy.freference) { 
	debug("creating Xor operation");
}
Xor::Xor(operation *cpy) : operation(operation::Xor,cpy->freference) { 
	debug("creating Xor operation");
}

void Xor::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Xor operation");
	left->Xor(where, right);
}

Neg::Neg(function &f) : operation(operation::Neg,f) { 
	debug("creating Neg operation");
}

Neg::Neg(const Neg &cpy) : operation(operation::Neg,cpy.freference) { 
	debug("creating Neg operation");
}

Neg::Neg(operation *cpy) : operation(operation::Neg,cpy->freference) { 
	debug("creating Neg operation");
}

void Neg::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Neg executeOperation which is really weird");
}


Call::Call(function *c, function &f) : operation(operation::Call, c, f){
	debug("creating a Call operator");
}

Call::Call(operation *cpy) : operation(operation::Call, cpy->call ,cpy->freference){
	debug("creating a Call operator");
}

Call::Call(const Call &cpy) : operation(operation::Call,cpy.call,cpy.freference) { 
	debug("creating Call operation");
}


void Call::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Call executeOperation which is really weird");
}

Equal::Equal(function &f): operation(operation::Equal, f){
	debug("creating an Equal operator");
}

Equal::Equal(operation *cpy) : operation(operation::Equal,cpy->freference) { 
	debug("creating Equal operation");
}

Equal::Equal(const Equal &cpy) : operation(operation::Equal,cpy.freference) { 
	debug("creating Equal operation");
}

void Equal::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Equal executeOperation which is really weird");
}

Ret::Ret(function &f): operation(operation::Ret, f){
	debug("creating a Ret operator");
}

Ret::Ret(const Ret &cpy) : operation(operation::Ret,cpy.freference) { 
	debug("creating Ret operation");
}

Ret::Ret(operation *cpy) : operation(operation::Ret,cpy->freference) { 
	debug("creating Ret operation");
}

void Ret::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Ret executeOperation which is really weird");
}


void operation::execute(){
	debug("operation::execute");

	operation *op = freference.operations.getNext();
	error_conditional(!op, "left operation in operation::execute is NULL");
	op->execute();
	if(freference.identifier.look() == result_identifier_stack::result){
		
		debug("left is a result");
		op = freference.operations.getNext();
		error_conditional(!op, "right operation in operation::execute is NULL");
		op->execute();

		if(freference.identifier.look() == result_identifier_stack::result){
			debug("right is result");

			result right_result = freference.results.pop_result();
			result &left_result = freference.results.get_result(0);


			error_conditional(right_result.get_size() != left_result.get_size(),
					"the sizes (%d and %d) of the results are different in operation::execute",
					right_result.get_size(),left_result.get_size());

			variable *right_iterator = right_result.begin();
			variable *left_iterator = left_result.begin();

			while(left_iterator != left_result.end()){

				debug("%p = %p operation %p\n",left_iterator,left_iterator,right_iterator);
				
				executeOperation(/* left */ left_iterator,
						 /* right */ right_iterator,
						 /* where */ left_iterator);

				right_iterator++;
				left_iterator++;
			}

			if(left_result.begin()->type != variable::pointer && right_result.begin()->type == variable::pointer){
				debug("have to adjust to right pointer");

				result non_pointer_result = freference.results.pop_result();
				result &pointer_result  = freference.results.push_result(non_pointer_result.get_size());

				error_conditional(pointer_result.get_size() != right_result.get_size(), 
						"in operation::execute adjusting space size %d != right_result.size %d",
						pointer_result.get_size(), right_result.get_size());

				auto pointer_it = pointer_result.begin();
				auto non_pointer_it = non_pointer_result.begin();
				right_iterator = right_result.begin();

				while(right_iterator != right_result.end()){

					right_iterator->clone(pointer_it);
					pointer_it->Equal(non_pointer_it);
					
					right_iterator++;
					pointer_it++;
					non_pointer_it++;
				}

			}

		}else{
			debug("right is a variable");	
			

			std::vector<variable *> right_result = freference.locals.pop();
			result &left_result = freference.results.get_result(0);
			

			error_conditional(right_result.size() != left_result.get_size(),
					"the sizes (%ld and %d) of the results are different in operation::execute",
					right_result.size(),left_result.get_size());


			auto left_iterator = left_result.begin();
			auto right_iterator = right_result.begin();

			while(right_iterator != right_result.end()){

				debug("%p = %p operation %p\n",left_iterator,left_iterator,*right_iterator);

				executeOperation(/* left */ left_iterator,
						 /* right */ *right_iterator,
						 /* where */ left_iterator);

				left_iterator++;
				right_iterator++;

			}

			debug("out of right_iterator iteration");

			if(left_result.begin()->type != variable::pointer && right_result.front()->type == variable::pointer){
				debug("have to adjust to right pointer");

				result non_pointer_result = freference.results.pop_result();
				result &pointer_result  = freference.results.push_result(non_pointer_result.get_size());

				error_conditional(pointer_result.get_size() != right_result.size(), 
						"in operation::execute adjusting space size %d != right_result.size %ld",
						pointer_result.get_size(), right_result.size());

				auto pointer_it = pointer_result.begin();
				auto non_pointer_it = non_pointer_result.begin();
				right_iterator = right_result.begin();

				while(right_iterator != right_result.end()){

					(*right_iterator)->clone(pointer_it);
					pointer_it->Equal(non_pointer_it);
					
					right_iterator++;
					pointer_it++;
					non_pointer_it++;
				}

			}

		}
	}else{
		debug("left is a variable");
		op = freference.operations.getNext();
		error_conditional(!op, "right operation in operation::execute is NULL");
		op->execute();

		if(freference.identifier.look() == result_identifier_stack::result){
			
			debug("right is a result");

			result right_result = freference.results.pop_result();
			std::vector<variable *> left_result = freference.locals.pop();


			error_conditional(right_result.get_size() != left_result.size(),
					"the sizes (%d and %ld) of the results are different in operation::execute",
					right_result.get_size(),left_result.size());

			result &result_space = freference.results.push_result(left_result.size());


			auto left_iterator = left_result.begin();
			auto right_iterator = right_result.begin();
			auto result_iterator = result_space.begin();

			while(right_iterator != right_result.end()){

				debug("%p = %p operation %p\n",result_iterator,*left_iterator,right_iterator);

				executeOperation(/* left */  *left_iterator,
						 /* right */ right_iterator,
						 /* where */ result_iterator);

				left_iterator++;
				right_iterator++;
				result_iterator++;
			}

			if(left_result.front()->type != variable::pointer && right_result.begin()->type == variable::pointer){
				debug("have to adjust to right pointer");

				result non_pointer_result = freference.results.pop_result();
				result &pointer_result  = freference.results.push_result(non_pointer_result.get_size());

				error_conditional(pointer_result.get_size() != right_result.get_size(), 
						"in operation::execute adjusting space size %d != right_result.size %d",
						pointer_result.get_size(), right_result.get_size());

				auto pointer_it = pointer_result.begin();
				auto non_pointer_it = non_pointer_result.begin();
				right_iterator = right_result.begin();

				while(right_iterator != right_result.end()){

					right_iterator->clone(pointer_it);
					pointer_it->Equal(non_pointer_it);
					
					right_iterator++;
					pointer_it++;
					non_pointer_it++;
				}

			}

		}else{
			debug("right is a variable");

			std::vector<variable *> right_result = freference.locals.pop();
			std::vector<variable *> left_result = freference.locals.pop();


			error_conditional(right_result.size() != left_result.size(),
					"the sizes (%ld and %ld) of the results are different in operation::execute",
					right_result.size(),left_result.size());

			result &result_space = freference.results.push_result(right_result.size());

			auto left_iterator = left_result.begin();
			auto right_iterator = right_result.begin();
			variable *result_iterator = result_space.begin();

			while(left_iterator != left_result.end()){

				debug("%p = %p operation %p\n",result_iterator,*left_iterator,*right_iterator);

				executeOperation(/* left */  *left_iterator,
						 /* right */ *right_iterator,
						 /* where */ result_iterator);

				left_iterator++;
				right_iterator++;
				result_iterator++;
			}

			if(left_result.front()->type != variable::pointer && right_result.front()->type == variable::pointer){
				debug("have to adjust to right pointer");

				result non_pointer_result = freference.results.pop_result();
				result &pointer_result  = freference.results.push_result(non_pointer_result.get_size());

				error_conditional(pointer_result.get_size() != right_result.size(), 
						"in operation::execute adjusting space size %d != right_result.size %ld",
						pointer_result.get_size(), right_result.size());

				auto pointer_it = pointer_result.begin();
				auto non_pointer_it = non_pointer_result.begin();
				right_iterator = right_result.begin();

				while(right_iterator != right_result.end()){

					(*right_iterator)->clone(pointer_it);
					pointer_it->Equal(non_pointer_it);
					
					right_iterator++;
					pointer_it++;
					non_pointer_it++;
				}

			}

		}
	}

}


