#include <stdio.h>
int c,sum,mi;
int main(){
	scanf("%d",&c);
	while(c--){
		scanf("%d%d",&sum,&mi);
		if(sum<mi || (sum+mi)%2==1) {puts("impossible");continue;}
		int t1=(sum+mi)/2;
		int t2=(sum-mi)/2;
		printf("%d %d\n",t1,t2);
	}
	return 0;
}
