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
	


private:
	variable *buf;
	unsigned int size;
};

class result_stack{
public:
	
	result &push_result(unsigned int);
	result pop_result();

	result &get_result(unsigned int);
	void delete_result();
	result_stack();
	~result_stack();
	
private:
	std::vector<result> results;
};


