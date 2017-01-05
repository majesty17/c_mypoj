#include <stdio.h>
#include <string.h>
int t,n;
//0 1 2 means: heavy light ok
int num[12][3];
char buff1[16];
char buff2[16];
char jud[10];

int tmp[12];

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
			scanf("%s %s %s",buff1,buff2,jud);
			int len=strlen(buff1);

			for(i=0;i<12;i++) tmp[i]=0;
			if(strcmp(jud,"up")==0){
				for(i=0;i<len;i++){
					num[buff1[i]-'A'][0]++;
					num[buff2[i]-'A'][1]++;
					tmp[buff1[i]-'A']++;
					tmp[buff2[i]-'A']++;
				}

				for(i=0;i<12;i++){
					if(tmp[i]==0){
						num[i][2]++;
					}
				}
			}
			if(strcmp(jud,"down")==0){
				for(i=0;i<len;i++){
					num[buff1[i]-'A'][1]++;
					num[buff2[i]-'A'][0]++;
					tmp[buff1[i]-'A']++;
					tmp[buff2[i]-'A']++;
				}
				for(i=0;i<12;i++){
					if(tmp[i]==0){
						num[i][2]++;
					}
				}
			}
			if(strcmp(jud,"even")==0){
				for(i=0;i<len;i++){
					num[buff1[i]-'A'][2]++;
					num[buff2[i]-'A'][2]++;
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
				printf("%c is the counterfeit coin and it is heavy.\n",i+'A');
				break;
			}
			if(num[i][1]>0){
				printf("%c is the counterfeit coin and it is light.\n",i+'A');
				break;
			}
		}

	}

	return 0;
}
