#include <stdio.h>
int n;
int x,y;

void handle(){
	if(x==y){
		if(x%2==0) printf("%d\n",x*2);
		else printf("%d\n",(x/2)*4+1);
	}
	else if(x-y==2){
		if(x%2==0) printf("%d\n",x*2-2);
		else printf("%d\n",(x/2)*4-1);
	}
	else{
		printf("No Number\n");
	}
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&x,&y);
		handle();
	}
	return 0;
}
