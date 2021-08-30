#include <new>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

class beispiel{
public:
	int ar[2];
	virtual ~beispiel(){
		printf("Destructor base\n");
	}
};

class beispiel2 : public beispiel{
	~beispiel2(){
		printf("Destructor derived\n");
	}
};

int main(){
	std::cout << "beispiel ist " << sizeof(beispiel) << " bytes groß" << std::endl;
	char *p = (char *)malloc(sizeof(beispiel) * 2);
	beispiel *b1 = new(p) beispiel();
	beispiel *b2 = new(p+sizeof(beispiel)) beispiel2();
	printf("b1 = %p\n",b1);
	printf("b2 = %p\n",b2);

	b1->~beispiel();
	b2->~beispiel();

	return 0;

}
