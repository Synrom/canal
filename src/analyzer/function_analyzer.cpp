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

bool canal_AST_analyzer::VisitVarDecl(clang::VarDecl *var_decl){

	std::string var_name = var_decl->getNameAsString();
	info("found declination statement of %s",var_name.c_str());
	
	std::string var_type = var_decl->getType().getAsString();
	info("type of that variable is %s",var_type.c_str());

	return true;
}

