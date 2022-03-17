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
#include <clang/AST/ASTContext.h>
#include <clang/AST/Expr.h>
#include <clang/AST/OperationKinds.h>
#include <llvm/Support/Casting.h>

canal_IfStmt_analyzer::canal_IfStmt_analyzer(clang::ASTContext *c, scheduler *s,const std::vector<CodeClassifier> &cl, unsigned int count, function *f): canal_dump_AST_Handler(c,s), classifier_type(cl), switch_count(count), current_function(f){
		debug("creating IfStmt analyzer");
}

bool canal_IfStmt_analyzer::VisitIfStmt(clang::IfStmt *if_stmnt){
	if(!Schedule.look_up())
		return true;
	Schedule.increase_child();
	if(isFirstIf){
		isFirstIf = false;
		current_function->operations.down_rope();
		current_function->operations.insert_last_rope(Add_Switch(switch_count,*current_function));
	}else{
		current_function->operations.up_rope();
		current_function->operations.down_rope();
		current_function->operations.insert_last_rope(Next_Switch(*current_function));
		current_classifier_position++;
	}
	visitedIfBeforeCompound = true;
	return true;
}

bool canal_IfStmt_analyzer::VisitCompoundStmt(clang::CompoundStmt *comp){
	if(!Schedule.look_up())
		return true;
	Schedule.increase_child();

	if(!visitedIfBeforeCompound){
		current_function->operations.up_rope();
		current_function->operations.down_rope();
		current_function->operations.insert_last_rope(Next_Switch(*current_function));
		current_classifier_position++;
	}

	canal_dump_AST_Handler dumpHandler(context,&Schedule);
	dumpHandler.TraverseStmt(comp);

	if(classifier_type[current_classifier_position] != CodeClassifier::onlyDecrease){
		canal_AST_analyzer compAnalyzer(context,current_function);
		compAnalyzer.TraverseStmt(comp);
	}

	if(!visitedIfBeforeCompound || current_classifier_position == classifier_type.size() - 1){
		current_function->operations.up_rope();
		current_function->operations.insert_all_ropes(End_Switch(*current_function));
	}

	if(visitedIfBeforeCompound)
		visitedIfBeforeCompound = false;

	return true;
}

bool isExprJustVar(clang::Expr *expr){
	clang::CastExpr *cast{NULL};
	if((cast = llvm::dyn_cast<clang::CastExpr>(expr)) != NULL)
		return isExprJustVar(cast->getSubExpr());
	else if(llvm::dyn_cast<clang::DeclRefExpr>(expr))
		return true;
	return false;
}

bool canal_IfStmt_analyzer::VisitBinaryOperator(clang::BinaryOperator *bn_op){
	if(!Schedule.look_up())
		return true;
	Schedule.increase_child();

	if(bn_op->getOpcode() == clang::BinaryOperatorKind::BO_LOr){
		current_function->operations.add_rope();
		current_function->operations.insert_last_rope(Next_Switch(*current_function));
		return true;
	}else if(classifier_type[current_classifier_position] != CodeClassifier::mixed){
		return true;
	}

	switch(bn_op->getOpcode()){
		// TODO ==, >=, <=, !=, >, < 
		//  -> recognize increments/decrements and accesses
		//
		case clang::BinaryOperatorKind::BO_LT: // <

			canal_classify_term left_classifier(context);
			canal_classify_term right_classifier(context);

			left_classifier.TraverseStmt(bn_op->getLHS());

			if(left_classifier.vars() != 1 || left_classifier.minus() % 2 != 0){

				right_classifier.TraverseStmt(bn_op->getRHS());

				if(right_classifier.vars() != 1 || right_classifier.minus() % 2 != 1){
					goto check_accesses;
				}

				// TODO rechts als kleiner hinzufuegen ( -1 nicht vergessen)

			}else{
				// TODO links als kleiner hinzufuegen ( -1 nicht vergessen)
			}
				

			break;

check_accesses:
check_increments:
			break;

	}

	return true;

}



canal_classify_term::canal_classify_term(clang::ASTContext *c): canal_dump_AST_Handler(c,NULL){
	debug("creating canal_classify_term");
}

bool canal_classify_term::VisitUnaryOperator(clang::UnaryOperator *un_op){
	if(!Schedule.look_up())
		return true;
	Schedule.increase_child();

	if(un_op->getOpcode() == clang::UnaryOperatorKind::UO_Deref){
		canal_dump_AST_Handler dumpHandler(context,&Schedule);
		dumpHandler.TraverseStmt(un_op);
	}

	return true;
}

bool canal_classify_term::VisitArraySubscriptExpr(clang::ArraySubscriptExpr *ar){
	if(!Schedule.look_up())
		return true;
	Schedule.increase_child();

	canal_dump_AST_Handler dumpHandler(context,&Schedule);
	dumpHandler.TraverseStmt(ar);

	return true;
}


bool canal_classify_term::VisitDeclRefExpr(clang::DeclRefExpr *decl){
	if(!Schedule.look_up())
		return true;
	Schedule.increase_child();
	var_count++;
	return true;
}

bool canal_classify_term::VisitBinaryOperator(clang::BinaryOperator *bn_op){
	if(!Schedule.look_up())
		return true;
	Schedule.increase_child();

	clang::UnaryOperator *un_op{NULL};

	switch(bn_op->getOpcode()){
		case clang::BinaryOperatorKind::BO_Div:
			if((un_op = llvm::dyn_cast<clang::UnaryOperator>(bn_op->getRHS())) != NULL){
				if(un_op->getOpcode() == clang::UnaryOperatorKind::UO_Minus){
					minus_count++;
				}
			}
		case clang::BinaryOperatorKind::BO_Mul:
			if((un_op = llvm::dyn_cast<clang::UnaryOperator>(bn_op->getLHS())) != NULL){
				if(un_op->getOpcode() == clang::UnaryOperatorKind::UO_Minus){
					minus_count++;
				}
			}
			break;
		case clang::BinaryOperatorKind::BO_Sub:
			minus_count++;
			break;
		default:
			break;
	}
	return true;
}

unsigned int canal_classify_term::vars(){
	return var_count;
}

unsigned int canal_classify_term::minus(){
	return minus_count;
}





























