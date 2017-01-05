#include <stdio.h>
int cases;
int n;
int num[20000];
int cmp(const void*a,const void*b){return *(int*)b-*(int*)a;}
int main(){
	int i;
	scanf("%d",&cases);
	while (cases--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
		}

		qsort(num,n,sizeof(int),cmp);

		int sum=0;
		for(i=2;i<n;i+=3)
			sum+=num[i];
		printf("%d\n",sum);

	}
	return 0;
}
