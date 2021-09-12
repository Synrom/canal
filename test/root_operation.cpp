#include <canal/root_operation.h>
#include <stdio.h>

void print_rootoperation(root_operation &root){
	printf("standard operation vector:\n");
	for(operation *opit = root.begin();opit != root.end;opit++)
		printf("%p -> %p\n",opit,opit->call);
	printf("recursive operation vector:\n");
	for(operation *opit = root.rbegin();opit != root.rend;opit++)
		printf("%p -> %p\n",opit,opit->call);
}

int main(){
	root_operation root;
	printf("append %p\n",root.append(1));
	print_rootoperation(root);
	printf("rappend %p\n",root.rappend(10));
	print_rootoperation(root);
	printf("append %p\n",root.append(2));
	print_rootoperation(root);
	printf("rappend %p\n",root.rappend(11));
	print_rootoperation(root);
	return 0;
}
