#include <stdio.h>
#include <stdlib.h>

int n;
int *num;
int main(){
	scanf("%d",&n);
	num=(int*)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",num+i);
	}

	//假设从第0个转折
	int j;
	int to_12=80000;
	for(i=0;i<=n;i++){
		int sum1=0,sum2=0;
		for(j=0;j<n;j++){
			if(j<i){
				if(num[j]!=1){
					sum1++;
				}
			}
			else if(j>=i){
				if(num[j]!=2){
					sum1++;
				}
			}

		}
		if(sum1<to_12)
			to_12=sum1;

	}
	printf("%d\n",to_12);

	free(num);
	return 0;
}
