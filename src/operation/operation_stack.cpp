#include <vector>

#include <canal/operation.h>
#include <canal/operation_stack.h>
#include <canal/debugger.h>


template<typename T> 
void operation_stack::insert(const T &value, rope &r){
	debug("inserting operation in operation_stack at %u",r);
	unsigned int difference = current - start_buf;
	if(difference > r)
		difference++;

	debug("operation_stack before new location %p-%p",start_buf,end_buf);
	operation *i = get_new_location();
	debug("operation_stack after new location %p-%p",start_buf,end_buf);


	while(start_buf + r < i){

		error_conditional(i < start_buf, "operation_stack::insert with rope %u is out of bounds start: %p iterator: %p",r,start_buf,i);


		debug("cloning %p to %p",i-1,i);
		(i - 1)->clone(i);

		debug("destructing %p",i-1);
		(i - 1)->~operation();

		i--;
	}

operation_stack_insert_value:
	error_conditional(start_buf + r != i, "start_buf %p plus %u (times size of operation) isnt equal to %p",start_buf,r,i);
	debug("final clone of value to %p",i);
	value.clone(i);

	
	for(auto rope_domain = ropes.begin(); rope_domain != ropes.end();rope_domain++){
		for(auto adjuster = (*rope_domain).begin();adjuster != (*rope_domain).end();adjuster++){
			if(*adjuster > r)
				(*adjuster)++;
		}
	}

	int domain = ropes.size() - 1;
	debug("fixing the parent ropes of %u at level %d",r,domain);
	while(domain != 0 && get_base_rope(r, domain) == r){
		get_base_rope(r,  domain)++;
		domain--;
	}

	current = start_buf + difference;
	r++;
}

operation_stack::rope &operation_stack::get_base_rope(rope r, int domain){
	debug("getting base rope of rope %u at level %d",r,domain);

	error_conditional(domain - 1 < 0, "trying to get base rope of a root rope");
	std::vector<rope> &parent_rope_domain = ropes[domain - 1];

	for(auto i = parent_rope_domain.begin();i != parent_rope_domain.end();i++){
		if(*i >= r)
			return *i;
	}
	error("couldnt find a parent of %u",r);

}

template<typename T>
void operation_stack::insert_all_ropes(const T &value){
	warning_conditional(ropes.empty(), "trying to insert operation to operation_stack without any ropes");
	for(auto i = ropes.back().begin();i != ropes.back().end();i++){
		insert(value,*i);
	}
}

template<typename T>
void operation_stack::insert_last_rope(const T &value){
	debug("inserting into last rope");
	if(ropes.size() == 1){
		insert(value,ropes.back().back());
		return;
	}
	auto rope_riterator = ropes.back().rbegin();
	for(unsigned int i = ropes[ropes.size() - 2].size();i > 0;i--, rope_riterator++){
		insert(value,*rope_riterator);
	}
}

void operation_stack::down_rope(){
	std::vector<rope> rope_domain = ropes.back();
	ropes.push_back(rope_domain);
}

void operation_stack::up_rope(){
	error_conditional(ropes.size() == 1, "trying to go up from root rope");
	ropes.pop_back();
}

void operation_stack::add_rope(){
	if(ropes.size() == 1){
		ropes.back().push_back(ropes.back().back());
		return;
	}
	for(auto rope_it = ropes[ropes.size() - 2].begin();rope_it != ropes[ropes.size() - 2].end();rope_it++)
		ropes.back().push_back(*rope_it);
}


operation_stack::operation_stack(){
	debug("creating operation_stack");
	
	start_buf = NULL;
	end_buf = NULL;
	current = NULL;
	capacity = 0;
	std::vector<rope> rope_init;
	rope_init.push_back(0);
	ropes.push_back(rope_init);
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
		i->clone(new_buf_i);
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

	operation *ret = current;
	current++;
	
	if(ret >= end_buf){
		if(ret > end_buf)
			debug("current iterator of operation_stack is out of range");
		debug("current is out");
		return NULL;
	}
	
	debug("current of operation_stack is %p with start %p and end %p",current,start_buf,end_buf);
	debug("returning %p",ret);
	return ret;
}

void operation_stack::reset(){
	debug("resetting current of to %p with start %p and end %p",current,start_buf,end_buf);
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

void operation_stack::push_back(const IntLiteral &cpy){
	debug("adding IntLiteral to operation_stack");
	new (get_new_location()) IntLiteral(cpy);
}

void operation_stack::push_back(const Or &cpy){
	debug("adding Or to operation_stack");
	new (get_new_location()) Or(cpy);
}

void operation_stack::push_back(const Xor &cpy){
	debug("adding Xor to operation_stack");
	new (get_new_location()) Xor(cpy);
}

void operation_stack::push_back(const Shl &cpy){
	debug("adding Shl to operation_stack");
	new (get_new_location()) Shl(cpy);
}

void operation_stack::push_back(const Shr &cpy){
	debug("adding Shr to operation_stack");
	new (get_new_location()) Shr(cpy);
}

void operation_stack::push_back(const Inc_Post &cpy){
	debug("adding Inc to operation_stack");
	new (get_new_location()) Inc_Post(cpy);
}

void operation_stack::push_back(const Dec_Post &cpy){
	debug("adding Dec to operation_stack");
	new (get_new_location()) Dec_Post(cpy);
}

void operation_stack::push_back(const Inc_Pre &cpy){
	debug("adding Inc to operation_stack");
	new (get_new_location()) Inc_Pre(cpy);
}

void operation_stack::push_back(const Dec_Pre &cpy){
	debug("adding Dec to operation_stack");
	new (get_new_location()) Dec_Pre(cpy);
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

void operation_stack::push_back(const VarPush &cpy){
	debug("adding VarPush to operation_stack");
	new (get_new_location()) VarPush(cpy);
}

void operation_stack::print(){

	operation *current_safe = current;
	reset();

	operation *op = getNext();
	while(op != NULL){
		op->print();
		op = getNext();
	}

	current = current_safe;

}

void operation_stack::print_simple(){

	operation *current_safe = current;
	reset();

	operation *op = getNext();
	while(op != NULL){
		op->print_simple();
		op = getNext();
	}

	current = current_safe;


}

operation *operation_stack::get_latest_added_operation(){
	debug("returning latest added operation");
	return end_buf - 1;
}


template void operation_stack::insert<Add>(const Add &value,rope &r);
template void operation_stack::insert<Minus>(const Minus &value,rope &r);
template void operation_stack::insert<Divide>(const Divide &value,rope &r);
template void operation_stack::insert<Times>(const Times &value,rope &r);
template void operation_stack::insert<Or>(const Or &value,rope &r);
template void operation_stack::insert<And>(const And &value,rope &r);
template void operation_stack::insert<Xor>(const Xor &value,rope &r);
template void operation_stack::insert<Shl>(const Shl &value,rope &r);
template void operation_stack::insert<Shr>(const Shr &value,rope &r);
template void operation_stack::insert<Neg>(const Neg &value,rope &r);
template void operation_stack::insert<Dec_Post>(const Dec_Post &value,rope &r);
template void operation_stack::insert<Inc_Post>(const Inc_Post &value,rope &r);
template void operation_stack::insert<Dec_Pre>(const Dec_Pre &value,rope &r);
template void operation_stack::insert<Inc_Pre>(const Inc_Pre &value,rope &r);
template void operation_stack::insert<Call>(const Call &value,rope &r);
template void operation_stack::insert<Equal>(const Equal &value,rope &r);
template void operation_stack::insert<Ret>(const Ret &value,rope &r);
template void operation_stack::insert<VarPush>(const VarPush &value,rope &r);
template void operation_stack::insert<IntLiteral>(const IntLiteral &value,rope &r);
template void operation_stack::insert<Add_Switch>(const Add_Switch &value,rope &r);
template void operation_stack::insert<Next_Switch>(const Next_Switch &value,rope &r);
template void operation_stack::insert<End_Switch>(const End_Switch &value,rope &r);
template void operation_stack::insert<Access>(const Access &value,rope &r);

template void operation_stack::insert_all_ropes<Add>(const Add &value);
template void operation_stack::insert_all_ropes<Minus>(const Minus &value);
template void operation_stack::insert_all_ropes<Divide>(const Divide &value);
template void operation_stack::insert_all_ropes<Times>(const Times &value);
template void operation_stack::insert_all_ropes<Or>(const Or &value);
template void operation_stack::insert_all_ropes<And>(const And &value);
template void operation_stack::insert_all_ropes<Xor>(const Xor &value);
template void operation_stack::insert_all_ropes<Shl>(const Shl &value);
template void operation_stack::insert_all_ropes<Shr>(const Shr &value);
template void operation_stack::insert_all_ropes<Neg>(const Neg &value);
template void operation_stack::insert_all_ropes<Dec_Post>(const Dec_Post &value);
template void operation_stack::insert_all_ropes<Inc_Post>(const Inc_Post &value);
template void operation_stack::insert_all_ropes<Dec_Pre>(const Dec_Pre &value);
template void operation_stack::insert_all_ropes<Inc_Pre>(const Inc_Pre &value);
template void operation_stack::insert_all_ropes<Call>(const Call &value);
template void operation_stack::insert_all_ropes<Equal>(const Equal &value);
template void operation_stack::insert_all_ropes<Ret>(const Ret &value);
template void operation_stack::insert_all_ropes<VarPush>(const VarPush &value);
template void operation_stack::insert_all_ropes<IntLiteral>(const IntLiteral &value);
template void operation_stack::insert_all_ropes<Add_Switch>(const Add_Switch &value);
template void operation_stack::insert_all_ropes<Next_Switch>(const Next_Switch &value);
template void operation_stack::insert_all_ropes<End_Switch>(const End_Switch &value);
template void operation_stack::insert_all_ropes<Access>(const Access &value);

template void operation_stack::insert_last_rope<Add>(const Add &value);
template void operation_stack::insert_last_rope<Minus>(const Minus &value);
template void operation_stack::insert_last_rope<Divide>(const Divide &value);
template void operation_stack::insert_last_rope<Times>(const Times &value);
template void operation_stack::insert_last_rope<Or>(const Or &value);
template void operation_stack::insert_last_rope<And>(const And &value);
template void operation_stack::insert_last_rope<Xor>(const Xor &value);
template void operation_stack::insert_last_rope<Shl>(const Shl &value);
template void operation_stack::insert_last_rope<Shr>(const Shr &value);
template void operation_stack::insert_last_rope<Neg>(const Neg &value);
template void operation_stack::insert_last_rope<Dec_Post>(const Dec_Post &value);
template void operation_stack::insert_last_rope<Inc_Post>(const Inc_Post &value);
template void operation_stack::insert_last_rope<Dec_Pre>(const Dec_Pre &value);
template void operation_stack::insert_last_rope<Inc_Pre>(const Inc_Pre &value);
template void operation_stack::insert_last_rope<Call>(const Call &value);
template void operation_stack::insert_last_rope<Equal>(const Equal &value);
template void operation_stack::insert_last_rope<Ret>(const Ret &value);
template void operation_stack::insert_last_rope<VarPush>(const VarPush &value);
template void operation_stack::insert_last_rope<IntLiteral>(const IntLiteral &value);
template void operation_stack::insert_last_rope<Add_Switch>(const Add_Switch &value);
template void operation_stack::insert_last_rope<Next_Switch>(const Next_Switch &value);
template void operation_stack::insert_last_rope<End_Switch>(const End_Switch &value);
template void operation_stack::insert_last_rope<Access>(const Access &value);
