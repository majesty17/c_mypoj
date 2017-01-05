#include <stdio.h>

int n;
int k;
int num[1001];
void init(){
	num[0]=1;
	num[1]=1;
	num[2]=2;
	num[3]=2;
	num[4]=4;
	int i,j;
	for(i=5;i<=1000;i++){
		num[i]=0;
		if(i%2==0){
			for(j=0;j<=i;j+=2){
				num[i]+=num[(i-j)/2];
			}
		}
		else{
			for(j=1;j<=i;j+=2){
				num[i]+=num[(i-j)/2];
			}

		}
	}
}
int main(){
	init();
	int count=0;
	scanf("%d",&n);
	while (n--){
		scanf("%d",&k);
		printf("%d %d\n",++count,num[k]);
	}
	return 0;
}
