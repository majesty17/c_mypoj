#include <stdio.h>
#include <string.h>
char num[100];
int n;
char rule[2][10][81];
char str[256];
char buff[256];
int exChange(int i){

	char *p;
	memset(buff,0,256);

	p=strstr(str,rule[0][i]);
	if(p!=NULL){
		memcpy(buff,str,p-str);
		strcat(buff,rule[1][i]);
		strcat(buff,p+strlen(rule[0][i]));
		strcpy(str,buff);
		return 1;
	}


	return 0;
}
int main(){
	int i;
	while(1){
		gets(num);
		if(num[0]=='0')break;
		n=atoi(num);
		for(i=0;i<n;i++){
			gets(rule[0][i]);
			gets(rule[1][i]);
		}
		gets(str);
		for(i=0;i<n;i++){
			while(exChange(i)==1){}
		}
		printf("%s\n",str);

	}
	return 0;
}
