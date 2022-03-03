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

canal_dump_AST_Handler::canal_dump_AST_Handler(clang::ASTContext *c, scheduler *s): Schedule(s), context(c){
	info_conditional(!s,"child Scheduler is NULL in canal_dump_AST_Handler constructor");
	debug("constructing canal_dump_AST_Handler");
}

void canal_dump_AST_Handler::handle(){
	debug("handling thing in canal_dump_AST_Handler");
	if(!Schedule.look_up())
		return;
	Schedule.increase_child();
}

bool canal_dump_AST_Handler::VisitFunctionDecl(clang::FunctionDecl *f){
	handle();
	return true;
}

bool canal_dump_AST_Handler::VisitVarDecl(clang::VarDecl *v){
	handle();
	return true;
}

bool canal_dump_AST_Handler::VisitBinaryOperator(clang::BinaryOperator *b){
	handle();
	return true;
}

bool canal_dump_AST_Handler::VisitUnaryOperator(clang::UnaryOperator *u){
	handle();
	return true;
}

bool canal_dump_AST_Handler::VisitIntegerLiteral(clang::IntegerLiteral *i){
	handle();
	return true;
}

bool canal_dump_AST_Handler::VisitDeclRefExpr(clang::DeclRefExpr *d){
	handle();
	return true;
}

bool canal_dump_AST_Handler::VisitCallExpr(clang::CallExpr *e){
	handle();
	return true;
}

bool canal_dump_AST_Handler::VisitReturnStmt(clang::ReturnStmt *r){
	handle();
	return true;
}

bool canal_dump_AST_Handler::VisitIfStmt(clang::IfStmt *i){
	handle();
	return true;
}































