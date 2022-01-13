#include <string>
#include <vector>
#include <stdio.h>

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
#include <canal/variable.h>

root_scope global_scope;

canal_AST_consumer::canal_AST_consumer(clang::ASTContext *c) : visitor(c) {
	info("created AST consumer");
}

void canal_AST_consumer::HandleTranslationUnit(clang::ASTContext &c){
	info("iterate over whole ast of file");
	visitor.TraverseAST(c);
}

canal_AST_analyzer::canal_AST_analyzer(clang::ASTContext *c) : context(c) {
	info("created Function finder");
	current_function = NULL;
}

bool canal_AST_analyzer::VisitFunctionDecl(clang::FunctionDecl *clang_function){
	std::string name = clang_function->getNameInfo().getName().getAsString();
	info("found function %s",name.c_str());


	current_function = global_scope.addFunction(name);

	info("created function instance in global_scope and moved current %p (%s)",current_function, current_function->name.c_str());


	return true;
}



