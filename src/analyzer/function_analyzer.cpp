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
#include <clang/AST/OperationKinds.h>

bool canal_AST_analyzer::VisitVarDecl(clang::VarDecl *var_decl){

	
	std::string var_name = var_decl->getNameAsString();
	info("found declination statement of %s",var_name.c_str());
	
	std::string var_type = var_decl->getType().getAsString();
	info("type of that variable is %s",var_type.c_str());

	addVar(var_name, var_type);

	if(!(var_decl->isLocalVarDecl())){
		current_function->pvariables.emplace_back(var_name);
		return true;
	}

	thisIsFollowupForAVarDecl = true;	

	return true;
}

bool canal_AST_analyzer::VisitUnaryOperator(clang::UnaryOperator *un_op){
	info("visiting Unary Operator");

	switch(un_op->getOpcode()){
		case clang::UnaryOperatorKind::UO_Minus:
			thisIsFollowupOfaMinus = true;
			thisIsFollowupOfUnaryOperator = true;
			break;
		default:
			info("UnaryOperator %s is yet not implemented",clang::UnaryOperator::getOpcodeStr(un_op->getOpcode()).bytes_begin());
			break;
	}

	return true;
}

bool canal_AST_analyzer::VisitDeclRefExpr(clang::DeclRefExpr *decl_ref){
	info("visting DeclRefExpr");
	
	std::string var_name = decl_ref->getFoundDecl()->getNameAsString();

	info("DeclRefExpr var_name = %s",var_name.c_str());

	current_function->operations.push_back(VarPush(var_name,*current_function));

	return true;
}

bool canal_AST_analyzer::VisitIntegerLiteral(clang::IntegerLiteral *in_lt){
	info("visiting integer literal");
	
	signed long long literal = in_lt->getValue().getLimitedValue();

	if(thisIsFollowupForAVarDecl){
		info("this is follow up of VarDecl so we need to add an = operation first :)");

		std::string var_name = current_function->current_vstance->get_latest_added_var()->name;

		current_function->operations.push_back(Equal(*current_function));
		current_function->operations.push_back(VarPush(var_name,*current_function));
		
		thisIsFollowupForAVarDecl = false;
	}
	if(thisIsFollowupOfUnaryOperator){
		if(thisIsFollowupOfaMinus){
			literal *= -1;
			thisIsFollowupOfaMinus = false;
		}
		thisIsFollowupOfUnaryOperator = false;
	}

	current_function->operations.push_back(IntLiteral(literal,*current_function));

	return true;
}


bool canal_AST_analyzer::VisitBinaryOperator(clang::BinaryOperator *bn_op){
	
	if(bn_op->isComparisonOp()){
		// to be implemented in the future
		return true;
	}
	
	if(thisIsFollowupForAVarDecl && bn_op->getOpcode() != clang::BinaryOperatorKind::BO_Assign){
		info("this is follow up of VarDecl so we need to add an = operation first :)");

		std::string var_name = current_function->current_vstance->get_latest_added_var()->name;

		current_function->operations.push_back(Equal(*current_function));
		current_function->operations.push_back(VarPush(var_name,*current_function));
		
		thisIsFollowupForAVarDecl = false;
	}

	switch(bn_op->getOpcode()){
		case clang::BinaryOperatorKind::BO_Add:
			debug("found Add operator");
			current_function->operations.push_back(Add(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_Sub:
			debug("found Minus operator");
			current_function->operations.push_back(Minus(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_Div:
			debug("found Divide operator");
			current_function->operations.push_back(Divide(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_Mul:
			debug("found Times operator");
			current_function->operations.push_back(Times(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_Or:
			debug("found Or operator");
			current_function->operations.push_back(Or(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_And:
			debug("found And operator");
			current_function->operations.push_back(And(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_Xor:
			debug("found Xor operator");
			current_function->operations.push_back(Xor(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_Assign:
			debug("found Equal operator");
			current_function->operations.push_back(Equal(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_Shl:
			debug("found Shl operator");
			current_function->operations.push_back(Shl(*current_function));
			break;
		case clang::BinaryOperatorKind::BO_Shr:
			debug("found Shr operator");
			current_function->operations.push_back(Shr(*current_function));
			break;
		default:
			info("%s is not yet implemented in VisitBinaryOperator",clang::BinaryOperator::getOpcodeStr(bn_op->getOpcode()).bytes_begin());
			break;
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
