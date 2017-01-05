#include <stdio.h>
int cases;
char P;
int a,b;
int n;
char lcd[1000];
int main(){
	int i,j,k;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&n);
		memset(lcd,0,1000);
		for(i=0;i<n;i++){
			scanf("\n%c%d%d",&P,&a,&b);
//			printf("here\n");
			for(j=a;j<b;j++){
				lcd[j]++;
			}
		}

		for(i=0;i<1000;i++){
			if(lcd[i]!=0) printf("%c",lcd[i]+'A'-1);
		}

		printf("\n");


	}
	return 0;
}
