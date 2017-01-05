#include <stdio.h>
#define PERFECT 1
#define DEFICIENT 2
#define ABUNDANT 3
short num[60001]={0,};

int n;
void handle(){
	int j;
	int sum;

	sum=0;
	for(j=1;j<=n/2;j++){
		if(n%j==0) sum+=j;
	}
	if(sum==n) printf("PERFECT\n");
	else if(sum<n) printf("DEFICIENT\n");
	else printf("ABUNDANT\n");

}
int main(){

	int o=0;

	while(1){
		scanf("%d",&n);
		if(n==0) break;

		if(o==0) printf("PERFECTION OUTPUT\n");
		printf("%5d  ",n);
		handle();
		o++;
	}


	printf("END OF OUTPUT\n");
	return 0;
}
