#include <stdio.h>
short a[10001]={0,};
int getLen(int n){
	int len=0;
	while(n!=1){
		if(n%2==0){
			n=n>>1;
		}
		else{
			n=3*n+1;
		}
		len++;
	}
	return len+1;
}


int main(){
	int i,j;


	while(scanf("%d%d",&i,&j)!=EOF){
		int max=-1,k;
		for(k=(i<j?i:j);k<=(j>i?j:i);k++){
			int tem=getLen(k);
			max=tem>max?tem:max;
		}





		printf("%d %d %d\n",i,j,max);
	}
	return 0;
}
