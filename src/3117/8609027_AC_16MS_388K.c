#include <stdio.h>
int T,N;
char name[20];
int main(){
	int i,sum;
	while(1){
		scanf("%d %d",&T,&N);
		if(T==0&&N==0) break;
		sum=0;
		for(i=0;i<T;i++){
			int tem;
			scanf("%s %d",&name,&tem);
			sum+=tem;
		}
		printf("%d\n",N*3-sum);
	}
	return 0;
}
