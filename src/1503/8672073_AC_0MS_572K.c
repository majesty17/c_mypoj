#include <stdio.h>
#include <string.h>
char num[1100];
char rus[1100]={'0',0,};
void plus(){
//	printf("here\n");
	int len1=strlen(num);
	int len2=strlen(rus);
	int i,tmp,c=0;
	for(i=0;i<(len1>len2?len1:len2);i++){
		tmp=c;
		if(i<len1)tmp+=num[i]-'0';
		if(i<len2)tmp+=rus[i]-'0';
		rus[i]=tmp%10+'0';
		c=tmp/10;
	}
	if(c)rus[i]=c+'0';
}
int main(){
	int i;
	while(1){
		scanf("%s",&num);
		if(strlen(num)==1 && num[0]=='0')break;
		strrev(num);
		for(i=strlen(num)-1;i>=0;i--){
			if(num[i]!='0'){
				num[i+1]='\0';
				break;
			}
		}
		plus();
	}
	printf("%s\n",strrev(rus));
	return 0;
}
