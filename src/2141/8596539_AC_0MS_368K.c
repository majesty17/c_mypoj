#include <stdio.h>
#include <string.h>
#include <ctype.h>
char map[27];
char code[81];
int main(){
	gets(map);
	gets(code);
	int i;
	for(i=0;i<strlen(code);i++){
		if(isupper(code[i])){
			printf("%c",map[code[i]-'A']-'a'+'A');
		}
		else if(islower(code[i])){
			printf("%c",map[code[i]-'a']);
		}
		else if(isspace(code[i])){
			printf("%c",code[i]);
		}
	}
	printf("\n");

	return 0;
}
