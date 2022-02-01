#include <stdlib.h>
#include <new>
#include <string>

#include <string.h>
#include <unistd.h>

#include <canal/variable.h>
#include <canal/container.h>
#include <canal/debugger.h>

unsigned int count = 0;






vcontainer::iterator::iterator(variable *v): location(v){
	debug("constructing vcontainer iterator");
}

void vcontainer::iterator::Inc(){
	debug("incrementing vcontainer iterator");
	location++;
}

bool vcontainer::iterator::operator!=(const vcontainer::iterator &cmp){

	debug_conditional(cmp.location != location, "comparing different vcontainer iterators");
	debug_conditional(cmp.location == location, "comparing equal vcontainer iterators");

	return cmp.location != location;
}

bool vcontainer::iterator::operator==(const vcontainer::iterator &cmp){

	debug_conditional(cmp.location != location, "comparing different vcontainer iterators");
	debug_conditional(cmp.location == location, "comparing equal vcontainer iterators");

	return cmp.location == location;
}

vcontainer::iterator vcontainer::begin(){
	debug("creating vcontainer begin iterator");
	return vcontainer::iterator(buf);
}

vcontainer::iterator vcontainer::end(){
	debug("creating vcontainer end iterator");
	return vcontainer::iterator(end_);
}

vcontainer::iterator vcontainer::last(){
	debug("creating vcontainer last iterator");
	return vcontainer::iterator(end_ - 1);
}

variable *vcontainer::iterator::operator *(){
	debug("getting variable %p from vcontainer::iterator",location);
	return location;
}

vcontainer::vcontainer(){
	count++;
	number = count;

	buf = NULL;
	capacity = 0;
	end_ = NULL;

	debug("constructing vcontainer %d",number);
	
}

vcontainer::~vcontainer(){
	debug("destroying vcontainer %d",number);

	for(auto i = begin(); i != end(); i.Inc()){
		debug("vcontainer deconstructs %s",(*i)->name.c_str());
		(*i)->~variable();
	}

	debug("freeing %p",buf);
	free(buf);

}

vcontainer::const_iterator vcontainer::cbegin() const noexcept{
	return buf;
}

vcontainer::const_iterator vcontainer::cend() const noexcept{
	return end_;
}

vcontainer::const_iterator vcontainer::clast() const noexcept{
	return end_ - 1;
}

variable *vcontainer::get_new_location(){
	debug("get new location in vcontainer");

	if(capacity - (end_ - buf) > 0){

		debug("vcontainer still got enough capacity");
		variable *result = end_;
		end_++;
		debug("returning %p and end is %p",result,end_);
		return result;

	}

	debug("vcontainer hasnt enough capacity");
	debug("vcontainer has buf at %p with capacity %d and end at %p",buf,capacity,end_);

	capacity = (capacity + 1) * 2;
	
	variable *new_buf = (variable *)malloc(capacity * sizeof(variable));
	variable *new_buf_i = new_buf;
	
	for(auto i = cbegin();i != cend();i++, new_buf_i++){
		switch(i->type){
			case variable::signedchar:
				new (new_buf_i) signedchar(i);
				break;
			case variable::unsignedchar:
				new (new_buf_i) unsignedchar(i);
				break;
			case variable::signedshort:
				new (new_buf_i) signedshort(i);
				break;
			case variable::unsignedshort:
				new (new_buf_i) unsignedshort(i);
				break;
			case variable::signedint:
				new (new_buf_i) signedint(i);
				break;
			case variable::unsignedint:
				new (new_buf_i) unsignedint(i);
				break;
			case variable::signedlong:
				new (new_buf_i) signedlong(i);
				break;
			case variable::unsignedlong:
				new (new_buf_i) unsignedlong(i);
				break;
			case variable::signedlonglong:
				new (new_buf_i) signedlonglong(i);
				break;
			case variable::unsignedlonglong:
				new (new_buf_i) unsignedlonglong(i);
				break;
			case variable::_float:
				new (new_buf_i) _float(i);
				break;
			case variable::_double:
				new (new_buf_i) _double(i);
				break;
			case variable::longdouble:
				new (new_buf_i) longdouble(i);
				break;
			case variable::pointer:
				new (new_buf_i) pointer(i);
				break;
			default:
				error("copying an variable witch matches no type");
		}

	}

	for(auto i = begin();i != end();i.Inc()){
		(*i)->~variable();
	}
	free(buf);

	buf = new_buf;
	end_ = new_buf_i;

	variable *result = end_;
	end_++;

	debug("vcontainer has now new buffer at %p with capacity %d and end at %p",buf,capacity,end_);
	debug("returning %p and end is %p",result,end_);
	return result;


}

vcontainer::vcontainer(const vcontainer &cpy){
	debug("copying vcontainer and constucting vcontainer");

	buf = (variable *)malloc((cpy.end_ - cpy.buf) * sizeof(variable));
	end_ = buf;
	capacity = cpy.end_ - cpy.buf;

	for(const_iterator i = cpy.cbegin(); i != cpy.cend(); i++){
		variable *location = get_new_location();	

		switch(i->type){
			case variable::signedchar:
				new (location) signedchar(i);
				break;
			case variable::unsignedchar:
				new (location) unsignedchar(i);
				break;
			case variable::signedshort:
				new (location) signedshort(i);
				break;
			case variable::unsignedshort:
				new (location) unsignedshort(i);
				break;
			case variable::signedint:
				new (location) signedint(i);
				break;
			case variable::unsignedint:
				new (location) unsignedint(i);
				break;
			case variable::signedlong:
				new (location) signedlong(i);
				break;
			case variable::unsignedlong:
				new (location) unsignedlong(i);
				break;
			case variable::signedlonglong:
				new (location) signedlonglong(i);
				break;
			case variable::unsignedlonglong:
				new (location) unsignedlonglong(i);
				break;
			case variable::_float:
				new (location) _float(i);
				break;
			case variable::_double:
				new (location) _double(i);
				break;
			case variable::longdouble:
				new (location) longdouble(i);
				break;
			case variable::pointer:
				new (location) pointer(i);
				break;
			default:
				error("copying an variable witch matches no type");
		}
	}

	debug("vcontainer is copied");

};

vcontainer& vcontainer::operator=(const vcontainer &cpy){
	debug("copying vcontainer in already constructed vcontainer");

	for(auto i = begin(); i != end(); i.Inc())
		(*i)->~variable();
	
	buf = (variable *)realloc(buf,(cpy.end_ - cpy.buf) * sizeof(variable));
	end_ = buf;
	capacity = cpy.end_ - cpy.buf;

	for(const_iterator i = cpy.cbegin(); i != cpy.cend(); i++){
		variable *location = get_new_location();	

		switch(i->type){
			case variable::signedchar:
				new (location) signedchar(i);
				break;
			case variable::unsignedchar:
				new (location) unsignedchar(i);
				break;
			case variable::signedshort:
				new (location) signedshort(i);
				break;
			case variable::unsignedshort:
				new (location) unsignedshort(i);
				break;
			case variable::signedint:
				new (location) signedint(i);
				break;
			case variable::unsignedint:
				new (location) unsignedint(i);
				break;
			case variable::signedlong:
				new (location) signedlong(i);
				break;
			case variable::unsignedlong:
				new (location) unsignedlong(i);
				break;
			case variable::signedlonglong:
				new (location) signedlonglong(i);
				break;
			case variable::unsignedlonglong:
				new (location) unsignedlonglong(i);
				break;
			case variable::_float:
				new (location) _float(i);
				break;
			case variable::_double:
				new (location) _double(i);
				break;
			case variable::longdouble:
				new (location) longdouble(i);
				break;
			case variable::pointer:
				new (location) pointer(i);
				break;
			default:
				error("copying an variable witch matches no type");
		}
	}

	debug("vcontainer is copied");
	
	return *this;
};







void vcontainer::emplace_back(const std::string &s, signed char v){
	debug("emplacing signedchar at the end of vcontainer");
	variable *location = get_new_location();
	new (location) signedchar(s,v);
}

void vcontainer::emplace_back(const std::string &s, unsigned char v){
	debug("emplacing unsignedchar at the end of vcontainer");
	variable *location = get_new_location();
	new (location) unsignedchar(s,v);
}

void vcontainer::emplace_back(const std::string &s, signed short v){
	debug("emplacing signedshort at the end of vcontainer");
	variable *location = get_new_location();
	new (location) signedshort(s,v);
}

void vcontainer::emplace_back(const std::string &s, unsigned short v){
	debug("emplacing unsignedshort at the end of vcontainer");
	variable *location = get_new_location();
	new (location) unsignedshort(s,v);
}

void vcontainer::emplace_back(const std::string &s, signed int v){
	debug("emplacing signedint at the end of vcontainer");
	variable *location = get_new_location();
	new (location) signedint(s,v);
}

void vcontainer::emplace_back(const std::string &s, unsigned int v){
	debug("emplacing unsignedint at the end of vcontainer");
	variable *location = get_new_location();
	new (location) unsignedint(s,v);
}

void vcontainer::emplace_back(const std::string &s, signed long v){
	debug("emplacing signedlong at the end of vcontainer");
	variable *location = get_new_location();
	new (location) signedlong(s,v);
}

void vcontainer::emplace_back(const std::string &s, unsigned long v){
	debug("emplacing unsignedlong at the end of vcontainer");
	variable *location = get_new_location();
	new (location) unsignedlong(s,v);
}

void vcontainer::emplace_back(const std::string &s, signed long long v){
	debug("emplacing signedlonglong at the end of vcontainer");
	variable *location = get_new_location();
	new (location) signedlonglong(s,v);
}

void vcontainer::emplace_back(const std::string &s, unsigned long long v){
	debug("emplacing unsignedlonglong at the end of vcontainer");
	variable *location = get_new_location();
	new (location) unsignedlonglong(s,v);
}

void vcontainer::emplace_back(const std::string &s, float v){
	debug("emplacing _float at the end of vcontainer");
	variable *location = get_new_location();
	new (location) _float(s,v);
}

void vcontainer::emplace_back(const std::string &s, double v){
	debug("emplacing _double at the end of vcontainer");
	variable *location = get_new_location();
	new (location) _double(s,v);
}

void vcontainer::emplace_back(const std::string &s, long double v){
	debug("emplacing longdouble at the end of vcontainer");
	variable *location = get_new_location();
	new (location) longdouble(s,v);
}

void vcontainer::emplace_back(const std::string &s, unsigned long long si, unsigned int v){
	debug("emplaceing pointer at the end of vcontaier");
	variable *location = get_new_location();
	new (location) pointer(s,si,v);
}

int vcontainer::find(const std::string &name){
	debug("searching for %s in vcontainer",name.c_str());
	int n = 0;
	for(auto i = begin();i != end();i.Inc(),n++){
		if((*i)->name == name){
			debug("found %s in container",name.c_str());
			return n;
		}
	}
	warning("didnt found %s in container",name.c_str());
	return -1;
}

variable *vcontainer::get_pointer(unsigned int i){
	error_conditional(i > end_ - buf,"vcontainer::get_pointer asking for pointer out of range");
	return buf + i;
}
