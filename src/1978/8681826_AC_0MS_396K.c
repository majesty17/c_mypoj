#include <stdio.h>
#include <string.h>
int n,times;
int p,c;
char cards[50];
char buff1[50];
char buff2[50];
void shuffle(){
	memcpy(buff1,cards,p-1);
	memcpy(buff2,cards+p-1,c);
	memcpy(cards,buff2,c);
	memcpy(cards+c,buff1,p-1);
}
int main(){
	int i,j;
	while(1){
		scanf("%d %d",&n,&times);
		if(n==0 && times==0)break;
		for(i=0;i<n;i++){
			cards[i]=n-i;
		}
		for(i=0;i<times;i++){
			scanf("%d %d",&p,&c);
			shuffle();
		}

		printf("%d\n",cards[0]);
	}
	return 0;
}
