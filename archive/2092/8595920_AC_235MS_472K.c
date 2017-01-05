#include <stdio.h>
#include <string.h>


struct Node{
	int num;
	int times;
}player[10001];
int N,M;

int cmp(const void *a,const void *b){

	if((*(struct Node*)b).times!=(*(struct Node*)a).times) return (*(struct Node*)b).times-(*(struct Node*)a).times;
	else{
		return (*(struct Node*)a).num-(*(struct Node*)b).num;
	}

}

int main(){
	int i,tem;
	while(1){
		scanf("%d %d",&N,&M);
		if(N==0 && M==0) break;
		for(i=0;i<=10000;i++){
			player[i].num=i;
			player[i].times=0;
		}
		for(i=1;i<=M*N;i++){
			scanf("%d",&tem);
			player[tem].times++;
		}
		qsort(&player[1],10000,sizeof(player[0]),cmp);

		struct Node *p=&player[2];
		while(p->times==player[1].times){
			p++;
		}
		struct Node *q=p+1;
		printf("%d ",p->num);
		while(q->times==p->times){
			printf("%d ",q->num);
			q++;
		}
		printf("\n");



	}
	return 0;
}
