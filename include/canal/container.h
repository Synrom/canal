#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <deque>

#include "variable.h"
#include "function.h"

class vcontainer{
public:

	class iterator{
	public:
		variable *location;

		iterator(variable *);
		
		void Inc();
		bool operator ==(const iterator &);
		bool operator !=(const iterator &);
	};
	/* 
	 * TODO: vcontainer =(const vcontainer &) 
	 * TODO: vcontainer programmieren und kopierbar machen
	 */

	variable *buf, *end_;
	unsigned int number;
	unsigned int size, capacity;

	vcontainer();
	vcontainer(vcontainer &&);
	vcontainer(const vcontainer &);
	~vcontainer();


	vcontainer& operator=(const vcontainer &);
	vcontainer& operator=(vcontainer &&);

	variable *get_pointer(unsigned int );
	iterator begin();
	iterator *end();
	void emplace_back(const std::string & ,double );
	void emplace_back(const std::string & ,float );
	void emplace_back(const std::string & ,long double );
	void emplace_back(const std::string & ,unsigned long long ,unsigned int );
	void emplace_back(const std::string & ,signed char );
	void emplace_back(const std::string & ,signed int );
	void emplace_back(const std::string & ,signed long );
	void emplace_back(const std::string & ,signed long long );
	void emplace_back(const std::string & ,signed short );
	void emplace_back(const std::string & ,unsigned char );
	void emplace_back(const std::string & ,unsigned int );
	void emplace_back(const std::string & ,unsigned long );
	void emplace_back(const std::string & ,unsigned long long );
	void emplace_back(const std::string & ,unsigned short );

};

class vcontainer_vector;
class vstance_vector;

class vstance{
private:
	std::vector<vcontainer *> container;
	std::vector<vstance *> children;
	vstance *parent;
	vcontainer_vector *vcontainer_space;
	vstance_vector *stance_space;
public:
	vstance(vstance *,vcontainer_vector *, vstance_vector *);
	void add_new_container();
	void add_existing_container(vcontainer *);
	void copy_container(vcontainer *);

	// TODO:
	void add_switch();

	// TODO:
	void add_var();

};

class vcontainer_vector{
public:
	vcontainer *add();
	void pop();
private:
	std::deque<vcontainer> vector;

};

class vstance_vector{

private:
	std::deque<vstance> vector;
	function *freference;

public:
	vstance_vector(function *);
	vstance *add();
	vstance *add(vstance *);
	void pop();

};































#endif
