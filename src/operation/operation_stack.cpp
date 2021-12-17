#include <canal/operation.h>
#include <canal/operation_stack.h>
#include <canal/debugger.h>



operation_stack::operation_stack(operation_stack &&mv){
	debug("creating operation_stack from moving");
	
	start_buf = mv.start_buf;
	end_buf = mv.end_buf;
	iterator = mv.iterator;

	mv.start_buf = NULL;
	mv.end_buf = NULL;
	mv.iterator = NULL;

}

operation_stack::operation_stack(){
	debug("creating operation_stack");
	
	start_buf = NULL;
	end_buf = NULL;
	iterator = NULL;

}

operation_stack& operation_stack::operator=(operation_stack &&mv){
	debug("moving operation_stack");
	
	start_buf = mv.start_buf;
	end_buf = mv.end_buf;
	iterator = mv.iterator;

	mv.start_buf = NULL;
	mv.end_buf = NULL;
	mv.iterator = NULL;

	return *this;
}

operation_stack::~operation_stack(){
	debug("destroying operation_stack");
	
	free(start_buf);

}
