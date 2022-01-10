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

canal_Function_finder::canal_Function_finder(clang::ASTContext *c) : context(c) {
	info("created Function finder");
}

bool canal_Function_finder::VisitFunctionDecl(clang::FunctionDecl *clang_function){
	std::string name = clang_function->getNameInfo().getName().getAsString();
	info("found function %s",name.c_str());


	function &freference = global_scope.addFunction(name);

	freference.operations.push_back(Add("a1","s1",freference));
	operation *current = freference.operations.getNext();
	info("current is %p with vars %s and %s",current, current->left.c_str(), current->right.c_str());

	freference.operations.push_back(Minus("a2","s2",freference));
	current = freference.operations.getNext();
	info("current is %p with vars %s and %s",current, current->left.c_str(), current->right.c_str());

	freference.operations.push_back(Divide("a3","s3",freference));
	freference.operations.push_back(Times("a4","s4",freference));
	freference.operations.push_back(Or("a5","s5",freference));
	freference.operations.push_back(And("a6","s6",freference));
	freference.operations.push_back(Xor("a7","s7",freference));
	freference.operations.push_back(Neg("a8",freference));
	freference.operations.push_back(Inc("a9",freference));
	freference.operations.push_back(Dec("a10",freference));
	std::vector<std::string> parameters_call;
	parameters_call.emplace_back("a");
	parameters_call.emplace_back("b");
	freference.operations.push_back(Call(&freference,parameters_call,freference));
	freference.operations.push_back(Equal("a11","s11",freference));
	freference.operations.push_back(Ret("a12",freference));

	info("no reset operation stack");

	operation *i;
	while((i = freference.operations.getNext()) != NULL){
		info("current is %p with vars %s and %s",i, i->left.c_str(), i->right.c_str());
	}

	return true;
}



