#include <stdio.h>
int n;
int num[102];
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int i;
	int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	qsort(num,n,sizeof(num[0]),cmp);
	for(i=0;i<(n+1)/2;i++){
		sum+=(num[i]+1)/2;
	}
	printf("%d\n",sum);
	return 0;
}
