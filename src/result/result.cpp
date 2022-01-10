#include <vector>
#include <utility>
#include <stdlib.h>

#include <canal/variable.h>
#include <canal/result.h>
#include <canal/debugger.h>

result::result(unsigned int s): size(s){
	buf = (variable *)malloc(size * sizeof(variable));
	error_conditional(!buf , "malloc returned NULL called with %ld in result::result",size*sizeof(variable));

	debug("creating result with size %d at %p",size,buf);
}

result::~result(){
	debug("deconstructing result at %p",buf);
	free(buf);
}

result::result(result &&mv){
	debug("moving result %p constructor",mv.buf);

	buf = mv.buf;
	size = mv.size;

	debug("buf of newly constructed result is %p",buf);
	debug("size of newly constructed result is %d",size);
	
	mv.size = 0;
	mv.buf = NULL;
}

unsigned int result::get_size(){
	debug("getting size of result");
	return size;
}

result &result::operator=(result &&mv){
	debug("moving result %p operator",mv.buf);

	buf = mv.buf;
	size = mv.size;

	mv.size = 0;
	mv.buf = NULL;

	return *this;
}

result::iterator result::begin(){
	debug("result::begin returning %p",buf);
	return buf;
}

result::iterator result::end(){
	debug("result end returning %p",buf + size);
	return buf + size;
}

result_stack::result_stack(){
	debug("creating result_stack");
}

result_stack::~result_stack(){
	debug("deconstructing result_stack");
}

result &result_stack::push_result(unsigned int size){
	debug("push %d results to result stack",size);
	results.emplace_back(size);
	
	return results.back();
}

result result_stack::pop_result(){
	debug("poping result from result_stack");

	result ret(std::move(results.back()));
	results.pop_back();

	return ret;
}


result &result_stack::get_result(unsigned int position){
	debug("get result from result_stack at %ld",results.size() - position);

	return results[(results.size() - position) - 1];
}

void result_stack::delete_result(){
	debug("deleting result from result_stack at top");
	results.pop_back();
}

