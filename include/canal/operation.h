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

	virtual ~operation();

	operation(Types , const std::string &, const std::string &, function &);
	operation(Types ,function *, const std::vector<std::string> &, function &);

private:
	virtual void executeOperation(variable *,variable *,variable *) = 0;
	
	
};


class Add: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Add(const std::string &, const std::string &, function &);
	Add(operation *);
	Add(const Add &);
};
class Minus: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Minus(const std::string &, const std::string &, function &);
	Minus(operation *);
	Minus(const Minus &);
};
class Divide: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Divide(const std::string &, const std::string &, function &);
	Divide(operation *);
	Divide(const Divide &);
};
class Times: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Times(const std::string &, const std::string &, function &);
	Times(operation *);
	Times(const Times &);
};
class Or: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Or(const std::string &, const std::string &, function &);
	Or(operation *);
	Or(const Or &);
};
class And: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	And(const std::string &, const std::string &, function &);
	And(operation *);
	And(const And &);
};
class Xor: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Xor(const std::string &, const std::string &, function &);
	Xor(operation *);
	Xor(const Xor &);
};
class Neg: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Neg(const std::string &, function &);
	Neg(operation *);
	Neg(const Neg &);
};
class Dec: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Dec(const std::string &, function &);
	Dec(operation *);
	Dec(const Dec &);
};
class Inc: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Inc(const std::string &, function &);
	Inc(operation *);
	Inc(const Inc &);
};
class Call: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Call(function *,const std::vector<std::string> &, function &);
	Call(operation *);
	Call(const Call &);
};
class Equal: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Equal(const std::string &, const std::string &, function &);
	Equal(operation *);
	Equal(const Equal &);
};
class Ret: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Ret(const std::string &, function &);
	Ret(operation *);
	Ret(const Ret &);
};

#endif
