#include <stdio.h>
#include <string.h>
char *toke[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten",
"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen",
"twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred","thousand","million","negative"};
char str[100];
char seg1[50],seg2[50],seg3[50];
int getValue(char *s){
	if(s[0]=='\0')return 0;
	int i;
	int ret=0;
	char s1[10]={0,},s2[20]={0,};
	char *p=s,*q;
	q=strstr(p,toke[28]);
	if(q!=NULL){
		strncpy(s1,p,q-p);
		p=q+8;
	}

	for(i=1;i<=9;i++){
		if(strstr(s1,toke[i])!=NULL){
			ret+=i*100;
			break;
		}
	}
	for(i=27;i>=1;i--){
		q=strstr(p,toke[i]);
		if(q!=NULL){
			if(i<=20)ret+=i;
			else ret+=(i-20+2)*10;
			p=q+strlen(toke[i])+1;
		}
	}

//	printf("<%s>\t\t\tvalue is %d\n",s,ret);
	return ret;
}
int handle(){
	int sign;
	memset(seg1,0,50);
	memset(seg2,0,50);
	memset(seg3,0,50);
	char *p=str,*q;
	q=strstr(p,toke[31]);
	if(q!=NULL){
		sign=-1;
		p=q+9;
	}
	else{
		sign=1;
	}
	int ret=0;

	q=strstr(p,toke[30]);

	if(q!=NULL){
		strncpy(seg1,p,q-p);
		p=q+8;
	}

	q=strstr(p,toke[29]);
	if(q!=NULL){
		strncpy(seg2,p,q-p);
		p=q+9;
	}
	strcpy(seg3,p);

//	seg1[strlen(seg1)]=' ';
//	seg2[strlen(seg2)]=' ';
//	seg3[strlen(seg3)]=' ';

//	printf("seg1 is %s\n",seg1);
//	printf("seg2 is %s\n",seg2);
//	printf("seg3 is %s\n",seg3);

	ret+=getValue(seg1)*1000000+getValue(seg2)*1000+getValue(seg3);

	return ret*sign;
}
int main(){
	while(1){
		gets(str);
		if(str[0]=='\0')break;
		printf("%d\n",handle());
	}
	return 0;
}
