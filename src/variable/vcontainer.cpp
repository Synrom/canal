#include <stdlib.h>
#include <new>

#include <canal/variable.h>
#include <canal/container.h>
#include <canal/debugger.h>

vcontainer::vcontainer(){
	debug("constructing vcontainer");
	buf = NULL;
	end = NULL;
	capacity = 0;
	size = 0;
}

vcontainer::~vcontainer(){
	debug("destroying vcontainer");

	for(variable *varit = (variable *)buf;varit != end;varit++)
		varit->~variable();
	
	free(buf);
}

unsigned int vcontainer::new_capacity(){
	debug("> vcontainer::new_capacity");

	if(capacity == 0){
		capacity = 1;
		return 1;
	}


	capacity = capacity * 2;
	return capacity;

}

variable *vcontainer::begin(){
	debug("> vcontainer::begin");
	return (variable *)buf;
}

variable *vcontainer::new_last(){
	debug("> vcontainer::new_last");
	if(size < capacity){
		variable *ret = end++;
		size++;
		return ret;
	}

	buf = (char *)realloc(buf, new_capacity() * sizeof(variable));
	error_conditional(!buf,"buf is NULL inc vcontainer::begin after realloc");

	end = (variable *)(buf + size * (sizeof(variable)));	

	variable *ret = end++;
	size++;
	return ret;

}

variable *vcontainer::get_pointer(unsigned int position){
	debug("> vcontainer::get_pointer");
	if(position >= size){
		warning("vcontainer::get_pointer got called with to hight position");
		return NULL;
	}
	return (variable *)(buf + (position * sizeof(variable)));
}


void vcontainer::emplace_back(variable::Types type,double v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) _double(type,v);
}

void vcontainer::emplace_back(variable::Types type,float v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) _float(type,v);
}

void vcontainer::emplace_back(variable::Types type,long double v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) longdouble(type,v);
}

void vcontainer::emplace_back(variable::Types type,unsigned long long v, unsigned int size){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) pointer(type,v,size);
}

void vcontainer::emplace_back(variable::Types type,signed char v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) signedchar(type,v);
}

void vcontainer::emplace_back(variable::Types type,signed int v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) signedint(type,v);
}

void vcontainer::emplace_back(variable::Types type,signed long v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) signedlong(type,v);
}

void vcontainer::emplace_back(variable::Types type,signed long long v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) signedlonglong(type,v);
}

void vcontainer::emplace_back(variable::Types type,signed short v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) signedshort(type,v);
}

void vcontainer::emplace_back(variable::Types type,unsigned char v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) unsignedchar(type,v);
}

void vcontainer::emplace_back(variable::Types type,unsigned int v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) unsignedint(type,v);
}

void vcontainer::emplace_back(variable::Types type,unsigned long v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) unsignedlong(type,v);
}

void vcontainer::emplace_back(variable::Types type,unsigned long long v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) unsignedlonglong(type,v);
}

void vcontainer::emplace_back(variable::Types type,unsigned short v){
	debug("> vcontainer::emplace_back");
	variable *place = new_last();
	new(place) unsignedshort(type,v);
}
