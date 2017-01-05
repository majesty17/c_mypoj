#include <stdio.h>
int cases,n;
__int64 num[12];
int grp[12][12];
__int64 sumgrp[12];
int fact(int a){
	int ret=1;
	while(a){
		ret*=a;
		a--;
	}
	return ret;
}
int cmn(int a,int b){
	if(a==b) return 1;
	if(b==1 || b==a-1) return a;
	int i;
	int ret=1;
	for(i=a;i>=a-b+1;i--){
		ret*=i;
	}
	return ret/fact(b);
}
void group(){
	int i,j;
	for(i=1;i<=11;i++){
		grp[i][1]=1;
		grp[i][i]=1;
	}
	sumgrp[1]=1;
	sumgrp[2]=1+1*fact(2);
	for(i=3;i<=11;i++){
		sumgrp[i]=1+1*fact(i);
		for(j=2;j<=i-1;j++){
			grp[i][j]=grp[i-1][j-1]+grp[i-1][j]*j;
			sumgrp[i]+=grp[i][j]*fact(j);
		}
	}
}
void init(){
	group();
	int i,j;
	__int64 sum;
	for(i=1;i<=11;i++){
		sum=0;
		for(j=1;j<=i;j++){
			sum+=cmn(i,j)*(sumgrp[j]);
		}
		num[i]=sum;
	}
}
int main(){
//	printf("%d\n",cmn(5,2));
//	return 0;

	int count=0;
	init();


//	int i;
//	for(i=1;i<=11;i++){
//		printf("%d\n",grp[11][i]);
//	}
//	return 0;


	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		printf("%d %d %I64d\n",++count,n,num[n]);
	}
	return 0;
}
