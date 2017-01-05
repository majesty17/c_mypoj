#include <stdio.h>
int n;
int k;
int main(){
	int i,sum,tem;
	scanf("%d",&n);
	while (n--){
		sum=0;
		scanf("%d",&k);
		for(i=0;i<k;i++){
			scanf("%d",&tem);
			sum+=tem;
		}
		printf("%d\n",sum-k+1);
	}
	return 0;
}
