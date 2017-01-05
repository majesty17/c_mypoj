#include <stdio.h>
int N,M,K;
int nu[20];
int main(){
	register int i;
	scanf("%d %d %d",&N,&M,&K);
	for(i=0;i<2*K;i++){
		scanf("%d",&nu[i]);
	}
	int count=0;
	for(i=0;i<K;i++){
		if(nu[i]<nu[i+K]){
			count+=nu[i+K]-nu[i];
		}
	}
	printf("%d\n",count);
	return 0;
}
