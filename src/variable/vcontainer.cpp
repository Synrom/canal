#include <stdlib.h>
#include <new>

#include <string.h>
#include <unistd.h>

#include <canal/variable.h>
#include <canal/container.h>
#include <canal/debugger.h>

unsigned int count = 0;

vcontainer::vcontainer(){
	count++;
	number = count;

	debug("constructing vcontainer %d",number);
	
}

vcontainer::~vcontainer(){
	debug("destroying vcontainer %d",number);
	//TODO deconstruct variables

}

vcontainer::vcontainer(const vcontainer &cpy){
	debug("copying vcontainer and constucting vcontainer");

	// TODO deconstruct variables
	
	buf = (variable *)realloc(buf,cpy.size);
	size = cpy.size;
	capacity = cpy.capacity;

	// TODO cpy variables	
	// 	-> find out about this new(buf) variable(Int)

};








