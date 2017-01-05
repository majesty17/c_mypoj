#include <stdio.h>
int n;
int r,e,c;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d",&r,&e,&c);
		if(e-c==r) printf("does not matter\n");
		else if(e-c>r) printf("advertise\n");
		else printf("do not advertise\n");
	}
	return 0;
}
