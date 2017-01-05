#include <stdio.h>
#include <math.h>
int n;

int isprime(int num){
//	printf("gonna judge %d\n",num);
	int i;
	for(i=2;i<=floor(sqrt(num*1.0));i++){
		if(num%i==0) return 0;
	}

	return 1;
}
int gapof(num){
	int ret=0;

	int i=num;
	while(isprime(++i)==0) ret++;
//	printf("i is %d\n",i);
	i=num;
	while(isprime(--i)==0) ret++;
//	printf("i is %d\n",i);
	return ret+2;
}

int main(){
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		if(isprime(n)==1) {
			printf("0\n");
			continue;
		}
		else {
			printf("%d\n",gapof(n));
			continue;
		}






	}
	return 0;
}
