#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int n;
int num[1024];
void handle(int a){
	int len=2<<a,i;
	int *tem=(int*)malloc(sizeof(int)*len);
	for(i=0;i<len/2;i++){
		tem[2*i]=(num[i]+num[i+len/2])/2;
		tem[2*i+1]=(num[i]-num[i+len/2])/2;
	}
	///
//	printf("a=%d\n",a);
//	for(i=0;i<len;i++){
//		printf("%d,",tem[i]);
//	}
//	printf("\n");
	///
	memcpy((void*)num,(void*)tem,sizeof(int)*len);
	free(tem);
}
int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
		}


		for(i=0;i<floor(log((double)n)/log(2.0));i++){
//			printf("%dth\n",i);
			handle(i);
		}


		for(i=0;i<n;i++){
			printf("%d",num[i]);
			if(i<n-1) printf(" ");
		}
		printf("\n");





	}
	return 0;
}
