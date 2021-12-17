
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

root_scope global_scope;

canal_AST_consumer::canal_AST_consumer(clang::ASTContext *c) : visitor(c) {
	info("created AST consumer");
}

void canal_AST_consumer::HandleTranslationUnit(clang::ASTContext &c){
	info("iterate over whole ast of file");
	visitor.TraverseAST(c);
}

canal_Function_finder::canal_Function_finder(clang::ASTContext *c) : context(c) {
	info("created Function finder");
}

bool canal_Function_finder::VisitFunctionDecl(clang::FunctionDecl *clang_function){
	std::string name = clang_function->getNameInfo().getName().getAsString();
	info("found function %s",name.c_str());

	function &freference = global_scope.addFunction(name);

	return true;
}



