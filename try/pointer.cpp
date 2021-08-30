#include <stdio.h>

int main(){
	int *ip;
	char *cp = (char *)0x4;
	ip = (int *)(cp + 1 * sizeof(int));
	printf("0x%x\n",sizeof(int));
	printf("%p\n",ip);
}
