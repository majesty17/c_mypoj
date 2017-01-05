#include <stdio.h>
int main(){
	int s,sum=0,i=0;
	scanf("%d",&s);
	while(sum<s || (sum-s)%2==1)
		sum+=++i;
	printf("%d\n",i);
	return 0;
}
