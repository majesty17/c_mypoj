#include <stdio.h>
#include <stdlib.h>

int n;
int num[30100];
int buff[30100]={0,};
int main(){
	scanf("%d",&n);
	int i;
	buff[0]=0;
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
		buff[i+1]=buff[i]+num[i];
	}
	if(buff[n]==n || buff[n]==2*n){
		printf("0");
		return -1;
	}
	int to_12=800000;
	for(i=2;i<=n;i++){
		int sum=0;
		int sum1=buff[i-1]-(i-1);
		int sum2=(n-i+1)*2-(buff[n]-buff[i-1]);
		sum=sum1+sum2;
		if(sum<to_12)
			to_12=sum;
	}

	int all1=buff[n]-n;
	int all2=2*n-buff[n];
	to_12=all1<to_12?all1:to_12;
	to_12=all2<to_12?all2:to_12;

	printf("%d",to_12);

	return 0;
}
