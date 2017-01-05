#include <stdio.h>
#include <string.h>
char str1[76],str2[76];


int cmp(char a,char b){
	if(a==b)return 0;
	switch (a){
		case 'R':{
			if(b=='S')return 1;
			if(b=='P')return -1;
		}
		case 'S':{
			if(b=='R')return -1;
			if(b=='P')return 1;
		}
		case 'P':{
			if(b=='R')return 1;
			if(b=='S')return -1;
		}
	}
}
void handle(){
	int ret1=0,ret2=0,i,tmp;
	for(i=0;i<strlen(str1);i++){
		tmp=cmp(str1[i],str2[i]);
		if(tmp>0)ret1++;
		if(tmp<0)ret2++;
	}
	printf("P1: %d\n",ret1);
	printf("P2: %d\n",ret2);
	return;
}

int main(){
	while(1){
		scanf("%s %s",&str1,&str2);
		if(str1[0]=='E')break;
		handle();
	}
	return 0;
}
