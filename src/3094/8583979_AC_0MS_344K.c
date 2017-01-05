#include <stdio.h>
#include <ctype.h>
#include <string.h>
char line[100];
int main(){
	int sum,i;
	while(1){
		gets(line);
		if(strcmp(line,"#")==0) break;
		sum=0;
		for(i=0;i<strlen(line);i++){
			if(isalpha(line[i])){
				sum+=(i+1)*(line[i]-'A'+1);
			}
		}

		printf("%d\n",sum);


	}
	return 0;
}
