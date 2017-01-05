#include <stdio.h>
#include <math.h>
int n;
int p[4000];


int isp(int num){
	if(num==0 || num==1) return 0;
	int i;
	for(i=2;i<=sqrt(num);i++){
		if(num%i==0) return 0;
	}
	return 1;
}
void init(){
	int i,j;
	int pos=0;
	for(i=2;i<=32768;i++){
		if(isp(i)==1) {
			p[pos++]=i;
//			printf("%dth p is %d\n",pos-1,i);
		}
	}
}
int testSplit(int pos,int num){
//	printf("gonna test num is %d,p is %d\n",num,p[pos]);
	if(isp(num-p[pos])==1) return 1;
	return 0;
}
int getSplitTimes(){
	int ret=0;
	int i=0;
	while(n>=2*p[i] ){
		ret+=testSplit(i,n);
		i++;
	}
	return ret;
}
int main(){
	init();
	while(1){
		scanf("%d",&n);
		if(n==0)break;

		printf("%d\n",getSplitTimes());
	}
	return 0;
}
