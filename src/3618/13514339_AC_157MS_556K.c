#include <stdio.h>
int t,n;
int num[50010];

int cmp(const void* a,const void* b){
	int n1=*(int*)a;
	int n2=*(int*)b;
	n1=abs(n1);
	n2=abs(n2);
	return n1-n2;
}

int main(){
	scanf("%d %d",&t,&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}


	qsort(num,n,sizeof(int),cmp);

	int dis=abs(num[0]);
	if(dis>t){
		printf("0\n");
		return -1;
	}


	for(i=1;i<n;i++){
		dis+=abs(num[i]-num[i-1]);
		if(dis>t){
			printf("%d\n",i);
			return -1;
		}
	}
	printf("%d\n",n);
	return 0;
}
