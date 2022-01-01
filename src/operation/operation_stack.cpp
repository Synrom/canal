#include <canal/operation.h>
#include <canal/operation_stack.h>
#include <canal/debugger.h>




operation_stack::operation_stack(){
	debug("creating operation_stack");
	
	start_buf = NULL;
	end_buf = NULL;
	current = NULL;
	capacity = 0;

}

operation_stack::~operation_stack(){
	debug("destroying operation_stack");

	for(auto i = begin(); i != end();i++)
		i->~operation();
	
	free(start_buf);

}

operation_stack::iterator operation_stack::begin(){
	debug("getting begin() from operation_stack");
	return start_buf;
}

operation_stack::iterator operation_stack::end(){
	debug("getting end() from operation_stack");
	return end_buf;
}

operation *operation_stack::get_new_location(){
	debug("get new location in operation");

	if(capacity - (end_buf - start_buf) > 0){

		debug("operation_stack still got enough capacity");
		operation *result = end_buf;
		end_buf++;
		debug("returning %p and end is %p and current %p",result,end_buf,current);
		return result;

	}

	debug("operation_stack hasnt enough capacity");
	debug("operation_stack has buf at %p with capacity %d and end at %p",start_buf,capacity,end_buf);

	capacity = (capacity + 1) * 2;
	
	operation *new_buf = (operation *)malloc(capacity * sizeof(operation));
	operation *new_buf_i = new_buf;
	
	for(auto i = begin();i != end();i++, new_buf_i++){
		
		switch(i->type){
			case operation::Add:
				new (new_buf_i) Add(i);
				break;
			case operation::Minus:
				new (new_buf_i) Minus(i);
				break;
			case operation::Divide:
				new (new_buf_i) Divide(i);
				break;
			case operation::Times:
				new (new_buf_i) Times(i);
				break;
			case operation::Or:
				new (new_buf_i) Or(i);
				break;
			case operation::And:
				new (new_buf_i) And(i);
				break;
			case operation::Xor:
				new (new_buf_i) Xor(i);
				break;
			case operation::Neg:
				new (new_buf_i) Neg(i);
				break;
			case operation::Dec:
				new (new_buf_i) Dec(i);
				break;
			case operation::Inc:
				new (new_buf_i) Inc(i);
				break;
			case operation::Call:
				new (new_buf_i) Call(i);
				break;
			case operation::Equal:
				new (new_buf_i) Equal(i);
				break;
			case operation::Ret:
				new (new_buf_i) Ret(i);
				break;
			default:
				error("copying an operation which matches no type");
		}

	}

	for(auto i = begin();i != end();i++){
		i->~operation();
	}

	unsigned int difference = current - start_buf;
	
	free(start_buf);

	start_buf = new_buf;
	end_buf = new_buf_i;
	current = start_buf + difference;

	operation *result = end_buf;
	end_buf++;

	debug("operation_stack has now new buffer at %p with capacity %d and end at %p and current at %p",start_buf,capacity,end_buf,current);
	debug("returning %p and end is %p",result,end_buf);
	return result;
}

operation_stack::iterator operation_stack::getNext(){
	debug("getting next element of operation_stack");

	if(current >= end_buf){
		info("current iterator of operation_stack is out of range");
		return NULL;
	}
	
	debug("current of operation_stack is %p",current);
	return current++;
}

void operation_stack::reset(){
	debug("resetting current of operation_stack");
	current = start_buf;
}

void operation_stack::push_back(const Add &cpy){
	debug("adding Add to operation_stack");
	new (get_new_location()) Add(cpy);
}

void operation_stack::push_back(const Minus &cpy){
	debug("adding Minus to operation_stack");
	new (get_new_location()) Minus(cpy);
}

void operation_stack::push_back(const Times &cpy){
	debug("adding Times to operation_stack");
	new (get_new_location()) Times(cpy);
}

void operation_stack::push_back(const Divide &cpy){
	debug("adding Divide to operation_stack");
	new (get_new_location()) Divide(cpy);
}

void operation_stack::push_back(const And &cpy){
	debug("adding And to operation_stack");
	new (get_new_location()) And(cpy);
}

void operation_stack::push_back(const Or &cpy){
	debug("adding Or to operation_stack");
	new (get_new_location()) Or(cpy);
}

void operation_stack::push_back(const Xor &cpy){
	debug("adding Xor to operation_stack");
	new (get_new_location()) Xor(cpy);
}

void operation_stack::push_back(const Inc &cpy){
	debug("adding Inc to operation_stack");
	new (get_new_location()) Inc(cpy);
}

void operation_stack::push_back(const Dec &cpy){
	debug("adding Dec to operation_stack");
	new (get_new_location()) Dec(cpy);
}

void operation_stack::push_back(const Neg &cpy){
	debug("adding Neg to operation_stack");
	new (get_new_location()) Neg(cpy);
}

void operation_stack::push_back(const Call &cpy){
	debug("adding Call to operation_stack");
	new (get_new_location()) Call(cpy);
}

void operation_stack::push_back(const Equal &cpy){
	debug("adding Equal to operation_stack");
	new (get_new_location()) Equal(cpy);
}

void operation_stack::push_back(const Ret &cpy){
	debug("adding Ret to operation_stack");
	new (get_new_location()) Ret(cpy);
}

