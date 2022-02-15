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
#include <clang/AST/Expr.h>
#include <clang/AST/OperationKinds.h>
#include <llvm/Support/Casting.h>

bool isVarinExpr(clang::Expr *expr){
	if(llvm::dyn_cast<clang::ImplicitCastExpr>(expr))
		return true;
	if(llvm::dyn_cast<clang::DeclRefExpr>(expr))
		return true;
	if(llvm::dyn_cast<clang::BinaryOperator>(expr)){
		clang::BinaryOperator *bn_op = llvm::dyn_cast<clang::BinaryOperator>(expr);
		return isVarinExpr(bn_op->getLHS()) || isVarinExpr(bn_op->getRHS());
	}
	if(llvm::dyn_cast<clang::UnaryOperator>(expr)){
		clang::UnaryOperator *un_op = llvm::dyn_cast<clang::UnaryOperator>(expr);
		return isVarinExpr(un_op->getSubExpr());
	}
	return false;
}

bool canal_Compound_classifier::VisitBinaryOperator(clang::BinaryOperator *bn_op){
	if(!Schedule.look_up())
		return true;

	Schedule.increase_child();

	if(type == CodeClassifier::mixed)
		return true;
	
	switch(bn_op->getOpcode()){
		case clang::BinaryOperatorKind::BO_Add:
		case clang::BinaryOperatorKind::BO_Mul:
		case clang::BinaryOperatorKind::BO_Or:
		case clang::BinaryOperatorKind::BO_Xor:
		case clang::BinaryOperatorKind::BO_Shl:
		case clang::BinaryOperatorKind::BO_AddAssign:
		case clang::BinaryOperatorKind::BO_MulAssign:
		case clang::BinaryOperatorKind::BO_OrAssign:
		case clang::BinaryOperatorKind::BO_XorAssign:
			if(visitedDecreasingOp)
				type = CodeClassifier::mixed;
			else
				type = CodeClassifier::onlyIncrease;
			break;
		case clang::BinaryOperatorKind::BO_Sub:
		case clang::BinaryOperatorKind::BO_Div:
		case clang::BinaryOperatorKind::BO_And:
		case clang::BinaryOperatorKind::BO_Assign:
		case clang::BinaryOperatorKind::BO_Shr:
			visitedDecreasingOp = true;
			if(type == CodeClassifier::onlyIncrease)
				type = CodeClassifier::mixed;
			break;

		default:
			info("%s is not yet implemented in canal_Compound_classifier::VisitBinaryOperator",clang::BinaryOperator::getOpcodeStr(bn_op->getOpcode()).bytes_begin());
			break;
	}
	
	return true;
}

bool canal_IfStmnt_classifier::VisitBinaryOperator(clang::BinaryOperator *bn_op){

	if(!Schedule.look_up())
		return true;

	if(type.back() == CodeClassifier::mixed)
		return true;

	switch(bn_op->getOpcode()){
		case clang::BinaryOperatorKind::BO_GE:
		case clang::BinaryOperatorKind::BO_GT:
			info("%s should be > or >=",clang::BinaryOperator::getOpcodeStr(bn_op->getOpcode()).bytes_begin());
			if(isVarinExpr(bn_op->getLHS()))
				isElseNeutral = false;
			if(isVarinExpr(bn_op->getRHS())){
				visitedDecreasingOp = true;
				if(type.back() == CodeClassifier::onlyIncrease)
					type.back() = CodeClassifier::mixed;
			}
			break;
		case clang::BinaryOperatorKind::BO_LE:
		case clang::BinaryOperatorKind::BO_LT:
			info("%s should be < or <=",clang::BinaryOperator::getOpcodeStr(bn_op->getOpcode()).bytes_begin());
			if(isVarinExpr(bn_op->getRHS()))
				isElseNeutral = false;
			if(isVarinExpr(bn_op->getLHS())){
				visitedDecreasingOp = true;
				if(type.back() == CodeClassifier::onlyIncrease)
					type.back() = CodeClassifier::mixed;
			}
			break;
		case clang::BinaryOperatorKind::BO_EQ:
			info("%s should be ==",clang::BinaryOperator::getOpcodeStr(bn_op->getOpcode()).bytes_begin());
			if(isVarinExpr(bn_op->getLHS()) || isVarinExpr(bn_op->getRHS())){
				visitedDecreasingOp = true;
				if(type.back() == CodeClassifier::onlyIncrease)
					type.back() = CodeClassifier::mixed;
			}
			break;
		default:
			info("%s is not yet implemented in canal_IfStmnt_classifier::VisitBinaryOperator",clang::BinaryOperator::getOpcodeStr(bn_op->getOpcode()).bytes_begin());
			break;
	}
	return true;
}


canal_IfStmnt_classifier::canal_IfStmnt_classifier(clang::ASTContext *c) : context(c) {
	debug("creating IfStmnt classifier");
}

canal_Compound_classifier::canal_Compound_classifier(clang::ASTContext *c,scheduler *s): context(c), Schedule(s) {
	debug("creating Compound Statement classifier");
}

