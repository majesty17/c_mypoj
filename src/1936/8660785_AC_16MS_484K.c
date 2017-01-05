#include <stdio.h>
char str1[100001];
char str2[100001];
int len1,len2;
int issubstr(){
	len1=strlen(str1);
	len2=strlen(str2);
	char *p=str2,*q;
	int i;
	for(i=0;i<len1;i++){
		q=strchr(p,str1[i]);
		if(q==NULL)return 0;
		p=q+1;
		if(p>=str2+len2 && i<len1-1)return 0;
	}
	return 1;
}
int main(){
	while(scanf("%s %s",&str1,&str2)!=EOF){
		if(issubstr()==1)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
