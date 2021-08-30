#include <stdio.h>

enum Types{
	Char,
	Int,
	Pointer
};

int main(){
	Types t = Char | Pointer;
	if(t | Char)
		printf("char\n");
	if(t | Pointer)
		printf("pointer\n");
	return 0;
}
