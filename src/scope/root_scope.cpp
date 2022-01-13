
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <canal/function.h>
#include <canal/root_scope.h>
#include <canal/debugger.h>

extern function NULL_Function;

root_scope::root_scope(){
	info("> creating the root_scope");

	pages.emplace_back();
	(*(pages.end()-1)).initialize();

}

root_scope::~root_scope(){
	info("> destroying the root_scope");
}

page_scope::~page_scope() noexcept {
	debug("destroying page_scope");
	for(function *i = start;i != end;i++)
		i->~function();
	free(start);
}

page_scope::page_scope(){

	start = NULL;
	end = NULL;

	debug("creating page_scope");
}

void page_scope::initialize() {
	debug("initializing page_scope");
	unsigned int pagesize = getpagesize();
	debug("pagesize = %d",pagesize);
	start = (function *)aligned_alloc(pagesize, pagesize);
	end = start;
	debug("allocated %d bytes at %p for functions (%lu)",pagesize,start,sizeof(function));
	error_conditional(!start,"page_scope::initialize aligned_alloc failed");
}

function *page_scope::begin(){
	debug("getting begin of function page");
	return start;
}


page_scope::page_scope(page_scope &&mv) noexcept {
	debug("creating page_scope mv");
	
	start = mv.start;
	end = mv.end;

	mv.start = NULL;
	mv.end = NULL;
}

page_scope& page_scope::operator=(page_scope &&mv) noexcept {
	debug("moving page_scope");
	
	start = mv.start;
	end = mv.end;

	mv.start = NULL;
	mv.end = NULL;

	return *this;
}

function *page_scope::addFunction(const std::string &name){

	debug("adding Function %s to page",name.c_str());

	unsigned int pagesize = getpagesize();

	if( ((char *)end) + sizeof(function) >= ((char *)start) + pagesize){
		debug("page is full");
		return NULL;
	}

	debug("page has enough capacity, placing object at %p",end);
	new (end) function(name);

	debug("accessing and then incrementing end of function page");
	function *ret = end;
	end++;

	return ret;

}

function &root_scope::findFunction(const std::string &s){
	debug("searching for function %s",s.c_str());	
	
	for(auto i = function_begin();i != function_end(); i.increment()){
		if((*i).name == s){
			debug("found function %s",s.c_str());
			return *i;
		}
	}

	warning("didnt found function %s",s.c_str());
	return NULL_Function;
}


function *root_scope::addFunction(const std::string &name){
	debug("adding function %s to root scope",name.c_str());

	function *ret = pages.back().addFunction(name);

	
	if(ret == NULL){

		debug("page was already completely full");

		pages.emplace_back();
		pages.back().initialize();

		return pages.back().addFunction(name);
	}

	return ret;
}

root_scope::function_iterator::function_iterator(std::vector<page_scope> &p): page(p.begin()) , page_end(p.end()) {
	debug("creating function iterator");
	
	location = (*page).begin();
}

function &root_scope::function_iterator::operator *(){
	debug("access function_iterator");
	return *location;
}

root_scope::function_iterator& root_scope::function_iterator::operator ++(){
	debug("increase function iterator");
	location++;
	
	if(location >= (*page).end){

		debug("got to the end of the function page");
		page++;

		if(page == page_end){
			debug("got to the end of all function pages");
			location = (*(--page)).end;
			return *this;
		}

		location = (*page).begin();

	}

	return *this;

}

void root_scope::function_iterator::increment(){
	debug("increase function iterator");
	location++;
	
	if(location >= (*page).end){

		debug("got to the end of the function page");
		page++;

		if(page == page_end){
			debug("got to the end of all function pages");
			location = (*(--page)).end;
			return ;
		}

		location = (*page).begin();

	}
}

bool root_scope::function_iterator::operator==(const root_scope::function_iterator &comparison){
	debug_conditional(location == comparison.location, "comparing equal iterators (probably end with iterating iterator)");
	debug_conditional(location != comparison.location, "comparing different iterators (probably end with iterating iterator)");
	return location == comparison.location;
}

bool root_scope::function_iterator::operator!=(const root_scope::function_iterator &comparison){
	debug_conditional(location == comparison.location, "comparing equal iterators (probably end with iterating iterator)");
	debug_conditional(location != comparison.location, "comparing different iterators (probably end with iterating iterator)");
	return location != comparison.location;
}

root_scope::function_iterator::function_iterator(function *l){
	debug("constructing iterator with function pointer");
	location = l;
}

root_scope::function_iterator root_scope::function_begin(){
	debug("getting function beginning from root_scope");
	return function_iterator(pages);
}

root_scope::function_iterator root_scope::function_end(){
	debug("getting function ending from root_scope");
	return function_iterator(pages.back().end);
}


