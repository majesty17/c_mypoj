#include <stdio.h>
int n,k;
int stu[1001];
int main(){
	int i,sum,count;
	float avg;
	scanf("%d",&n);
	while(n--){
		sum=0;
		count=0;
		scanf("%d",&k);
		for(i=0;i<k;i++){
			scanf("%d",&stu[i]);
			sum+=stu[i];
		}
		avg=(double)sum/k;
		for(i=0;i<k;i++){
			if(stu[i]>avg) count++;
		}
		printf("%.3f%%\n",(double)count/k*100);
	}
	return 0;
}
