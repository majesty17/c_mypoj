#include <stdio.h>
int n;
int main(){
	int count=0,n1,n2,n3,n4;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		printf("%d. ",++count);
		n1=3*n;
		if(n1%2==0){
			printf("even ");
			n2=n1/2;
		}
		else {
			printf("odd ");
			n2=(n1+1)/2;
		}
		n3=3*n2;
		n4=n3/9;
		printf("%d\n",n4);

	}

}
