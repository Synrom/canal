

int add(int i1,int i2){
	return i1 + i2;
}

int main(){
	int a = 5 + 7 * 9 - 10;
	int b = add(a,0) + 10 * 100;
	if(a > b){
		b = a;
	}else if(b > a){
		a = 0;
	}else{
		b = 0;
	}

	while(b > 0){
		b--;
		a++;
	}

	a = 14;

	return 0;
}
