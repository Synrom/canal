#include <canal/scheduler.h>
#include <canal/debugger.h>

void scheduler::decrease(){
	debug("decreasing scheduler");
	count--;
}

void scheduler::increase(){
	debug("increasing scheduler");
	count++;
	if(child)
		child->increase();
}

bool scheduler::look_up(){
	debug("look_up in scheduler");
	if(!count)
		return true;
	decrease();
	if(!count)
		return true;
	return false;
}

scheduler::scheduler(scheduler *s) : child(s) {
	debug("creating scheduler with child %p",s);
}
