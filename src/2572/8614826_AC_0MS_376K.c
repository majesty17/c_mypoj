#include <stdio.h>
#include <string.h>
char line[30];
char num1[10],num2[10],res[10];
char buff[10];
void cut(char *str){
	while(str[strlen(str)-1]=='0') str[strlen(str)-1]='\0';
}
int judge(){

	memset(buff,0,10);
	int len1=strlen(num1),len2=strlen(num2);
	int minlen=len1<len2?len1:len2;
	int maxlen=len1>len2?len1:len2;
	int tem;
	int i,c=0;
	for(i=0;i<minlen;i++){
		tem=num1[i]-'0'+num2[i]-'0'+c;
		buff[i]=(tem)%10+'0';
		c=tem/10;
	}

	for(i=minlen;i<maxlen;i++){
		if(len1>len2)tem=num1[i]-'0'+c;
		else tem=num2[i]-'0'+c;
		buff[i]=(tem)%10+'0';
		c=tem/10;
	}
	if(c!=0)buff[strlen(buff)]='1';

	cut(buff);
	cut(res);
	return strcmp(res,buff);
}
int main(){
	while(1){
		scanf("%s",line);
		memset(num1,0,10);
		memset(num2,0,10);
		strncpy(num1,line,strchr(line,'+')-line);
		strncpy(num2,strchr(line,'+')+1,strchr(line,'=')-strchr(line,'+')-1);
		strcpy(res,strchr(line,'=')+1);
		if(strcmp(num1,"0")==0&&strcmp(num2,"0")==0&&strcmp(res,"0")==0) {puts("True");break;}
//		printf("i get it !!!!\t%s+%s=%s\n",num1,num2,res);

		if(judge()==0)puts("True");
		else puts("False");

	}
	return 0;
}
