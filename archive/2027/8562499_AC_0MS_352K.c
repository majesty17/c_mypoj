#include <stdio.h>
int n;
int main(){
	int X,Y;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&X,&Y);
		if(X<Y) printf("NO BRAINS\n");
		else printf("MMM BRAINS\n");
	}
	return 0;
}
