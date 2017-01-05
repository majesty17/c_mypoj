#include <stdio.h>
int t,n;
//0 1 2 means: heavy light ok
int num[12][3];
char buff[8];
char jud[10];

int main(){
	scanf("%d",&n);
	int i,j;
	while(n--){
		//clear num
		for(i=0;i<12;i++){
			num[i][0]=0;num[i][1]=0;num[i][2]=0;
		}
		int r=3;
		while(r--){
			scanf("%s %s %s",buff,buff+4,jud);


			if(strcmp(jud,"up")==0){
				for(i=0;i<4;i++){
					num[buff[i]-'A'][0]++;
				}
				for(i=4;i<8;i++){
					num[buff[i]-'A'][1]++;
				}
			}
			if(strcmp(jud,"down")==0){
				for(i=0;i<4;i++){
					num[buff[i]-'A'][1]++;
				}
				for(i=4;i<8;i++){
					num[buff[i]-'A'][0]++;
				}
			}
			if(strcmp(jud,"even")==0){
				for(i=0;i<8;i++){
					num[buff[i]-'A'][2]++;
				}
			}
		}
		//清理肯定对的
		for(i=0;i<12;i++){
			if(num[i][0]*num[i][1]>0){
				num[i][2]=100;
			}
			if(num[i][2]>0){
				num[i][1]=0;
				num[i][0]=0;
			}
		}

		for(i=0;i<12;i++){
			if(num[i][0]>0){
				printf("%c is the counterfeit coin and it is heavy.",i+'A');
				break;
			}
			if(num[i][1]>0){
				printf("%c is the counterfeit coin and it is light.",i+'A');
				break;
			}
		}

	}

	return 0;
}
