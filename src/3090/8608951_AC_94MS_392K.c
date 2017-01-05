#include <stdio.h>
int cases;
int k;
int num[1001];
int gcd(int a,int b){
	int r;
	while(b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	if(a==1)return 1;
	return 0;
}
void handle(){
	num[1]=3;
	num[2]=5;
	int i,j;
	for(i=3;i<=1000;i++){
		num[i]=num[i-1]+2;	//printf("heer\n");
		for(j=2;j<i;j++){
			if(gcd(i,j)!=0) num[i]+=2;
		}
	}
}



int main(){
	handle();

	int i,count=0;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&k);
		printf("%d %d %d\n",++count,k,num[k]);
	}
	return 0;
}
