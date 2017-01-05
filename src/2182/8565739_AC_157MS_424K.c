#include <stdio.h>
int n;
int in[8001];		//has n-1

int out[8001];		//


int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}



int main(){
	int i,j;
	scanf("%d",&n);


	for(i=0;i<n-1;i++){
		scanf("%d",&in[i]);
	}
	for(i=0;i<n;i++) out[i]=i+1;
//	for(i=0;i<n;i++) printf("out %d\n",out[i]);
	for(i=n-2;i>=0;i--){
		int t=in[i];
//		printf("t is %d\n",t);
//		for(j=0;j<n;j++) printf("out %d\n",out[j]);
		//qsort(out,i+2,sizeof(int),cmp);

//		for(j=0;j<n;j++) printf("out %d\n",out[j]);
//		printf("gonna chang %d %d\n",out[i+1],out[t]);
		if(out[i+1]==out[t]) continue;
		out[i+1]=out[t]^out[i+1];
		out[t]=out[t]^out[i+1];
		out[i+1]=out[t]^out[i+1];
		int tem=out[t];
		for(j=t;j<=i;j++){
			out[j]=out[j+1];
		}
		out[i]=tem;

//		printf("out i+1 is %d,out t is %d\n",out[i+1],out[t]);
	}


	for(i=0;i<n;i++) printf("%d\n",out[i]);



	return 0;
}
