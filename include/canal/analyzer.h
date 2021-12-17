#ifndef ANALYZER_H
#define ANALYZER_H

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#include "operation.h"
#include "operation_stack.h"
#include "function.h"


class canal_Function_analyzer : public clang::RecursiveASTVisitor<canal_Function_analyzer>{
public:
	explicit canal_Function_analyzer(clang::ASTContext *, function &);
private:
	function &freference;
	clang::ASTContext *context;
};

class canal_Function_finder : public clang::RecursiveASTVisitor<canal_Function_finder>{
public:
	explicit canal_Function_finder(clang::ASTContext* );
	bool VisitFunctionDecl(clang::FunctionDecl *);
private:
	clang::ASTContext *context;
};

class canal_AST_consumer : public clang::ASTConsumer{
public:
	explicit canal_AST_consumer(clang::ASTContext *); 

	virtual void HandleTranslationUnit(clang::ASTContext &);

private:
	canal_Function_finder visitor;
};

class canal_AST_FrontendAction : public clang::ASTFrontendAction{
public:
	virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
		clang::CompilerInstance& Compiler, llvm::StringRef InFile){
		return std::make_unique<canal_AST_consumer>(&Compiler.getASTContext());
	}

};

#endif
