#include <stdio.h>
int n,num[100001];
int main(){
	register int i;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(i=1;i<=n;i++){
			scanf("%d",&num[i]);
		}
		char sign=0;
		for(i=1;i<=n;i++){
			if(num[num[i]]!=i){
				sign=1;
				break;
			}
		}
		if(sign==0) puts("ambiguous");
		else puts("not ambiguous");

	}
	return 0;
}
