#include <stdio.h>

int main(){

	int num;
	scanf("%d",&num);
	if(num<100 || num>999)
		return -2;
	int i;
	int s2,s3;
	int sum=0;
	for(i=0;i<=9999;i++){
		s2=i/100;
		s3=i%100;
		if(num-s2-s3==0)
			sum++;
	}
	printf("%d",sum);
	return 0;
}
