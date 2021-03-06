#include "canal/operation.h"
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

	// TEST OPERATION_STACK ROPE
	/*
	{
		printf("TESTING THE OPERATION_STACK ROPE SYSTEM\n");
		function imag("imaginary");
		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("first",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));


		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("middle",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));



		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("last",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));

		imag.operations.insert_all_ropes(Equal(imag));
		imag.operations.insert_all_ropes(VarPush("both",imag));
		imag.operations.insert_all_ropes(VarPush("works",imag));

		imag.operations.down_rope();

		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("first_down",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));

		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("middle_down",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));

		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("last_down",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));

		imag.operations.insert_all_ropes(Equal(imag));
		imag.operations.insert_all_ropes(VarPush("both_down",imag));
		imag.operations.insert_all_ropes(VarPush("works",imag));

		imag.operations.up_rope();

		imag.operations.insert_all_ropes(Equal(imag));
		imag.operations.insert_all_ropes(VarPush("both_after_down_up",imag));
		imag.operations.insert_all_ropes(VarPush("works",imag));
		



		printf("after last and both rope");
		imag.operations.print_simple();

		info("TEST ENDED");
	}
	*/

	/*
	// TEST VSTANCE SWITCHES
	{
		printf("TESTING THE OPERATION_STACK ROPE SYSTEM\n");
		function imag("imaginary");
		imag.current_vstance->add_var("Var1",1);
		imag.current_vstance->add_var("Var2",2);
		imag.current_vstance->add_var("Var3",3);
		imag.current_vstance->add_var("Var4",4);
		imag.add_switches(4);
		imag.next_switch();
		imag.next_switch();
		imag.add_switches(5);
		imag.next_switch();
		imag.next_switch();
		imag.next_switch();
		imag.next_switch();
		imag.end_switch();
		imag.current_vstance->print();
		imag.next_switch();
		imag.end_switch();
		imag.current_vstance->print();

	}
	*/

	/*
	// TEST VSTANCE OPERATION PRINT
	{
		printf("TEST VSTANCE OPERATION PRINT\n");
		function imag("imaginary");

		imag.operations.insert_all_ropes(Add_Switch(3,imag));
		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("first",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));
		
		imag.operations.insert_last_rope(Next_Switch(imag));
		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("second",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));
		imag.operations.insert_last_rope(Add_Switch(1,imag));
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("indented",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));
		imag.operations.insert_last_rope(End_Switch(imag));


		imag.operations.insert_last_rope(Next_Switch(imag));
		imag.operations.add_rope();
		imag.operations.insert_last_rope(Equal(imag));
		imag.operations.insert_last_rope(VarPush("third",imag));
		imag.operations.insert_last_rope(VarPush("works",imag));


		imag.operations.insert_last_rope(End_Switch(imag));
		imag.operations.insert_all_ropes(Equal(imag));
		imag.operations.insert_all_ropes(VarPush("all",imag));
		imag.operations.insert_all_ropes(VarPush("works",imag));

		imag.operations.print_simple();
		imag.operations.print();

	}
	*/
	if (argc < 2) {
		return 1;
	}

	debugger::init_debugger();

	std::ifstream ifs(argv[1]);

	std::string content((std::istreambuf_iterator<char>(ifs)),
	    (std::istreambuf_iterator<char>()));

	printf("analyze %s\n",content.c_str());
	clang::tooling::runToolOnCode(std::make_unique<canal_AST_FrontendAction>(), content.c_str());

	for(auto i = global_scope.function_begin(); i != global_scope.function_end(); i.increment()){
		(*i).print();
		if((*i).name == "main"){
			printf("found main function");
			(*i).execute();
			(*i).print_vars();
		}
	}

	

	return 0;
}

