#include "stdio.h"
#include "string.h"




int main(){
	char a[27][400]={0,};
	int i,j;
	char buf[110];
	char c;
	int max=0;
	for(i=0;i<4;i++){
		//memset(buf,0,100);
		gets(buf);
		for(j=0;j<strlen(buf);j++){
			c=buf[j];
			if(c>='A' && c<='Z'){
				c=c-'A'+1;
				a[c][strlen(a[c])]='*';
				if(strlen(a[c])>max){
					max=strlen(a[c]);
				}
			}
		}
	}

	for(i=max;i>=1;i--){
		for(j=1;j<=26;j++){
			if(a[j][i-1]=='*')
				printf("* ",a[j][i-1]);
				else
				printf("  ");

		}
		printf("\n");
	}
	printf("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z ");
	//gets(buf);
	return 0;
}
