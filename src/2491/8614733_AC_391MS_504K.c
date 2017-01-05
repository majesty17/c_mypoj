#include <stdio.h>
#include <string.h>
#define WORD_LEN 20
int cases,k;
char map[334][334];
char name[334][WORD_LEN];
char done[334];
char tem1[WORD_LEN],tem2[WORD_LEN];
int ifclear(int col){
	int i,sum=0;
	for(i=0;i<k;i++){
		sum+=map[i][col];
	}
	if(sum==0) return 1;
	else return 0;
}
void doclear(int row){
	int i;
	for(i=0;i<k;i++){
		map[row][i]=0;
	}
}
int main(){
	int i,j,ii,count=0,left,right;
	scanf("%d",&cases);
	while(cases--){
		left=0;right=0;
		scanf("%d",&k);
		memset(map,0,334*334);
		memset(name,0,334*WORD_LEN);
		for(i=0;i<k-1;i++){
			scanf("%s %s",tem1,tem2);
			for(j=0;j<333;j++){
				if(strcmp(tem1,name[j])==0){
					left=j;
					break;
				}
				if(name[j][0]=='\0'){
					strcpy(name[j],tem1);
					left=j;
					break;
				}
			}
			for(j=0;j<333;j++){
				if(strcmp(tem2,name[j])==0){
					right=j;
					break;
				}
				if(name[j][0]=='\0'){
					strcpy(name[j],tem2);
					right=j;
					break;
				}
			}
//			printf("map left right: %d %d\n",left,right);
			map[left][right]=1;
		}


//		printf("\n");
//		for(i=0;i<k;i++)
//			printf("%s\n",name[i]);
//		for(i=0;i<k;i++){
//			for(j=0;j<k;j++){
//				printf("%d,",map[i][j]);
//			}
//			printf("\n");
//		}


		printf("Scenario #%d:\n",++count);
		memset(done,0,334);
		for(i=0;i<k;i++){

			for(j=0;j<k;j++){
				if(done[j]==0 && ifclear(j)==1){
					done[j]=1;
					printf("%s\n",name[j]);
					doclear(j);
					break;
				}
			}
		}

		printf("\n");
	}
}
