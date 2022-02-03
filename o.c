

int add(int i1,int i2){
	return i1 + i2;
}

int main(){
	int a = 5 + 7 * 9 - 10;
	int b = a + 10 * 100;
	b = a;
	a = 0;
	b = 0;

	//unsigned int ui;

	a = 14;
	a = b << 15;
	a = b >> 15;

	signed char signedchar = 1;
	signed short signedshort = -14;
	unsigned short unsignedshort = 14;
	signed int signedint = -14;
	unsigned int unsignedint = 14;
	signed long signedlong = -15;
	unsigned long unsignedlong = 15;
	signed long long signedlonglong = -0xffffffffffffffff;
	unsigned long long unsignedlonglong = 0xffffffffffffffff;

	return 0;
}
