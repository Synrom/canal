#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <vector>

#include "variable.h"
#include "function.h"

class function;

class operation{
public:
	
	enum Types{
		Add,
		Minus,
		Divide,
		Times,
		Or,
		And,
		Xor,
		Neg,
		Dec,
		Inc,
		Call,
		Equal,
		Ret,
		Switch,
		Next_Switch,
		End_Switch,

	};

	Types type;
	

	std::vector<std::string> variables;
	function *call, &freference;

	std::string left,right;

	virtual variable *execute();
	virtual ~operation();

	operation(Types , const std::string &, const std::string &, function &);
	operation(Types ,function *, const std::vector<std::string> &, function &);

private:
	virtual void executeOperation(variable *,variable *,variable *) = 0;
	
	
};


class Add: public operation{
	void executeOperation(variable *,variable *,variable *);
	Add(const std::string &, const std::string &, function &);
};
class Minus: public operation{
	void executeOperation(variable *,variable *,variable *);
	Minus(const std::string &, const std::string &, function &);
};
class Divide: public operation{
	void executeOperation(variable *,variable *,variable *);
	Divide(const std::string &, const std::string &, function &);
};
class Times: public operation{
	void executeOperation(variable *,variable *,variable *);
	Times(const std::string &, const std::string &, function &);
};
class Or: public operation{
	void executeOperation(variable *,variable *,variable *);
	Or(const std::string &, const std::string &, function &);
};
class And: public operation{
	void executeOperation(variable *,variable *,variable *);
	And(const std::string &, const std::string &, function &);
};
class Xor: public operation{
	void executeOperation(variable *,variable *,variable *);
	Xor(const std::string &, const std::string &, function &);
};
class Neg: public operation{
	void executeOperation(variable *,variable *,variable *);
	Neg(const std::string &, function &);
};
class Dec: public operation{
	void executeOperation(variable *,variable *,variable *);
	Dec(const std::string &, function &);
};
class Inc: public operation{
	void executeOperation(variable *,variable *,variable *);
	Inc(const std::string &, function &);
};
class Call: public operation{
	void executeOperation(variable *,variable *,variable *);
	Call(function *,const std::vector<std::string> &, function &);
};
class Equal: public operation{
	void executeOperation(variable *,variable *,variable *);
	Equal(const std::string &, const std::string &, function &);
};
class Ret: public operation{
	void executeOperation(variable *,variable *,variable *);
	Ret(const std::string &, function &);
};

#endif
