#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/CommonOptionsParser.h"
#include "clang/Tooling/Tooling.h"
#include "llvm/Support/CommandLine.h"

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>


#include <canal/analyzer.h>
#include <canal/debugger.h>
#include <canal/root_scope.h>

extern root_scope global_scope;

int main(int argc, char** argv)
{

	if (argc < 2) {
		return 1;
	}

	debugger::init_debugger();

	std::ifstream ifs(argv[1]);

	std::string content((std::istreambuf_iterator<char>(ifs)),
	    (std::istreambuf_iterator<char>()));

	//printf("analyze %s\n",content.c_str());
	clang::tooling::runToolOnCode(std::make_unique<canal_AST_FrontendAction>(), content.c_str());

	for(auto i = global_scope.function_begin(); i != global_scope.function_end(); i.increment()){
		(*i).print();
	}

	return 0;
}

