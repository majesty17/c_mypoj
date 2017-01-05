#include <stdio.h>
#include <string.h>
int c;
char str1[111];
char str2[111];

char pre1[111],tail1[111];
char pre2[111],tail2[111];


int len1,len2;
int main(){
	int i;
	scanf("%d\n",&c);
	while(c--){
		gets(str1);
		gets(str2);
		len1=strlen(str1);
		len2=strlen(str2);
//		printf("%s\n",str1);
//		printf("%s\n",str2);
		memset(pre1,0,60);
		memset(pre2,0,60);
		memset(tail1,0,60);
		memset(tail2,0,60);
		char *p=strchr(str1,'<');
		char *q=strchr(p,'>');
		memcpy(pre1,p+1,q-p-1);
		p=strchr(q,'<');
		memcpy(tail1,q+1,p-q-1);
		q=strchr(p,'>');
		memcpy(pre2,p+1,q-p-1);
		strcpy(tail2,q+1);


//		printf("[%s] [%s] [%s] [%s]\n",pre1,tail1,pre2,tail2);




		for(i=0;i<len1;i++){
			if(str1[i]!='<' && str1[i]!='>') printf("%c",str1[i]);
		}
		printf("\n");
		for(i=0;i<len2;i++){
			if(str2[i]=='.'){
				printf("%s%s%s%s",pre2,tail1,pre1,tail2);
				break;
			}
			printf("%c",str2[i]);
		}

		printf("\n");

	}
	return 0;
}
