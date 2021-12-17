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
		Ret
	};

	Types type;
	

	/* falls variable rvalue ist, ist sie ein wert und keine variable */
	std::vector<std::string> variables;
	function *call, &freference;

	std::string left,right;

	virtual variable *execute();
	virtual ~operation();

	operation(Types , const std::string &, const std::string &, function &);
	operation(Types ,function *, const std::vector<std::string> &, function &);

private:
	virtual variable *executeOperation(variable *,variable *) = 0;
	
	
};


class Add: public operation{
	variable *executeOperation(variable *,variable *);
public:
	Add(operation *,operation *);
	Add(variable *,operation *);
	Add(operation *,variable *);
	Add(variable *,variable *);
};
class Minus: public operation{
	variable *executeOperation(variable *,variable *);
	Minus(operation *,operation *);
	Minus(variable *,operation *);
	Minus(operation *,variable *);
	Minus(variable *,variable *);
};
class Divide: public operation{
	variable *executeOperation(variable *,variable *);
	Divide(operation *,operation *);
	Divide(variable *,operation *);
	Divide(operation *,variable *);
	Divide(variable *,variable *);
};
class Times: public operation{
	variable *executeOperation(variable *,variable *);
	Times(operation *,operation *);
	Times(variable *,operation *);
	Times(operation *,variable *);
	Times(variable *,variable *);
};
class Or: public operation{
	variable *executeOperation(variable *,variable *);
	Or(operation *,operation *);
	Or(variable *,operation *);
	Or(operation *,variable *);
	Or(variable *,variable *);
};
class And: public operation{
	variable *executeOperation(variable *,variable *);
	And(operation *,operation *);
	And(variable *,operation *);
	And(operation *,variable *);
	And(variable *,variable *);
};
class Xor: public operation{
	variable *executeOperation(variable *,variable *);
	Xor(operation *,operation *);
	Xor(variable *,operation *);
	Xor(operation *,variable *);
	Xor(variable *,variable *);
};
class Neg: public operation{
	variable *executeOperation(variable *,variable *);
	Neg(operation *);
	Neg(variable *);
};
class Dec: public operation{
	variable *executeOperation(variable *,variable *);
	Dec(variable *);
};
class Inc: public operation{
	variable *executeOperation(variable *,variable *);
	Inc(variable *);
};
class Call: public operation{
	variable *executeOperation(variable *,variable *);
	Call(function *,const std::vector<variable *> &);
	variable *execute();
};
class Equal: public operation{
	variable *executeOperation(variable *,variable *);
	Equal(variable *,operation *);
	Equal(variable *,variable *);
};
class Ret: public operation{
	variable *executeOperation(variable *,variable *);
	Ret(variable *);
	variable *execute();
};

#endif
