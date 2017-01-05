#include <stdio.h>
int n;
void handle(){
	if(n%2==0)printf("No Solution!\n");
	else printf("%d\n",n-1);
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		handle();
	}
	return 0;
}
