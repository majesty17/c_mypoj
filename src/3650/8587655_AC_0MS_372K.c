#include <stdio.h>
char line[100];
int main(){
	int len,i;
	while(1){
		gets(line);
		if(strcmp(line,"#")==0) break;
		len=strlen(line);
		for(i=0;i<len;i++){
			switch (line[i]){
				case ' ':{
					printf("%%20");
					break;
				}
				case '!':{
					printf("%%21");
					break;
				}
				case '$':{
					printf("%%24");
					break;
				}
				case '%':{
					printf("%%25");
					break;
				}
				case '(':{
						printf("%%28");
					break;
				}
				case ')':{
					printf("%%29");
					break;
				}
				case '*':{
					printf("%%2a");
					break;
				}
				default:
					printf("%c",line[i]);
					break;
			}
		}
		printf("\n");

	}
	return 0;
}
