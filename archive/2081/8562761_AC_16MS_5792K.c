#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *a,*b;
int n;
void init(){
	a=(int*)malloc(500000*sizeof(int));
	b=(int*)malloc(10000000*sizeof(int));
	memset(b,0,500000*sizeof(int));
	a[0]=0;
	b[0]=1;
	int i;
	for(i=1;i<=500000;i++){
		if(a[i-1]<=i){
			a[i]=a[i-1]+i;
			b[a[i-1]+i]=1;
			continue;
		}

		if(b[a[i-1]-i]==0){
			a[i]=a[i-1]-i;
			b[a[i-1]-i]=1;
		}
		else{
			a[i]=a[i-1]+i;
			b[a[i-1]+i]=1;
		}
	}



}

int main(){
	init();
	while(1){
		scanf("%d",&n);
		if(n<0 || n>500000) break;
		printf("%d\n",a[n]);
	}
	return 0;
}
