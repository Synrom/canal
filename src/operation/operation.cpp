#include <canal/variable.h>
#include <canal/operation.h>
#include <canal/debugger.h>
#include <string>

operation::~operation(){
	debug("deconstructing operation");
}

operation::operation(Types _type,const std::string &l,const std::string &r,function &func): freference(func) {
	debug("constructing operation");
	left = l;
	right = r;
	type = _type;
	call = NULL;
}



operation::operation(Types _type, function *f, const std::vector<std::string> &v, function &func): call(f) , freference(func), variables(v) {
	debug("constructing operation");
	type = _type;
}


Add::Add(const std::string &left, const std::string &right, function &f) : operation(operation::Add,left,right,f) { 
	debug("creating Add operation");
}

void Add::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Add operation");
	left->Plus(where, right);
}

Minus::Minus(const std::string &left, const std::string &right, function &f) : operation(operation::Minus,left,right,f) { 
	debug("creating Minus operation");
}

void Minus::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Minus operation");
	left->Minus(where, right);
}

Times::Times(const std::string &left, const std::string &right, function &f) : operation(operation::Times,left,right,f) { 
	debug("creating Times operation");
}

void Times::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Times operation");
	left->Times(where, right);
}

Divide::Divide(const std::string &left, const std::string &right, function &f) : operation(operation::Divide,left,right,f) { 
	debug("creating Divide operation");
}

void Divide::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Divide operation");
	left->Divide(where, right);
}

And::And(const std::string &left, const std::string &right, function &f) : operation(operation::And,left,right,f) { 
	debug("creating And operation");
}

void And::executeOperation(variable *left, variable *right, variable *where){
	debug("calling And operation");
	left->And(where, right);
}

Or::Or(const std::string &left, const std::string &right, function &f) : operation(operation::Or,left,right,f) { 
	debug("creating Or operation");
}

void Or::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Or operation");
	left->Or(where, right);
}

Xor::Xor(const std::string &left, const std::string &right, function &f) : operation(operation::Xor,left,right,f) { 
	debug("creating Xor operation");
}

void Xor::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Xor operation");
	left->Xor(where, right);
}

Inc::Inc(const std::string &left, function &f) : operation(operation::Inc,left,"",f) { 
	debug("creating Inc operation");
}

void Inc::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Inc executeOperation which is really weird");
}

Dec::Dec(const std::string &left, function &f) : operation(operation::Dec,left,"",f) { 
	debug("creating Dec operation");
}

void Dec::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Dec executeOperation which is really weird");
}

Neg::Neg(const std::string &left, function &f) : operation(operation::Dec,left,"",f) { 
	debug("creating Neg operation");
}

void Neg::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Neg executeOperation which is really weird");
}


Call::Call(function *c, const std::vector<std::string> &p, function &f) : operation(operation::Call, c, p ,f){
	debug("creating a Call operator");
}

void Call::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Call executeOperation which is really weird");
}

Equal::Equal(const std::string &left, const std::string &right, function &f): operation(operation::Equal, left, right, f){
	debug("creating an Equal operator");
}

void Equal::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Equal executeOperation which is really weird");
}

Ret::Ret(const std::string &left, function &f): operation(operation::Equal, left, "", f){
	debug("creating a Ret operator");
}

void Ret::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Ret executeOperation which is really weird");
}


