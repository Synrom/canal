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
		Shl,
		Shr,
		Neg, // TODO in function_analyzer
		Dec, // TODO in function_analyzer
		Inc, // TODO in function_analyzer
		Call,
		Equal,
		Ret,
		Switch,
		Next_Switch,
		End_Switch,
		IntLiteral,
		VarPush
	};

	Types type;
	

	function *call{NULL}, &freference;

	variable::Data literal;
	std::string var_name{""};

	virtual ~operation();

	operation(Types, function &);
	operation(Types ,function *, function &);

	virtual void execute();
	virtual void clone(operation *) const = 0;
	virtual void print();
	virtual void print_simple();


private:
	virtual void executeOperation(variable *,variable *,variable *) = 0;

	
	
};

class VarPush: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	VarPush(const std::string &, function &);
	VarPush(operation *);
	VarPush(const VarPush &);
	void clone(operation *) const;
	void execute();
	void print();
	void print_simple();
};

class IntLiteral: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	IntLiteral(signed long long, function &);
	IntLiteral(operation *);
	IntLiteral(const IntLiteral &);
	void clone(operation *) const;
	void execute();
	void print();
	void print_simple();
};

class Shl: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Shl(function &);
	Shl(operation *);
	Shl(const Shl &);
	void clone(operation *) const;
};

class Shr: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Shr(function &);
	Shr(operation *);
	Shr(const Shr &);
	void clone(operation *) const;
};

class Add: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Add(function &);
	Add(operation *);
	Add(const Add &);
	void clone(operation *) const;
};
class Minus: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Minus(function &);
	Minus(operation *);
	Minus(const Minus &);
	void clone(operation *) const;
};
class Divide: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Divide(function &);
	Divide(operation *);
	Divide(const Divide &);
	void clone(operation *) const;
};
class Times: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Times(function &);
	Times(operation *);
	Times(const Times &);
	void clone(operation *) const;
};
class Or: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Or(function &);
	Or(operation *);
	Or(const Or &);
	void clone(operation *) const;
};
class And: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	And(function &);
	And(operation *);
	And(const And &);
	void clone(operation *) const;
};
class Xor: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Xor(function &);
	Xor(operation *);
	Xor(const Xor &);
	void clone(operation *) const;
};
class Neg: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Neg(function &);
	Neg(operation *);
	Neg(const Neg &);
	void clone(operation *) const;
};
class Dec: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Dec(function &);
	Dec(operation *);
	Dec(const Dec &);
	void clone(operation *) const;
};
class Inc: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Inc(function &);
	Inc(operation *);
	Inc(const Inc &);
	void clone(operation *) const;
};
class Call: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Call(function *, function &);
	Call(operation *);
	Call(const Call &);
	void clone(operation *) const;
	void print();
	void print_simple();
	void execute();
};
class Equal: public operation{
	void executeOperation(variable *,variable *,variable *);
	void execute();
public:
	Equal(function &);
	Equal(operation *);
	Equal(const Equal &);
	void clone(operation *) const;
	void print();
};
class Ret: public operation{
	void executeOperation(variable *,variable *,variable *);
public:
	Ret(function &);
	Ret(operation *);
	Ret(const Ret &);
	void clone(operation *) const;
	void print();
	void print_simple();
	void execute();
};

#endif
