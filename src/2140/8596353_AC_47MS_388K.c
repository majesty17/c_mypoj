#include <stdio.h>
int N;
int main(){
	scanf("%d",&N);
	int a;
	int count=0;
	for(a=0;a<sqrt(1+8*N)/2-.5;a++){
		if((2*N)%(a+1)==0 && ((2*N)/(a+1)-a)%2==0) {
//			printf("a is %d\n",a);
			count++;
		}

	}
	printf("%d\n",count);

	return 0;
}
