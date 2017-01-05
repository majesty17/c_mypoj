#include <stdio.h>

int m,n;
char name[1000][20];
int money[1000];

char buff[20];
int getMoney(char *str){
	int i;
	for(i=0;i<m;i++){
		if(strcmp(name[i],str)==0) return money[i];
	}
	return 0;
}
int main(){
	int i,j,sum;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++){
		scanf("%s %d",&name[i],&money[i]);
	}
	for(i=0;i<n;i++){
		sum=0;
		while(1){
			scanf("%s",&buff);
			if(strcmp(buff,".")==0) break;
			sum+=getMoney(buff);
		}
		printf("%d\n",sum);
	}
	return 0;
}
