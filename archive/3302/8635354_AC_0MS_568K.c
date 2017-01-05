#include <stdio.h>
int n;
char str1[101],str2[101];
int substr(char *str,char *sub){
	int len=strlen(sub);
	int i;
	char *p;
	p=str;
	for(i=0;i<len;i++){
		p=strchr(p,sub[i]);
		if(p==NULL) return 0;
		p++;
	}

	return 1;
}
int main(){
	scanf("%d",&n);
	while (n--){
		scanf("%s %s",&str1,&str2);
		if(substr(str1,str2)==0 && substr(strrev(str1),str2)==0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
