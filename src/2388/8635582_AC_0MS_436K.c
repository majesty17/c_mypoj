#include <stdio.h>
int n;
int num[10000];

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	qsort(num,n,sizeof(num[0]),cmp);

	printf("%d\n",num[n/2]);

	return 0;
}
