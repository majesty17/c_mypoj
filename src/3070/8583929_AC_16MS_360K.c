#include <stdio.h>
#include <string.h>
#include <math.h>
int n;

__int64 fibonacci(int n){
	double b=(pow(5,-0.5)*(pow(0.5+pow(5,0.5)/2.0,n)-pow(0.5-pow(5,0.5)/2.0,n)));
	__int64 a=floor(b+.5);
	return a;
}
int fibonacci4(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	if(n==2) return 1;

	int i;
	int i0=0,i1=1,i2=1,i3;
	for(i=0;i<n-2;i++){
		i3=i2+i1;
		i3%=10000;
		i0=i1;i1=i2;i2=i3;
	}
	return i3;
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n==-1) break;
		printf("%d\n",fibonacci4((n-23)%15000+23));

	}

	return 0;
}
