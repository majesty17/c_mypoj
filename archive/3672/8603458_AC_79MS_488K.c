#include <stdio.h>

char path[100000]={0,};

int M,T,U,F,D;
int main(){
	int i;
	scanf("%d %d %d %d %d",&M,&T,&U,&F,&D);
//	printf("T is %d\n",T);
	for(i=0;i<T;i++){
		scanf("\n%c",&path[i]);
//		printf("i is %d\n",i);
	}

	int tem=0;
	int sum=0;
	for(i=0;i<T;i++){
		if(path[i]=='f') sum+=F*2;
		else sum+=U+D;

		if(sum>M){
			printf("%d\n",i);
			return;
		}
		else{
			tem=sum;
		}
	}

	printf("%d\n",T);

	return 0;
}
