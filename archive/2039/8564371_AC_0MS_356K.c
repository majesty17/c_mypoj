#include <stdio.h>
int n;
char str[300];
int main(){
	int i,j;
	while(1){
		scanf("%d",&n);
		if(!n) break;
		scanf("%s",&str);
		int len=strlen(str);
		for(i=0;i<n;i++){
			for(j=0;j<len/n;j++){
				if(j%2==0) printf("%c",str[j*n+i]);
				else printf("%c",str[j*n+n-i-1]);
			}
		}
		printf("\n");



	}
	return 0;
}
