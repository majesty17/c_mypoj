#include <stdio.h>
#include <math.h>
int n;

int main(){
	int i;
	scanf("%d",&n);
	while(n--){
		int order,num;
		scanf("%d %d",&order,&num);
		int sum=0;
		for(i=2;i<(int)sqrt((double)num)*2;i++)
		{
			if(2*num%i==0&&2*num/i+1-i>0&&(2*num/i+1-i)%2==0)
				sum++;
		}
		printf("%d %d\n",order,sum);
	}
	return 0;
}
