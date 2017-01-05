#include <stdio.h>
int n;
int a[100];
int main(){
	int i,sum,moves,count=0;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		sum=0;
		moves=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		int avg=sum/n;

		for(i=0;i<n;i++){
			moves+=a[i]>avg?a[i]-avg:0;
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",++count,moves);
	}
	return 0;
}
