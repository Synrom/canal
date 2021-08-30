#include <canal/variable.h>
#include <canal/container.h>


void print_container(const vcontainer &c){
	printf(" -------------------------------------------------------------------- \n");
	for(variable *it = c.begin();it != c.end();it++)
		printf("%p: %lld ( %d )\n",it, it->unsignedlonglong , it->size);
	printf("\n");
}
	

int main(){
	vcontainer container;
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (signed char) 1);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (unsigned char) 2);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (signed short) 3);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (unsigned short) 4);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (unsigned int) 5);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (signed int) 6);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (signed int) 7);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (signed long) 8);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (unsigned long) 9);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (unsigned long long ) 10);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (signed long long ) 11);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (float) 12);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (double) 13);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, (long double) 14);
	print_container(container);
	container.emplace_back(variable::Types.rvalue, 14, sizeof(unsigned int));
	print_container(container);
	return 0;
}

