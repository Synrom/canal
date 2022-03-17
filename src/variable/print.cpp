#include <string>
#include <canal/variable.h>
#include <canal/debugger.h>
#include <new>
#include <stdio.h>

void variable::print(){
	printf("%s = ",name.c_str());

	switch(type){
		case variable::signedchar:
			printf("'%c'",value.signedchar);
			break;
		case variable::unsignedchar:
			printf("'%c'",value.unsignedchar);
			break;
		case variable::signedshort:
			printf("%hd",value.signedshort);
			break;
		case variable::unsignedshort:
			printf("%hu",value.unsignedshort);
			break;
		case variable::signedint:
			printf("%d",value.signedint);
			break;
		case variable::unsignedint:
			printf("%u",value.unsignedint);
			break;
		case variable::signedlong:
			printf("%ld",value.signedlong);
			break;
		case variable::unsignedlong:
			printf("%lu",value.unsignedlong);
			break;
		case variable::signedlonglong:
			printf("%lld",value.signedlonglong);
			break;
		case variable::unsignedlonglong:
			printf("%llu",value.unsignedlonglong);
			break;
		case variable::_float:
			printf("%f",value._float);
			break;
		case variable::_double:
			printf("%lf",value._double);
			break;
		case variable::longdouble:
			printf("%Lf",value.longdouble);
			break;
		case variable::pointer:
			printf("(size: %u, capacity: %u, position: %llu)",size,capacity,value.unsignedlonglong);
			break;
	}
	printf("\n");

}

void pointer::print(){
	printf("%s = ",name.c_str());
	printf("(size: %u, capacity: %u, position: %llu)\n",size,capacity,value.unsignedlonglong);
}
