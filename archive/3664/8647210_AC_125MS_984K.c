#include <stdio.h>
int N,K;
typedef struct co{
	int first;
	int second;
	int index;
};
struct co cow[50000];

int cmpfirst(struct co *a,struct co *b){

	return b->first-a->first;
}
int cmpsecond(struct co *a,struct co *b){
	return b->second-a->second;
}
int main(){
	int i;
	scanf("%d %d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%d %d",&(cow[i].first),&(cow[i].second));
		cow[i].index=i+1;
	}
	qsort(cow,N,sizeof(cow[0]),cmpfirst);
	qsort(cow,K,sizeof(cow[0]),cmpsecond);

	printf("%d\n",cow[0].index);
	return 0;
}
