#include <stdio.h>
int len,n;
int x,y;
int main(){
	int i;
	while(1){
		scanf("%d %d",&len,&n);
		if(len==0 && n==0) break;
		len++;
		for(i=0;i<n;i++){
			scanf("%d %d",&x,&y);
			len-=(y-x+1);
		}
		printf("%d\n",len);
	}
	return 0;
}
