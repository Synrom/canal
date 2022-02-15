

int add(int i1,int i2){
	return i1 + i2;
}

int getvar(){
	int i = 5;
	return i;
}

int main(){
	int a = 5 + 7 * 9 - 10;
	int b = a + 10 * 100;


	a = 14;
	a = b << 15;
	a = b >> 15;

	signed char signedchar = 0x42;
	signed short signedshort = -14;
	unsigned short unsignedshort = 14;
	signed int signedint = -14;
	unsigned int unsignedint = 14;
	signed long signedlong = -15;
	unsigned long unsignedlong = 15;
	signed long long signedlonglong = -0xffffffffffffffff;
	unsigned long long unsignedlonglong = 0xffffffffffffffff;


	// test return
	int c = add(14,12);
	c = getvar();
	

	// test execute
	a = b + c;
	a = b + 15;
	a = 15 + b;
	
	// test equal
	a = c;
	a = 16;

	// test call
	//int d = add(5,getvar());
	
	if(a + 1> 12 && 1 == 1 || 0 != 0){
		c = add(14,12);
	}else if(true){
		a = 14;
		if(14){
			printf("adsf");
		}
	}else{
		getvar();
	}

	return 0;
}
