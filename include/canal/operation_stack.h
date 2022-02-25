#ifndef ROOT_OPERATION_H
#define ROOT_OPERATION_H

#include <vector>
#include <type_traits>


class function;
class operation;
class Add;
class Minus;
class Divide;
class Times;
class Or;
class And;
class Xor;
class Shl;
class Shr;
class Neg;
class Dec;
class Inc;
class Call;
class Equal;
class Ret;
class IntLiteral;
class VarPush;

class operation_stack{
public:
	operation *getNext();
	void reset();

	operation_stack();
	~operation_stack();

	using iterator = operation *;
	using rope = unsigned int;

	void print();
	void print_simple();

	void push_back(const Add &);
	void push_back(const Minus &);
	void push_back(const Divide &);
	void push_back(const Times &);
	void push_back(const Or &);
	void push_back(const And &);
	void push_back(const Xor &);
	void push_back(const Shl &);
	void push_back(const Shr &);
	void push_back(const Neg &);
	void push_back(const Dec &);
	void push_back(const Inc &);
	void push_back(const Call &);
	void push_back(const Equal &);
	void push_back(const Ret &);
	void push_back(const IntLiteral &);
	void push_back(const VarPush &);
	
	
	template<typename T>
	void insert_last_rope(const T &);

	template<typename T>
	void insert_all_ropes(const T &);

	void add_rope();

	operation *get_latest_added_operation();


private:

	template<typename T>
	void insert(const T &,rope *);

	operation *start_buf, *end_buf;
	unsigned int capacity;
	operation *current;
	std::vector<rope> ropes;

	iterator begin();
	iterator end();
	iterator get_new_location();



};

#endif
