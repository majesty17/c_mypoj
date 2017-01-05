#include <stdio.h>
char line[100];
int main(){
	while(gets(line)!=NULL){
		printf("%s\n",line);
	}
	return 0;
}
