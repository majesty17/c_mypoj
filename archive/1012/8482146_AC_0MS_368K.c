#include <stdio.h>

int a[20]={0,
		2,7,5,30,169,
		441,1872,7632,1740,93313,
		459901,1358657,2504881
		};


int main(){

	int n;
	while(1){
		scanf("%d",&n);
		if(n<1 || n>14){
			return -1;
		}

		printf("%d\n",a[n]);

	}

	return 0;
}