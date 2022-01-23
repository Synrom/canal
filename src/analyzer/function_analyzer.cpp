#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#include <canal/operation.h>
#include <canal/operation_stack.h>
#include <canal/function.h>
#include <canal/analyzer.h>
#include <canal/debugger.h>
#include <canal/root_scope.h>

bool canal_AST_analyzer::VisitVarDecl(clang::VarDecl *var_decl){

	std::string var_name = var_decl->getNameAsString();
	info("found declination statement of %s",var_name.c_str());
	
	std::string var_type = var_decl->getType().getAsString();
	info("type of that variable is %s",var_type.c_str());

	addVar(var_name, var_type);

	thisIsFollowupForAVarDecl = true;	

	return true;
}

bool canal_AST_analyzer::VisitBinaryOperator(clang::BinaryOperator *bn_op){
	
	info("analyzing binary operation");
	
	if(thisIsFollowupForAVarDecl){
		info("this is follow up of VarDecl so we need to add an = operation first :)");
		thisIsFollowupForAVarDecl = false;
	}


	return true;
}



void canal_AST_analyzer::addVar(const std::string &name, std::string &type){
	if(type == "double"){
		current_function->current_vstance->add_var(name, (double) 0);
		current_type = variable::_double;
	}else if(type == "float"){
		current_function->current_vstance->add_var(name, (float) 0);
		current_type = variable::_float;
	}else if(type == "long double"){
		current_function->current_vstance->add_var(name, (long double) 0);
		current_type = variable::longdouble;
	}else if(type == "signed char"){
		current_function->current_vstance->add_var(name, (signed char) 0);
		current_type = variable::signedchar;
	}else if(type == "int"){
		current_function->current_vstance->add_var(name, (int) 0);
		current_type = variable::signedint;
	}else if(type == "long"){
		current_function->current_vstance->add_var(name, (long) 0);
		current_type = variable::signedlong;
	}else if(type == "long long"){
		current_function->current_vstance->add_var(name, (long long) 0);
		current_type = variable::signedlonglong;
	}else if(type == "short"){
		current_function->current_vstance->add_var(name, (short) 0);
		current_type = variable::signedshort;
	}else if(type == "unsigned char"){
		current_function->current_vstance->add_var(name, (unsigned char) 0);
		current_type = variable::unsignedchar;
	}else if(type == "unsigned int"){
		current_function->current_vstance->add_var(name, (unsigned int) 0);
		current_type = variable::unsignedint;
	}else if(type == "unsigned long"){
		current_function->current_vstance->add_var(name, (unsigned long) 0);
		current_type = variable::unsignedlong;
	}else if(type == "unsigned long long"){
		current_function->current_vstance->add_var(name, (unsigned long long) 0);
		current_type = variable::unsignedlonglong;
	}else if(type == "unsigned short"){
		current_function->current_vstance->add_var(name, (unsigned short) 0);
		current_type = variable::unsignedshort;
	}else if(type.back() == '*'){
		type.pop_back();
		type.pop_back();
		current_type = variable::pointer;
		if(type == "double"){
			current_function->current_vstance->add_var(name, 0, sizeof(double));
		}else if(type == "float"){
			current_function->current_vstance->add_var(name, 0, sizeof(float));
		}else if(type == "long double"){
			current_function->current_vstance->add_var(name, 0, sizeof(long double));
		}else if(type == "signed char"){
			current_function->current_vstance->add_var(name, 0, sizeof(signed char));
		}else if(type == "int"){
			current_function->current_vstance->add_var(name, 0, sizeof(int));
		}else if(type == "long"){
			current_function->current_vstance->add_var(name, 0, sizeof(long));
		}else if(type == "long long"){
			current_function->current_vstance->add_var(name, 0, sizeof(long long));
		}else if(type == "short"){
			current_function->current_vstance->add_var(name, 0, sizeof(short));
		}else if(type == "unsigned char"){
			current_function->current_vstance->add_var(name, 0, sizeof(unsigned char));
		}else if(type == "unsigned int"){
			current_function->current_vstance->add_var(name, 0, sizeof(unsigned int));
		}else if(type == "unsigned long"){
			current_function->current_vstance->add_var(name, 0, sizeof(unsigned long));
		}else if(type == "unsigned long long"){
			current_function->current_vstance->add_var(name, 0, sizeof(unsigned long long));
		}else if(type == "unsigned short"){
			current_function->current_vstance->add_var(name, 0, sizeof(unsigned short));
		}else{
			warning("type %s is not implemented yet in the analyzer",type.c_str());
		}
	}else{
		warning("type %s is not implemented yet in the analyzer",type.c_str());
	}
}
