#include <stdio.h>

int num[10001];
int makeNum(int n){
	int d1=n/10000;
	int d2=(n/1000)%10;
	int d3=(n/100)%10;
	int d4=(n/10)%10;
	int d5=n%10;
	return n+d1+d2+d3+d4+d5;
}
int main(){
//	printf("%d\n",makeNum(12345));
//	return 0;


	int i;
	for(i=0;i<10000;i++){
		num[i]=i;
	}

	for(i=1;i<10000;i++){
		int n=makeNum(i);
		if(n<=10000) num[n]=0;
	}




	for (i=1;i<10001;i++){
		if(num[i]!=0)
			printf("%d\n",i);
	}





	return 0;
}
