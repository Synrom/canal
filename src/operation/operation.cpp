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

Add::Add(operation *cpy) : operation(operation::Add,cpy->left,cpy->right,cpy->freference) { 
	debug("creating Add operation");
}

Add::Add(const Add &cpy) : operation(operation::Add,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Add operation");
}

void Add::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Add operation");
	left->Plus(where, right);
}

Minus::Minus(const std::string &left, const std::string &right, function &f) : operation(operation::Minus,left,right,f) { 
	debug("creating Minus operation");
}

Minus::Minus(const Minus &cpy) : operation(operation::Minus,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Minus operation");
}

Minus::Minus(operation *cpy) : operation(operation::Minus,cpy->left,cpy->right,cpy->freference) { 
	debug("creating Minus operation");
}

void Minus::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Minus operation");
	left->Minus(where, right);
}

Times::Times(const std::string &left, const std::string &right, function &f) : operation(operation::Times,left,right,f) { 
	debug("creating Times operation");
}

Times::Times(const Times &cpy) : operation(operation::Times,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Times operation");
}

Times::Times(operation *cpy) : operation(operation::Times,cpy->left,cpy->right,cpy->freference) { 
	debug("creating Times operation");
}

void Times::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Times operation");
	left->Times(where, right);
}

Divide::Divide(const std::string &left, const std::string &right, function &f) : operation(operation::Divide,left,right,f) { 
	debug("creating Divide operation");
}

Divide::Divide(const Divide &cpy) : operation(operation::Divide,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Times operation");
}

Divide::Divide(operation *cpy) : operation(operation::Divide,cpy->left,cpy->right,cpy->freference) { 
	debug("creating Divide operation");
}

void Divide::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Divide operation");
	left->Divide(where, right);
}

And::And(const std::string &left, const std::string &right, function &f) : operation(operation::And,left,right,f) { 
	debug("creating And operation");
}

And::And(const And &cpy) : operation(operation::And,cpy.left,cpy.right,cpy.freference) { 
	debug("creating And operation");
}

And::And(operation *cpy) : operation(operation::And,cpy->left,cpy->right,cpy->freference) { 
	debug("creating And operation");
}

void And::executeOperation(variable *left, variable *right, variable *where){
	debug("calling And operation");
	left->And(where, right);
}

Or::Or(const std::string &left, const std::string &right, function &f) : operation(operation::Or,left,right,f) { 
	debug("creating Or operation");
}

Or::Or(const Or &cpy) : operation(operation::Or,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Or operation");
}

Or::Or(operation *cpy) : operation(operation::Or,cpy->left,cpy->right,cpy->freference) { 
	debug("creating Or operation");
}

void Or::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Or operation");
	left->Or(where, right);
}

Xor::Xor(const std::string &left, const std::string &right, function &f) : operation(operation::Xor,left,right,f) { 
	debug("creating Xor operation");
}

Xor::Xor(const Xor &cpy) : operation(operation::Xor,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Xor operation");
}
Xor::Xor(operation *cpy) : operation(operation::Xor,cpy->left,cpy->right,cpy->freference) { 
	debug("creating Xor operation");
}

void Xor::executeOperation(variable *left, variable *right, variable *where){
	debug("calling Xor operation");
	left->Xor(where, right);
}

Inc::Inc(const std::string &left, function &f) : operation(operation::Inc,left,"",f) { 
	debug("creating Inc operation");
}

Inc::Inc(const Inc &cpy) : operation(operation::Inc,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Inc operation");
}

Inc::Inc(operation *cpy) : operation(operation::Inc,cpy->left,"",cpy->freference) { 
	debug("creating Inc operation");
}

void Inc::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Inc executeOperation which is really weird");
}

Dec::Dec(const std::string &left, function &f) : operation(operation::Dec,left,"",f) { 
	debug("creating Dec operation");
}

Dec::Dec(const Dec &cpy) : operation(operation::Dec,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Dec operation");
}

Dec::Dec(operation *cpy) : operation(operation::Dec,cpy->left,"",cpy->freference) { 
	debug("creating Dec operation");
}

void Dec::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Dec executeOperation which is really weird");
}

Neg::Neg(const std::string &left, function &f) : operation(operation::Dec,left,"",f) { 
	debug("creating Neg operation");
}

Neg::Neg(const Neg &cpy) : operation(operation::Neg,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Neg operation");
}

Neg::Neg(operation *cpy) : operation(operation::Neg,cpy->left,"",cpy->freference) { 
	debug("creating Neg operation");
}

void Neg::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Neg executeOperation which is really weird");
}


Call::Call(function *c, const std::vector<std::string> &p, function &f) : operation(operation::Call, c, p ,f){
	debug("creating a Call operator");
}

Call::Call(operation *cpy) : operation(operation::Call, cpy->call , cpy->variables, cpy->freference){
	debug("creating a Call operator");
}

Call::Call(const Call &cpy) : operation(operation::Call,cpy.call,cpy.variables,cpy.freference) { 
	debug("creating Call operation");
}


void Call::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Call executeOperation which is really weird");
}

Equal::Equal(const std::string &left, const std::string &right, function &f): operation(operation::Equal, left, right, f){
	debug("creating an Equal operator");
}

Equal::Equal(operation *cpy) : operation(operation::Equal,cpy->left,cpy->right,cpy->freference) { 
	debug("creating Equal operation");
}

Equal::Equal(const Equal &cpy) : operation(operation::Equal,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Equal operation");
}

void Equal::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Equal executeOperation which is really weird");
}

Ret::Ret(const std::string &left, function &f): operation(operation::Equal, left, "", f){
	debug("creating a Ret operator");
}

Ret::Ret(const Ret &cpy) : operation(operation::Ret,cpy.left,cpy.right,cpy.freference) { 
	debug("creating Ret operation");
}

Ret::Ret(operation *cpy) : operation(operation::Equal,cpy->left,"",cpy->freference) { 
	debug("creating Ret operation");
}

void Ret::executeOperation(variable *left, variable *right, variable *where){
	warning("calling Ret executeOperation which is really weird");
}


void operation::execute(){
	debug("operation::execute");

	if(right == ""){
		debug("getting right from result stack in operation::execute");

		if(left == ""){
			
			debug("executing left and right in operation::execute");

			freference.operations.getNext()->execute();
			freference.operations.getNext()->execute();

			debug("getting left also from result stack in operation::execute");

			result right_result = freference.results.pop_result();
			result &left_result = freference.results.get_result(0);


			error_conditional(right_result.get_size() != left_result.get_size(),
					"the sizes (%d and %d) of the results are different in operation::execute",
					right_result.get_size(),left_result.get_size());

			variable *right_iterator = right_result.begin();
			variable *left_iterator = left_result.begin();

			while(left_iterator != left_result.end()){

				debug("%p = %p operation %p\n",left_iterator,left_iterator,right_iterator);
				
				executeOperation(/* left */ left_iterator,
						 /* right */ right_iterator,
						 /* where */ left_iterator);

				right_iterator++;
				left_iterator++;
			}

		}else{
			
			debug("executing right in operation::execute");
			
			freference.operations.getNext()->execute();

			debug("getting variable values for %s (left) in operation::execute",left.c_str());

			result right_result = freference.results.pop_result();
			std::vector<variable *> left_result = freference.current_vstance->get_var(left);
			
			// here we have to reserve space on the result stack for the results

			error_conditional(right_result.get_size() != left_result.size(),
					"the sizes (%d and %ld) of the results are different in operation::execute",
					right_result.get_size(),left_result.size());

			result &result_space = freference.results.push_result(left_result.size());

			auto left_iterator = left_result.begin();
			variable *right_iterator = right_result.begin();
			variable *result_iterator = result_space.begin();

			while(left_iterator != left_result.end()){

				debug("%p = %p operation %p\n",result_iterator,*left_iterator,right_iterator);

				executeOperation(/* left */ *left_iterator,
						 /* right */ right_iterator,
						 /* where */ result_iterator);

				left_iterator++;
				right_iterator++;
				result_iterator++;
			}

		}
	}else{
		debug("getting variable values for %s (right) in operation::execute",right.c_str());

		if(left == ""){
			debug("executing left in operation::execute");
			
			freference.operations.getNext()->execute();

			debug("getting only left from result stack in operation::execute");

			std::vector<variable *> right_result = freference.current_vstance->get_var(right);
			result &left_result = freference.results.get_result(0);

			// here is left_result also the place where the results will be stored

			error_conditional(right_result.size() != left_result.get_size(),
					"the sizes (%ld and %d) of the results are different in operation::execute",
					right_result.size(),left_result.get_size());

			variable *left_iterator = left_result.begin();
			auto right_iterator = right_result.begin();

			while(right_iterator != right_result.end()){

				debug("%p = %p operation %p\n",left_iterator,left_iterator,*right_iterator);

				executeOperation(/* left */  left_iterator,
						 /* right */ *right_iterator,
						 /* where */ left_iterator);

				left_iterator++;
				right_iterator++;
			}

		}else{
			debug("getting variable values for %s (left) in operation::execute",left.c_str());

			std::vector<variable *> right_result = freference.current_vstance->get_var(right);
			std::vector<variable *> left_result = freference.current_vstance->get_var(left);

			// here we need to reserve a result on the result_stack, where the results will be stored

			error_conditional(right_result.size() != left_result.size(),
					"the sizes (%ld and %ld) of the results are different in operation::execute",
					right_result.size(),left_result.size());

			result &result_space = freference.results.push_result(right_result.size());

			auto left_iterator = left_result.begin();
			auto right_iterator = right_result.begin();
			variable *result_iterator = result_space.begin();

			while(left_iterator != left_result.end()){

				debug("%p = %p operation %p\n",result_iterator,*left_iterator,*right_iterator);

				executeOperation(/* left */  *left_iterator,
						 /* right */ *right_iterator,
						 /* where */ result_iterator);

				left_iterator++;
				right_iterator++;
				result_iterator++;
			}

		}
	}

}

void operation::print(){
	if(type == operation::Call){
		printf("call %s(",call->name.c_str());
		for(auto i = variables.begin();i != variables.end();i++)
			printf("%s ,",(*i).c_str());
		printf(")");
		return;
	}
	printf("%s",left.c_str());
	switch(type){
		case operation::Add:
			printf(" + ");
			break;
		case operation::Minus:
			printf(" - ");
			break;
		case operation::Divide:
			printf(" / ");
			break;
		case operation::Times:
			printf(" * ");
			break;
		case operation::Or:
			printf(" | ");
			break;
		case operation::And:
			printf(" & ");
			break;
		case operation::Xor:
			printf(" ^ ");
			break;
		case operation::Neg:
			printf(" ~ ");
			break;
		case operation::Dec:
			printf("-- ");
			break;
		case operation::Inc:
			printf("++ ");
			break;
		case operation::Equal:
			printf(" = ");
			break;
		case operation::Ret:
			printf(" return");
			break;
		case operation::Switch:
			printf("switch");
			break;
		case operation::Next_Switch:
			printf("next_switch");
			break;
		case operation::End_Switch:
			printf("end_switch");
			break;
		default:
			printf("operation isnt implemented in print operation");
	}
	printf("%s",right.c_str());
}
