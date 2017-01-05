#include <stdio.h>
#include <string.h>
char buff[15];
char str[15];
void sum(char *n1,char *n2){
	int len1=strlen(n1);
	int len2=strlen(n2);
	int len=len1>len2?len1:len2;
	int i,tmp;
	for(i=0;i<len;i++){
		if(n1[i]=='\0' && n2[i]=='\0') break;
		tmp=0;
		if(n1[i]!='\0') tmp+=n1[i]-'0';
		if(n2[i]!='\0') tmp+=n2[i]-'0';
		n1[i]=tmp%10+'0';

	}

}
int main(){
	memset(buff,0,15);
	while(scanf("%s",&str)!=EOF){
		sum(buff,strrev(str));
		memset(str,0,15);
	}

	printf("%s\n",strrev(buff));
	return 0;
}
