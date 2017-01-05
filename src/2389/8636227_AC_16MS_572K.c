#include <stdio.h>
#include <string.h>
#include <ctype.h>

char s1[50],s2[50];
char buf[100];
char rus[100]={0,};
void multi(char *num1,int num2,char *des){
	int c=0;
	int i;
	int tmp;
	for(i=0;i<strlen(num1);i++){
		tmp=c+(num1[i]-'0')*num2;
		des[i]=tmp%10+'0';
		c=tmp/10;
	}
	if(c!=0)des[i]=c+'0';
}
void plus(char *des,char *num,int pos){
	int len_des=strlen(des);
	int len_num=strlen(num)+pos;
	int i,c=0,tmp;
	for(i=pos;i<(len_des>len_num?len_des:len_num);i++){
		tmp=c;
		if(des[i]=='\0' && num[i-pos]=='\0') return;
		if(isdigit(num[i-pos])) tmp+=num[i-pos]-'0';
		if(isdigit(des[i])) tmp+=des[i]-'0';
		des[i]=tmp%10+'0';
		c=tmp/10;
	}
	if(c!=0) des[i]=c+'0';
}
int main(){
	scanf("%s",&s1);
	scanf("%s",&s2);

	strrev(s1);
	strrev(s2);
	int i;
	for(i=0;i<strlen(s2);i++){
		memset(buf,0,100);
		multi(s1,s2[i]-'0',buf);
//		printf("%s\n",buf);
		plus(rus,buf,i);
//		printf("rus is %s\n",rus);
	}
	while(1){
		if(rus[strlen(rus)-1]!='0') break;
		rus[strlen(rus)-1]='\0';
	}

	if(strlen(rus)==0)printf("0\n");
	else printf("%s\n",strrev(rus));

	return 0;
}
