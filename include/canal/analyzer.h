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
	bool VisitArraySubscriptExpr(clang::ArraySubscriptExpr *);
	bool VisitCompoundStmt(clang::CompoundStmt *);

protected:
	clang::ASTContext *context{NULL};
	scheduler Schedule;
};


class canal_IfStmt_analyzer: public canal_dump_AST_Handler {
public:
	explicit canal_IfStmt_analyzer(clang::ASTContext *, scheduler *, const std::vector<CodeClassifier> &,unsigned int, function *);

	bool VisitBinaryOperator(clang::BinaryOperator *);
	bool VisitIfStmt(clang::IfStmt *);
	bool VisitCompoundStmt(clang::CompoundStmt *);
private:
	bool visitedIfBeforeCompound{false};
	bool isFirstIf{true};
	std::vector<CodeClassifier> classifier_type;
	unsigned int current_classifier_position{0};
	unsigned int switch_count{0};
	function *current_function{NULL};

};

bool isAccessInStmt(clang::Stmt *,clang::ASTContext *);
bool isExprJustVar(clang::Expr *);

class canal_classify_term: public canal_dump_AST_Handler{
public:
	explicit canal_classify_term(clang::ASTContext *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	bool VisitArraySubscriptExpr(clang::ArraySubscriptExpr *);
	bool VisitDeclRefExpr(clang::DeclRefExpr *);
	bool VisitBinaryOperator(clang::BinaryOperator *);
	unsigned int vars();
	unsigned int minus();
private:
	unsigned int var_count{0};
	unsigned int minus_count{0};

};

class canal_Access_In_Expr: public clang::RecursiveASTVisitor<canal_Access_In_Expr>{
public:
	explicit canal_Access_In_Expr(clang::ASTContext *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	bool VisitArraySubscriptExpr(clang::ArraySubscriptExpr *);
	bool isAccess();
private:
	bool ceAccess{false};
	clang::ASTContext *context{NULL};

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
	bool VisitArraySubscriptExpr(clang::ArraySubscriptExpr *);
	
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
	std::vector<CodeClassifier> getType();
	unsigned int getCount();
	unsigned int getSwitchCount();

	bool VisitBinaryOperator(clang::BinaryOperator *);
	bool VisitIfStmt(clang::IfStmt *);
	bool VisitCompoundStmt(clang::CompoundStmt *);
	bool VisitCallExpr(clang::CallExpr *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	bool VisitArraySubscriptExpr(clang::ArraySubscriptExpr *);
	
	
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
	explicit canal_AST_analyzer(clang::ASTContext* ,function *);
	bool VisitFunctionDecl(clang::FunctionDecl *);
	bool VisitVarDecl(clang::VarDecl *);
	bool VisitBinaryOperator(clang::BinaryOperator *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	bool VisitIntegerLiteral(clang::IntegerLiteral *);
	bool VisitDeclRefExpr(clang::DeclRefExpr *);
	bool VisitCallExpr(clang::CallExpr *);
	bool VisitReturnStmt(clang::ReturnStmt *);
	bool VisitIfStmt(clang::IfStmt *);
	bool VisitArraySubscriptExpr(clang::ArraySubscriptExpr *);
	bool VisitCompoundStmt(clang::CompoundStmt *);
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

class canal_Term_last_rope_analyzer : public clang::RecursiveASTVisitor<canal_Term_last_rope_analyzer>{
public:
	explicit canal_Term_last_rope_analyzer(clang::ASTContext* ,function *,scheduler *);
	bool VisitFunctionDecl(clang::FunctionDecl *);
	bool VisitVarDecl(clang::VarDecl *);
	bool VisitBinaryOperator(clang::BinaryOperator *);
	bool VisitUnaryOperator(clang::UnaryOperator *);
	bool VisitIntegerLiteral(clang::IntegerLiteral *);
	bool VisitDeclRefExpr(clang::DeclRefExpr *);
	bool VisitCallExpr(clang::CallExpr *);
	bool VisitReturnStmt(clang::ReturnStmt *);
	bool VisitIfStmt(clang::IfStmt *);
	bool VisitArraySubscriptExpr(clang::ArraySubscriptExpr *);
	bool VisitCompoundStmt(clang::CompoundStmt *);
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

class canal_reversed_term_analyzer: public canal_Term_last_rope_analyzer{

private:
	clang::BinaryOperatorKind thisIsFollowupOf{clang::BinaryOperatorKind::BO_Add};
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
