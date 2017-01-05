#include <stdio.h>
#include <stdlib.h>


#define CHANGED 1
#define NOCHANGE 0

int main(){
	int n,i,j;
	int *a;
	scanf("%d",&n);

	for(i=0;i<n;i++){
		int sum;
		scanf("%d",&sum);
		a=(int*)malloc(sizeof(int)*sum);
		for(j=0;j<sum;j++){
			scanf("%d",a+j);
		}

		if(sum%2==1){
			printf("YES\n");
			continue;
		}


		int ifchange=CHANGED;

		while(ifchange!=NOCHANGE){
			ifchange=NOCHANGE;
			for(j=0;j<sum-2;j++){
				if(a[j]==0 && a[j+2]==1){
					a[j]=1;
					a[j+2]=0;
					ifchange=CHANGED;
				}
			}
		}

//
//		for(j=0;j<sum;j++){
//			printf("%d,",a[j]);
//		}
		for(j=0;j<sum-1;j++){
			if(a[j]==0 && a[j+1]==1){
				printf("NO\n");
				break;
			}
			else if(a[j]==0 && a[j+1]==0){
				printf("YES\n");
				break;
			}

		}
		if(j==sum-1 && a[j]==1){
			printf("YES\n");
			continue;
		}




		free(a);
	}


	return 0;
}
