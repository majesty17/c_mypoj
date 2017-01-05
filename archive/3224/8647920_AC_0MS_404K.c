#include <stdio.h>
int n;
int num[101][101];
int main(){
	int i,j;
	scanf("%d",&n);
	int maxwin=-1,maxi=0;
	for(i=0;i<n;i++){
		int tmp=0;
		for(j=0;j<n;j++){
			scanf("%d",&num[i][j]);
			if(num[i][j]==3)tmp++;
		}
		if(tmp>=maxwin){
			maxwin=tmp;
			maxi=i;
		}
	}
	printf("%d\n",maxi+1);
	return 0;
}
