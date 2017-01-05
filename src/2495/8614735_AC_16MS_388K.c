#include <stdio.h>
int cases;
int a,b,c,d;
int main(){
	int i,count=0;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d %d %d",&a,&b,&c,&d);
		printf("Scenario #%d:\n",++count);
		printf("%d\n",(a+b+c+d)%2);
		printf("\n");
	}
	return 0;
}
