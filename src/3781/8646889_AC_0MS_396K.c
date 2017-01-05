#include <stdio.h>
int c,order,num[10];
int cmp(const void *a,const void *b){return *(int*)a-*(int*)b;}
int main(){
	int i;
	scanf("%d",&c);
	while(c--){
		scanf("%d",&order);
		for(i=0;i<10;i++){
			scanf("%d",&num[i]);
		}
		qsort(num,10,sizeof(num[0]),cmp);
		printf("%d %d\n",order,num[7]);
	}
	return 0;
}
