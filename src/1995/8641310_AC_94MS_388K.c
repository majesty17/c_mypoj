#include <stdio.h>
int cases;
int M;
int n;
int num1,num2;
__int64 sum;
__int64 qmod(int n1,int n2,int mo){
	if(n2==0)return 1;
	if(n2==1)return n1%mo;

	__int64 t=qmod(n1,n2/2,mo);
	t=(t*t)%mo;
	if(n2%2==1) t=(t*n1)%mo;
	return t;
}
int main(){
	int i,j;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d%d",&M,&n);
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d %d",&num1,&num2);
			sum+=qmod(num1,num2,M);
		}

		printf("%I64d\n",sum%M);
	}
	return 0;
}
