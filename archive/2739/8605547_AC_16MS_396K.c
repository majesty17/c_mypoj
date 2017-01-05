#include <stdio.h>
#include <math.h>
int n;
int p[1500];


int isp(int num){
	int i;
	for(i=2;i<=sqrt(num);i++){
		if(num%i==0) return 0;
	}
	return 1;
}
void init(){
	int i,j;
	int pos=0;
	for(i=2;i<=10050;i++){
		if(isp(i)==1) {
			p[pos++]=i;
//			printf("%dth p is %d\n",pos-1,i);
		}
	}
}
int testSplit(int pos,int num){
	if(num==p[pos]) return 1;
	else if(num<p[pos]) return 0;
	else{
		return testSplit(pos+1,num-p[pos]);
	}
}
int getSplitTimes(){
	int ret=0;
	int i=0;
	while(n>=p[i]){
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
