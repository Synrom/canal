#include <canal/root_operation.h>
#include <canal/operation.h>
#include <canal/debugger.h>

root_operation::root_operation(){
	debug("creating a new root_operation");
	size = 0;
	capacity = 0;
	rsize = 0;
	rcapacity = 0;
	buf = NULL;
	rbuf = NULL;
	end = NULL;
	rend = NULL;
}

root_operation::~root_operation(){
	debug("deconstructing a root_operation");

	for(operation *opit = (operation *)buf;opit != end;opit++)
		opit->~operation();
	
	for(operation *opit = (operation *)rbuf;opit != rend;opit++)
		opit->~operation();

	free(buf);
	free(rbuf);
}	

unsigned int root_operation::new_capacity(){
	debug("> root_operation::new_capacity");

	if(capacity == 0){
		capacity = 1;
		return capacity;
	}

	capacity = capacity * 2;
	return capacity;
}

unsigned int root_operation::new_rcapacity(){
	debug("> root_operation::new_rcapacity");

	if(rcapacity == 0){
		rcapacity = 1;
		return rcapacity;
	}

	rcapacity = rcapacity * 2;
	return rcapacity;
}

operation *root_operation::begin(){
	return (operation *)buf;
}

operation *root_operation::rbegin(){
	return (operation *)rbuf;
}


operation *root_operation::new_last(){
	debug("> root_operation::new_last");

	if(size < capacity){
		operation *ret = end++;
		size++;
		return ret;
	}

	buf = (char *)realloc(buf, new_capacity() * sizeof(operation));
	end = (operation *)(buf + size * (sizeof(operation)));	

	operation *ret = end++;
	size++;
	return ret;

}

operation *root_operation::new_rlast(){
	debug("> root_operation::new_rlast");
	if(rsize < rcapacity){
		operation *ret = rend++;
		rsize++;
		return ret;
	}

	rbuf = (char *)realloc(rbuf, new_rcapacity() * sizeof(operation));
	rend = (operation *)(rbuf + rsize * (sizeof(operation)));	

	operation *ret = rend++;
	rsize++;
	return ret;

}

/* nur fuer tests */

operation *root_operation::append(unsigned int i){
	debug("> root_operation::append nur fuer testing");
	operation *place = new_last();
	new(place) Add((operation *) i, (operation *) (i+1));
	return place;
}

operation *root_operation::rappend(unsigned int i){
	debug("> root_operation::rappend nur fuer testing");
	operation *place = new_rlast();
	new(place) Add((operation *) i, (operation *) (i+1));
	return place;
}


