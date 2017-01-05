#include <stdio.h>
int n,s;
int num[20010];
int sum=0;

int cmp(const void *a, const void *b){
     return(*(int *)a-*(int *)b);
}

int main(){
	scanf("%d %d",&n,&s);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	qsort(num,n,sizeof(int),cmp);


	int sum=0;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			int tmp=num[i]+num[j];
			if(tmp<=s){
				sum++;
			}
			else
				break;
		}
	}

	printf("%d",sum);
	return 0;
}
