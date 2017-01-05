#include <stdio.h>
#include <string.h>
#define LOCKED 0
#define UNLOCKED 1


int n;
char a[101];

int main(){
	int lines;
	scanf("%d",&lines);

	while(lines--){					//each game
		scanf("%d",&n);				//has n cells
		int i,j;
		memset(a,0,101);			//clear a to 0
		for(i=1;i<=n;i++){			//for n rounds
			for(j=i;j<=n;j+=i){
				if(a[j]==LOCKED) a[j]=UNLOCKED;
				else a[j]=LOCKED;
			}

		}
		int sum=0;
		for(i=1;i<=n;i++){
			sum+=a[i];
		}

		printf("%d\n",sum);

	}


}
