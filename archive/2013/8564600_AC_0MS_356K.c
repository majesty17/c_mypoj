#include <stdio.h>
char a[15][30];
int n;
int main(){
	int i;
	int count=0;
	while(1){
		scanf("%d",&n);
		if(n==0) break;

		for(i=0;i<n/2;i++){
			scanf("%s %s",&a[i],&a[n-i-1]);
		}
		if(n%2==1) scanf("%s",&a[n/2]);
		printf("SET %d\n",++count);
		for(i=0;i<n;i++) {
			printf("%s\n",a[i]);
		}

	}
	return 0;
}
