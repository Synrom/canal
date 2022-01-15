#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>

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
#include "variable.h"



class canal_AST_analyzer : public clang::RecursiveASTVisitor<canal_AST_analyzer>{
public:
	explicit canal_AST_analyzer(clang::ASTContext* );
	bool VisitFunctionDecl(clang::FunctionDecl *);
	bool VisitVarDecl(clang::VarDecl *);
private:
	clang::ASTContext *context;
	function *current_function;
	variable::Types current_type;
	void addVar(const std::string &,std::string &);
	bool wasLastOperationVarDecl;
};

class canal_AST_consumer : public clang::ASTConsumer{
public:
	explicit canal_AST_consumer(clang::ASTContext *); 

	virtual void HandleTranslationUnit(clang::ASTContext &);

private:
	canal_AST_analyzer visitor;
};

class canal_AST_FrontendAction : public clang::ASTFrontendAction{
public:
	virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(
		clang::CompilerInstance& Compiler, llvm::StringRef InFile){
		return std::make_unique<canal_AST_consumer>(&Compiler.getASTContext());
	}

};

#endif
