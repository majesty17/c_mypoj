#include <stdio.h>
int n,d;
int num[502][102];
int sum[102];
int main(){
	while(1){
		scanf("%d %d",&n,&d);
		if(n==0 && d==0)
			break;
		int i,j;
		for(i=0;i<n;i++)
			sum[i]=0;
		for(i=0;i<d;i++){
			for(j=0;j<n;j++){
				scanf("%d",&num[i][j]);
				sum[j]+=num[i][j];
			}
		}
		for(i=0;i<n;i++){
			if(sum[i]==d){
				printf("yes\n");
				break;
			}
		}
		if(i==n){
			printf("no\n");
		}


	}
	return 0;
}
