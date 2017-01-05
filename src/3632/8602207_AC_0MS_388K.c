#include <stdio.h>
int cases;
int n;
int num[101];

int max,min;
int main(){
	int i;
	scanf("%d",&cases);
	while (cases--){
		max=0;
		min=255;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&num[i]);
			if(num[i]<min) min=num[i];
			if(num[i]>max) max=num[i];
		}


		printf("%d\n",(max-min)*2);
	}
	return 0;
}
