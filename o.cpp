#include <canal/variable.h>
#include <canal/function.h>
#include <canal/operation.h>
#include <canal/root_operation.h>
#include <canal/scope.h>
#include <canal/file.h>
#include <canal/root_scope.h>
#include <canal/container.h>

#include <stdio.h>


void print_container(vcontainer &c){
	printf(" -------------------------------------------------------------------- \n");
	for(variable *it = c.begin();it != c.end;it++)
		printf("%p: %lld ( %d )\n",it, it->value.unsignedlonglong , it->size);
	printf("\n");
}
	

int main(){
	vcontainer container;
	print_container(container);
	container.emplace_back(variable::rvalue, (signed char) 1);
	print_container(container);
	container.emplace_back(variable::rvalue, (unsigned char) 2);
	print_container(container);
	container.emplace_back(variable::rvalue, (signed short) 3);
	print_container(container);
	container.emplace_back(variable::rvalue, (unsigned short) 4);
	print_container(container);
	container.emplace_back(variable::rvalue, (unsigned int) 5);
	print_container(container);
	container.emplace_back(variable::rvalue, (signed int) 6);
	print_container(container);
	container.emplace_back(variable::rvalue, (signed int) 7);
	print_container(container);
	container.emplace_back(variable::rvalue, (signed long) 8);
	print_container(container);
	container.emplace_back(variable::rvalue, (unsigned long) 9);
	print_container(container);
	container.emplace_back(variable::rvalue, (unsigned long long ) 10);
	print_container(container);
	container.emplace_back(variable::rvalue, (signed long long ) 11);
	print_container(container);
	container.emplace_back(variable::rvalue,  12.0f);
	print_container(container);
	container.emplace_back(variable::rvalue,  13.0 );
	print_container(container);
	container.emplace_back(variable::rvalue, (long double) 14.0l);
	print_container(container);
	container.emplace_back(variable::rvalue, 14, sizeof(unsigned int));
	print_container(container);
	return 0;
}

