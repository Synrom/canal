
#ifndef ROOT_SCOPE_H
#define ROOT_SCOPE_H

#include <vector>
#include <string>

#include "function.h"


class page_scope{
public:
	page_scope();
	~page_scope();
	void initialize();

	page_scope(page_scope &&);
	page_scope& operator=(page_scope &&);

	function &addFunction(const std::string &);

	function *begin();
	function *start,*end;
};

class root_scope{
public:
	std::vector<page_scope> pages;

	class function_iterator{
	public:
		function_iterator(std::vector<page_scope> &);
		function_iterator(function *);
		function &operator *();
		function_iterator &operator++();
		void increment();
		bool operator==(const function_iterator &);
		bool operator!=(const function_iterator &);

	private:
		std::vector<page_scope>::iterator page, page_end;
		function *location;

	};

	function_iterator function_begin();
	function_iterator function_end();

	~root_scope();
	root_scope();
	function &findFunction(const std::string &);
	function &addFunction(const std::string &);
};

#endif
