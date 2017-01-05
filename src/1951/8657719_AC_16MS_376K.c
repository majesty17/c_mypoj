#include <stdio.h>
char buff[100];
char str[100]={0,};
char alpha[26]={-1,0,0,0,-1,0,0,
				0,-1,0,0,0,0,0,
				-1,0,0,0,0,0,
				-1,0,0,0,0,0};
int main(){
	int i,si,len,pos=0;

	gets(buff);
	len=strlen(buff);



	for(i=0;i<len;i++){
		if(isalpha(buff[i])==0){
			if(buff[i]==' ' && str[pos]==' ')continue;
			str[pos++]=buff[i];
			continue;
		}

		si=alpha[buff[i]-'A'];

		if(si==0){
			str[pos++]=buff[i];
			alpha[buff[i]-'A']++;
		}
	}

//	while(str[strlen(str)-2]==' '){
//		str[strlen(str)-2]=str[strlen(str)-1];
//		str[strlen(str)-1]='\0';
//	}
	char *p=str;
	while(*p==' ')p++;
	len=strlen(p);
	for(i=0;i<len;i++){
//		if(i>0 && p[i]==' ' && isalpha(p[i-1])==0 )continue;
		if(i<len-1 && p[i]==' ' && isalpha(p[i+1])==0 )continue;
		printf("%c",p[i]);
	}
	printf("\n");

	return 0;
}
