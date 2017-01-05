#include <stdio.h>
int n;
char num[26];
int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
		}
		printf("%d ",num[0]);
		for(i=1;i<n;i++){
			if(num[i]!=num[i-1])printf("%d ",num[i]);
		}
		printf("$\n");
	}
	return 0;
}
