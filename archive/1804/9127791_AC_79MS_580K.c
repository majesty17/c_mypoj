#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int k;
int *num;
int main(){
	int i,j,count=0,res=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		num=malloc(sizeof(int)*k);
		for(i=0;i<k;i++){
			scanf("%d",num+i);
		}
		res=0;
		for(i=0;i<k-1;i++){
			for(j=i;j<k;j++){
				if(num[i]>num[j])res++;
			}
		}


		printf("Scenario #%d:\n",++count);
		printf("%d\n\n",res);

	}
}

