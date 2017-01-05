#include <stdio.h>
int n;
double map[100000];
int main(){
	int i;
	map[0]=0;
	for(i=1;i<100000;i++){
		map[i]=map[i-1]+1.0/(i*2);
	}
	printf("Cards  Overhang\n");
	while(scanf("%d",&n)!=EOF){
		printf("%5d     %.3f\n",n,map[n]);
	}
	return 0;
}
