


#ifndef VARIABLE_H
#define VARIABLE_H

#define INFTY -1

#include <iostream>
#include <string>

class variable{
public:
	std::string name;
	unsigned int size;

	/* value is always the theOratically possible highest value */
	/* bei pointern ist value die capacity */
	// TODO: value sollte union sein

	union Data{
		signed char signedchar;
		unsigned char unsignedchar;
		signed short signedshort;
		unsigned short unsignedshort;
		signed int signedint;
		unsigned int unsignedint;
		signed long signedlong;
		unsigned long unsignedlong;
		signed long long signedlonglong;
		unsigned long long unsignedlonglong;
		float _float;
		double _double;
		long double longdouble;
	};

		
	union Data value;


	enum Types {
		rvalue,
		lvalue
	};

	
	Types type;

	variable(std::string && , Types  );
	variable(Types , signed char);
	variable(Types , unsigned char);
	variable(Types ,signed short );
	variable(Types ,unsigned short);
	variable(Types ,signed int );
	variable(Types ,unsigned int );
	variable(Types ,signed long );
	variable(Types ,unsigned long );
	variable(Types ,signed long long );
	variable(Types ,unsigned long long );
	variable(Types ,float );
	variable(Types ,double );
	variable(Types ,long double );
	variable(Types );
	virtual ~variable();

	/* hier muss noch die operation uebergeben werden */
	variable *handleOperation(variable *);

	virtual variable *Plus(variable *) = 0;
	virtual variable *Minus(variable *) = 0;
	virtual variable *Times(variable *) = 0;
	virtual variable *Divide(variable *) = 0;
	virtual variable *And(variable *) = 0;
	virtual variable *Or(variable *) = 0;
	virtual variable *Xor(variable *) = 0;
	virtual variable *Neg() = 0;
	virtual variable *Inc() = 0;
	virtual variable *Dec() = 0;

};

class signedint: public variable{
public:
	signedint(Types ,signed int );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class unsignedint: public variable{
public:
	unsignedint(Types ,unsigned int );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class signedchar: public variable{
public:
	signedchar(Types , signed char );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class unsignedchar: public variable{
public:
	unsignedchar(Types , unsigned char );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};

class signedshort: public variable{
public:
	signedshort(Types , signed short );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class unsignedshort: public variable{
public:
	unsignedshort(Types , unsigned short );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class signedlong: public variable{
public:
	signedlong(Types , signed long );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class unsignedlong: public variable{
public:
	unsignedlong(Types , unsigned long );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class unsignedlonglong: public variable{
public:
	unsignedlonglong(Types , unsigned long long );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class signedlonglong: public variable{
public:
	signedlonglong(Types , signed long long );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};

class _float: public variable{
public:
	_float(Types , float );
	_float(Types , unsigned int );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class _double: public variable{
public:
	_double(Types , double );
	_double(Types , unsigned int );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class longdouble: public variable{
public:
	longdouble(Types , long double);
	longdouble(Types , unsigned int );
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};


class pointer: public variable{
public:
	pointer(Types , unsigned long long, unsigned int);
	variable *Plus(variable *);
	variable *Minus(variable *);
	variable *Times(variable *);
	variable *Divide(variable *);
	variable *And(variable *);
	variable *Or(variable *);
	variable *Xor(variable *);
	variable *Neg();
	variable *Inc();
	variable *Dec();
};

#endif
