


#ifndef VARIABLE_H
#define VARIABLE_H

#define INFTY -1

#include <iostream>
#include <string>

class variable{
public:
	std::string name;
	unsigned int size;

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
		signedchar,
		unsignedchar,
		signedshort,
		unsignedshort,
		signedint,
		unsignedint,
		signedlong,
		unsignedlong,
		signedlonglong,
		unsignedlonglong,
		_float,
		_double,
		longdouble,
		pointer,
	};

	
	Types type;

	variable(const std::string &);
	virtual ~variable();


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
	
	virtual bool operator > (variable *) = 0;
	virtual void copy_to_pointer(variable *) = 0;
};

class signedint: public variable{
public:
	signedint(const std::string &, signed int );
	signedint(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class unsignedint: public variable{
public:
	unsignedint(const std::string &, unsigned int );
	unsignedint(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class signedchar: public variable{
public:
	signedchar(const std::string &, signed char );
	signedchar(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class unsignedchar: public variable{
public:
	unsignedchar(const std::string &, unsigned char );
	unsignedchar(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};

class signedshort: public variable{
public:
	signedshort(const std::string &, signed short );
	signedshort(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class unsignedshort: public variable{
public:
	unsignedshort(const std::string &, unsigned short );
	unsignedshort(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class signedlong: public variable{
public:
	signedlong(const std::string &, signed long );
	signedlong(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class unsignedlong: public variable{
public:
	unsignedlong(const std::string &, unsigned long );
	unsignedlong(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class unsignedlonglong: public variable{
public:
	unsignedlonglong(const std::string &, unsigned long long );
	unsignedlonglong(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class signedlonglong: public variable{
public:
	signedlonglong(const std::string &, signed long long );
	signedlonglong(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};

class _float: public variable{
public:
	_float(const std::string &, float );
	_float(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class _double: public variable{
public:
	_double(const std::string &, double );
	_double(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class longdouble: public variable{
public:
	longdouble(const std::string &, long double );
	longdouble(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};


class pointer: public variable{
public:
	pointer(const std::string & , unsigned long long, unsigned int);
	pointer(const variable *);
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
	bool operator > (variable *);
	virtual void copy_to_pointer(variable *);
};

#endif
