#include <stdio.h>
int n;
int main(){
	int sum;
	while(scanf("%d",&n)!=EOF){
		sum=ceil((sqrt(1.0+8.0*n)-1.0)/2.0);
//		printf("sum is %d\n",sum);

		if(sum%2==0){
			printf("TERM %d IS %d/%d\n",n,n-sum*(sum-1)/2,sum-n+sum*(sum-1)/2+1);
		}
		else{
			printf("TERM %d IS %d/%d\n",n,sum-n+sum*(sum-1)/2+1,n-sum*(sum-1)/2);
		}
	}
	return 0;
}
