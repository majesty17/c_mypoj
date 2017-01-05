#include <stdio.h>
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		if(n&(n-1)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
