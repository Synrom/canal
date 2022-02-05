#include <canal/operation.h>
#include <stdio.h>
#include <string>

void operation::print(){

	operation *next = freference.operations.getNext();
	if(next)
		next->print();
	else
		printf("NULL");

	switch(type){
		case operation::Add:
			printf(" + ");
			break;
		case operation::Minus:
			printf(" - ");
			break;
		case operation::Times:
			printf(" * ");
			break;
		case operation::Divide:
			printf(" / ");
			break;
		case operation::Or:
			printf(" | ");
			break;
		case operation::And:
			printf(" & ");
			break;
		case operation::Xor:
			printf(" ^ ");
			break;
		case operation::Shl:
			printf(" << ");
			break;
		case operation::Shr:
			printf(" >> ");
			break;
		default:
			printf("this operation is not implemented for print");
			break;
	}

	
	next = freference.operations.getNext();
	if(next)
		next->print();
	else
		printf("NULL");
}

void operation::print_simple(){

	switch(type){
		case operation::Equal:
			printf(" = ");
			break;
		case operation::Add:
			printf(" + ");
			break;
		case operation::Minus:
			printf(" - ");
			break;
		case operation::Times:
			printf(" * ");
			break;
		case operation::Divide:
			printf(" / ");
			break;
		case operation::Or:
			printf(" | ");
			break;
		case operation::And:
			printf(" & ");
			break;
		case operation::Xor:
			printf(" ^ ");
			break;
		case operation::Shl:
			printf(" << ");
			break;
		case operation::Shr:
			printf(" >> ");
			break;
		default:
			printf("this operation is not implemented for print");
			break;
	}
	printf("\n");
	
}
void IntLiteral::print(){
	printf("%lld",literal.signedlonglong);
}

void IntLiteral::print_simple(){
	printf("%lld",literal.signedlonglong);
	printf("\n");
}

void VarPush::print(){
	printf("%s",var_name.c_str());
}

void VarPush::print_simple(){
	printf("%s",var_name.c_str());
	printf("\n");
}

void Call::print_simple(){
	printf("%s()\n",call->name.c_str());
}

void Call::print(){
	printf("%s(",call->name.c_str());
	for(int i = 0;i < call->pvariables.size() - 1;i++){
		operation *next = freference.operations.getNext();
		if(next)
			next->print();
		else
			printf("NULL");
		printf(", ");
	}
	operation *next = freference.operations.getNext();
	if(next)
		next->print();
	else
		printf("NULL");
	printf(")");

}

void Equal::print(){

	operation *next = freference.operations.getNext();
	if(next)
		next->print();
	else
		printf("NULL");

	printf(" = ");

	next = freference.operations.getNext();
	if(next)
		next->print();
	else
		printf("NULL");

	printf(";\n");

}
