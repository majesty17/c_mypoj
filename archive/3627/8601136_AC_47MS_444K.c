#include <stdio.h>
int N,B;
int num[20001];
int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int main(){
	int i;
	scanf("%d %d",&N,&B);
	for(i=0;i<N;i++){
		scanf("%d",&num[i]);
	}
	qsort(num,N,sizeof(num[0]),cmp);
	int sum=0;
	for(i=0;i<N;i++){
		sum+=num[i];
		if(sum>=B){
			break;
		}
	}

	printf("%d\n",++i);

	return 0;
}
