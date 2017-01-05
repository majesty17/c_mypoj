#include <stdio.h>
#include <string.h>
char line[500];
int main(){
	int i,sign=0;
	while (gets(line)!=NULL){
		for(i=0;i<strlen(line);i++){
			if(line[i]=='"'){
				if(sign%2==0) printf("``");
				else printf("''");
				sign++;
			}
			else{
				printf("%c",line[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
