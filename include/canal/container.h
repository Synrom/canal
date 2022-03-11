#ifndef CONTAINER_H
#define CONTAINER_H

#include <vector>
#include <deque>

#include "variable.h"

class function;

class vcontainer{
public:

	class iterator{
	public:
		variable *location;

		iterator(variable *);
		
		void Inc();
		bool operator ==(const iterator &);
		bool operator !=(const iterator &);
		variable * operator *();
	};

	using const_iterator = const variable *;

	variable *buf, *end_;
	unsigned int number;
	unsigned int capacity; // capacity ist in variable slots

	vcontainer();
	vcontainer(const vcontainer &);
	~vcontainer();

	void print();

	vcontainer& operator=(const vcontainer &);

	variable *get_pointer(unsigned int );
	iterator begin();
	iterator end();
	iterator last();
	const_iterator cbegin() const noexcept;
	const_iterator cend() const noexcept;
	const_iterator clast() const noexcept;
	int find(const std::string &);
	void emplace_back(const std::string & ,double );
	void emplace_back(const std::string & ,float );
	void emplace_back(const std::string & ,long double );
	void emplace_back(const std::string & ,variable::Types ,unsigned long long ,unsigned int );
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
private:
	variable *get_new_location();

};


class vcontainer_vector{
public:
	vcontainer *add();
	void pop();
//private:
	std::deque<vcontainer> vector;

};

class vstance_vector;

class vstance{
private:

	std::vector<vcontainer *> container;
	std::vector<vstance *> children;
	vstance *parent;

	vcontainer_vector *vcontainer_space;
	vstance_vector *stance_space;

public:
	unsigned int container_quantity();

	vstance(vstance *,vcontainer_vector *, vstance_vector *);
	
	// primitive functions, that dont care about parents etc.
	void add_new_container();
	vcontainer *copy_container(vcontainer *);
	vstance *get_parent();
	vstance *get_child(unsigned int);
	vstance *get_following_neighbor();
	unsigned int children_size();

	// all of these functions care about parents 
	void add_switches(unsigned int); 
	void add_existing_container(vcontainer *);
	void reset();

	void print();
	void print_structure();
	
	void add_var(const std::string & ,double );
	void add_var(const std::string & ,float );
	void add_var(const std::string & ,long double );
	void add_var(const std::string & ,variable::Types ,unsigned long long ,unsigned int );
	void add_var(const std::string & ,signed char );
	void add_var(const std::string & ,signed int );
	void add_var(const std::string & ,signed long );
	void add_var(const std::string & ,signed long long );
	void add_var(const std::string & ,signed short );
	void add_var(const std::string & ,unsigned char );
	void add_var(const std::string & ,unsigned int );
	void add_var(const std::string & ,unsigned long );
	void add_var(const std::string & ,unsigned long long );
	void add_var(const std::string & ,unsigned short );
	std::vector<variable *> get_var(const std::string &);
	variable *get_latest_added_var();

};



class vstance_vector{

private:
	function *freference;

public:
	vstance_vector(function *);
	vstance *add(); // adding vstance root
	vstance *add(vstance *); // adding vstance with parent
	void pop();
	std::deque<vstance> vector;

};




#endif
