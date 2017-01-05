#include <stdio.h>
int c;
int x,y,z;
void handle(){
	if(x>y&&y>z || x<y&&y<z)printf("Ordered\n");
	else printf("Unordered\n");
	return;
}
int main(){
	scanf("%d",&c);
	printf("Gnomes:\n");
	while(c--){
		scanf("%d %d %d",&x,&y,&z);
		handle();
	}
	return 0;
}
