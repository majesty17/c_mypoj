#include <stdio.h>
int n;
short a[31];
int main(){
	int sums,sume,i;
	while(1){

		scanf("%d",&n);
		if(n<2 || n>30) break;
		sums=0;
		sume=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sume+=a[i];
		}
		for(i=0;i<n;i++){
			if(sume==sums) break;
			else{
				sums+=a[i];
				sume-=a[i];
			}
		}

		if(i==n) printf("No equal partitioning.\n");
		else{
			printf("Sam stops at position %d and Ella stops at position %d.\n",i,i+1);
		}

	}



	return ;
}
