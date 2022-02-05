#include <vector>
#include "variable.h"

class result{
public:

	result(unsigned int);
	~result();
	result(result &&);
	result &operator =(result &&);

	using iterator = variable *;
	iterator begin();
	iterator end();

	unsigned int get_size();
	


private:
	variable *buf;
	unsigned int size;
};

class result_identifier_stack{
public:
	enum result_identifier{
		result,
		local
	};

	result_identifier look();
	void push(result_identifier );
	void pop();
	void reset();
	
private:
	std::vector<result_identifier> stack;

};

class result_stack{
public:
	
	result &push_result(unsigned int);
	result pop_result();

	result &get_result(unsigned int);
	void delete_result();

	void reset();
	
	result_stack();
	~result_stack();
	result_stack(result_stack &&) = default;
	result_stack &operator =(result_stack &&) = default;
	void set_identifier(result_identifier_stack *);
	
private:
	std::vector<result> results;
	result_identifier_stack *identifiers{NULL};
};

class local_stack{
public:

	std::vector<variable *> pop();
	void push(const std::vector<variable *> &);

	void reset();

	void set_identifier(result_identifier_stack *);
private:
	std::vector<std::vector<variable *>> stack;
	result_identifier_stack *identifiers{NULL};

};



