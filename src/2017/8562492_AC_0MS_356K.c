#include <stdio.h>
int n;
int mile[11];
int hour[11];

int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(n==-1) break;
		for(i=0;i<n;i++){
			scanf("%d %d",&mile[i],&hour[i]);
		}
		int sum=mile[0]*hour[0];
		for(i=1;i<n;i++){
			sum+=(hour[i]-hour[i-1])*mile[i];
		}
		printf("%d miles\n",sum);
	}
	return 0;
}
