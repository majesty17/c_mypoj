#include <stdio.h>
int n;
int isP(int num){
	int i;
	for(i=2;i<=sqrt(num);i++){
		if(num%i==0)return 0;
	}
	return 1;
}
int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(i=3;i<=n/2;i+=2){
			if(isP(i)&&isP(n-i)){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
	}
	return 0;
}
