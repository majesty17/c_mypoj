#include <stdio.h>
int n;
int num[101];
int main(){
	int i;
	int max,min,sum;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		max=-1;min=0x7fffffff;
		sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
			max=max>num[i]?max:num[i];
			min=min<num[i]?min:num[i];
			sum+=num[i];
		}
		printf("%d\n",(sum-max-min)/(n-2));


	}
	return 0;
}
