//思路是从小于根号m的最大素数开始搜索

#include <stdio.h>
#include <math.h>
int m,a,b;
int ifaP(int n){
	int i;
	int sq=sqrt(n);
	for(i=2;i<=sq;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
void split(int *p1,int *p2){
	int n=m;
	while(1){
		int i;
		int sq=sqrt(n);
//		printf("n=%d,sq=%d\n",n,sq);
		for(i=2;i<=sq;i++){
			if(n%i==0 && ifaP(i)==1) break;
		}
		if(ifaP(n/i) && (i*b)>=(a*n/i) && i<=sq){
			*p1=i;
			*p2=n/i;
			return ;
		}

		else{
			n--;
			continue;
		}



	}
}
int main(){
//	int i;
//	for(i=1;i<100;i++)
//	printf("%d,%d\n",i,ifaP(i));
//	return 0;


	int p,q;
	while(1){
		scanf("%d%d%d",&m,&a,&b);
		if((m|a|b) ==0) break;


		split(&p,&q);




		printf("%d %d\n",p,q);


	}



	return 0;
}
