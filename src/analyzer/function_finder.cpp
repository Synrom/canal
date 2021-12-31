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
#include <canal/result.h>

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

	result_stack stack;
	
	result &r1 = stack.push_result(10);
	info("r1 is at %p",r1.begin());
	info("r1 is the following");
	for(auto i = r1.begin();i != r1.end();i++){
		info("%p",i);
	}
	result &r2 = stack.push_result(20);
	info("r2 is at %p",r2.begin());
	info("r2 is the following");
	for(auto i = r2.begin();i != r2.end();i++){
		info("%p",i);
	}


	result r2_pop = stack.pop_result();
	info("poped r2 and result is at %p",r2_pop.begin());
	info("poped r2 is the following");
	for(auto i = r2_pop.begin();i != r2_pop.end();i++){
		info("%p",i);
	}

	result &r3 = stack.push_result(20);
	info("r3 is at %p",r3.begin());
	info("r3 is the following");
	for(auto i = r3.begin();i != r3.end();i++){
		info("%p",i);
	}

	info("getting 0 from top is at %p",stack.get_result(0).begin());
	info("getting 1 from top is at %p",stack.get_result(1).begin());
	
	stack.delete_result();
	result r1_pop = stack.pop_result();
	info("poped r1 and result is at %p",r1_pop.begin());
	info("poped r1 is the following");
	for(auto i = r1_pop.begin();i != r1_pop.end();i++){
		info("%p",i);
	}



	return true;
}



