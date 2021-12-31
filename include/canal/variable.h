


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


	
	virtual void Plus(variable *,variable *) = 0;
	virtual void Minus(variable *,variable *) = 0;
	virtual void Times(variable *,variable *) = 0;
	virtual void Divide(variable *,variable *) = 0;
	virtual void And(variable *,variable *) = 0;
	virtual void Or(variable *,variable *) = 0;
	virtual void Xor(variable *,variable *) = 0;
	virtual void Neg(variable *) = 0;
	virtual void Inc() = 0;
	virtual void Dec() = 0;
	
	
};

class signedint: public variable{
public:
	signedint(const std::string &, signed int );
	signedint(const variable *);
	~signedint();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class unsignedint: public variable{
public:
	unsignedint(const std::string &, unsigned int );
	unsignedint(const variable *);
	~unsignedint();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class signedchar: public variable{
public:
	signedchar(const std::string &, signed char );
	signedchar(const variable *);
	~signedchar();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class unsignedchar: public variable{
public:
	unsignedchar(const std::string &, unsigned char );
	unsignedchar(const variable *);
	~unsignedchar();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};

class signedshort: public variable{
public:
	signedshort(const std::string &, signed short );
	signedshort(const variable *);
	~signedshort();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class unsignedshort: public variable{
public:
	unsignedshort(const std::string &, unsigned short );
	unsignedshort(const variable *);
	~unsignedshort();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class signedlong: public variable{
public:
	signedlong(const std::string &, signed long );
	signedlong(const variable *);
	~signedlong();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class unsignedlong: public variable{
public:
	unsignedlong(const std::string &, unsigned long );
	unsignedlong(const variable *);
	~unsignedlong();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class unsignedlonglong: public variable{
public:
	unsignedlonglong(const std::string &, unsigned long long );
	unsignedlonglong(const variable *);
	~unsignedlonglong();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class signedlonglong: public variable{
public:
	signedlonglong(const std::string &, signed long long );
	signedlonglong(const variable *);
	~signedlonglong();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};

class _float: public variable{
public:
	_float(const std::string &, float );
	_float(const variable *);
	~_float();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class _double: public variable{
public:
	_double(const std::string &, double );
	_double(const variable *);
	~_double();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class longdouble: public variable{
public:
	longdouble(const std::string &, long double );
	longdouble(const variable *);
	~longdouble();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};


class pointer: public variable{
public:
	pointer(const std::string & , unsigned long long, unsigned int);
	pointer(const variable *);
	~pointer();
	void Plus(variable *,variable *);
	void Minus(variable *,variable *);
	void Times(variable *,variable *);
	void Divide(variable *,variable *);
	void And(variable *,variable *);
	void Or(variable *,variable *);
	void Xor(variable *,variable *);
	void Neg(variable *);
	void Inc();
	void Dec();
};

#endif
