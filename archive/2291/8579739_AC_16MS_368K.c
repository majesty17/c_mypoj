#include <stdio.h>
int cases;
int n;
int ropes[1000];


int cmp(const void *a,const void*b){
	return *(int*)b-*(int*)a;
}

int main(){
	int i;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		for(i=0;i<n;i++) scanf("%d",&ropes[i]);

		qsort(ropes,n,sizeof(ropes[0]),cmp);

//		for(i=0;i<n;i++) printf("%d,",ropes[i]);

		int max=ropes[0];

		for(i=1;i<n;i++){
			if(max<ropes[i]*(i+1)) max=ropes[i]*(i+1);
			//else break;
		}



		printf("%d\n",max);

	}










	return 0;
}
