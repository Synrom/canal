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
#include "scheduler.h"


enum CodeClassifier{
	onlyDecrease,
	onlyIncrease,
	mixed,
};

class canal_dump_AST_Handler: public clang::RecursiveASTVisitor<canal_dump_AST_Handler>{
public:
	explicit canal_dump_AST_Handler(clang::ASTContext *, scheduler *);
	void handle();
	
	bool VisitFunctionDecl(clang::FunctionDecl *);
	bool VisitVarDecl(clang::VarDecl *);
	bool VisitBinaryOperator(clang::BinaryOperator *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	bool VisitIntegerLiteral(clang::IntegerLiteral *);
	bool VisitDeclRefExpr(clang::DeclRefExpr *);
	bool VisitCallExpr(clang::CallExpr *);
	bool VisitReturnStmt(clang::ReturnStmt *);
	bool VisitIfStmt(clang::IfStmt *);

private:
	clang::ASTContext *context{NULL};
	scheduler Schedule;
};

class canal_Compound_classifier : public clang::RecursiveASTVisitor<canal_Compound_classifier>{
public:

	explicit canal_Compound_classifier(clang::ASTContext*, scheduler *);
	void setType(CodeClassifier );
	CodeClassifier getType();
	void setVisitedDecreasingOp(bool );

	bool VisitBinaryOperator(clang::BinaryOperator *);
	bool VisitIfStmt(clang::IfStmt *);
	bool VisitCompoundStmt(clang::CompoundStmt *);
	bool VisitCallExpr(clang::CallExpr *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	
private:
	CodeClassifier type{onlyDecrease};
	clang::ASTContext *context{NULL};
	scheduler Schedule;
	bool visitedDecreasingOp{false};
};

class canal_IfStmnt_classifier : public clang::RecursiveASTVisitor<canal_IfStmnt_classifier>{
public:

	explicit canal_IfStmnt_classifier(clang::ASTContext*);
	explicit canal_IfStmnt_classifier();
	CodeClassifier getType(unsigned int);
	unsigned int getCount();
	unsigned int getSwitchCount();

	bool VisitBinaryOperator(clang::BinaryOperator *);
	bool VisitIfStmt(clang::IfStmt *);
	bool VisitCompoundStmt(clang::CompoundStmt *);
	bool VisitCallExpr(clang::CallExpr *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	
	
private:
	std::vector<CodeClassifier> type;
	clang::ASTContext *context{NULL};
	scheduler Schedule;
	bool visitedDecreasingOp{false};
	bool isElseNeutral{true};
	bool visitedIfBeforeCompound{false};
	canal_Compound_classifier CompoundClassifier;
	unsigned int switch_count{0};
};

class canal_AST_analyzer : public clang::RecursiveASTVisitor<canal_AST_analyzer>{
public:
	explicit canal_AST_analyzer(clang::ASTContext* );
	bool VisitFunctionDecl(clang::FunctionDecl *);
	bool VisitVarDecl(clang::VarDecl *);
	bool VisitBinaryOperator(clang::BinaryOperator *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	bool VisitIntegerLiteral(clang::IntegerLiteral *);
	bool VisitDeclRefExpr(clang::DeclRefExpr *);
	bool VisitCallExpr(clang::CallExpr *);
	bool VisitReturnStmt(clang::ReturnStmt *);
	bool VisitIfStmt(clang::IfStmt *);
private:
	bool thisIsFollowupForAVarDecl { false };
	bool thisIsFollowupOfUnaryOperator { false };
	bool thisIsFollowupOfaMinus { false };
	bool thisIsFollowupOfaCall { false };
	clang::ASTContext *context { NULL };
	function *current_function { NULL };
	variable::Types current_type;
	void addVar(const std::string &,std::string &);
	scheduler Schedule;
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
