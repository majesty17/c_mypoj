#include <stdio.h>
int N,W,S;
char name[65][16];
int main(){
	scanf("%d",&N);
	int i;
	for(i=1;i<=N;i++){
		scanf("%s",&name[i]);
	}
	scanf("%d,%d",&W,&S);
//	printf("W is %d,S is %d\n",W,S);

	int pos=W-1;
	for(i=1;i<=N-S+1;i++){
		int step=S;
		while(step--){
			while(1){
				pos++;
				if(pos>N){
					pos=pos%N;
				}
				if(name[pos][0]!='\0'){
					break;
				}
			}
		}


		printf("%s\n",name[pos]);
		memset(name[pos],0,16);
	}

	int l=S-1;
	while(l--){
		while(1){
			pos++;
			if(pos>N){
				pos=pos%N;
			}
			if(name[pos][0]!='\0'){
				break;
			}
		}
		printf("%s\n",name[pos]);
		memset(name[pos],0,16);
	}





	return 0;
}
