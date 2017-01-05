#include <stdio.h>
#include <string.h>
#include <ctype.h>
char line[201];



int main(){

	while(1){
		gets(line);
		if(strcmp(line,"ENDOFINPUT")==0) break;
		gets(line);
		int i,len=strlen(line);
		for(i=0;i<len;i++){
			if(isupper(line[i])){
				line[i]=(line[i]-'A'+21)%26+'A';
			}
		}

		printf("%s\n",line);


		gets(line);
	}



	return 0;
}
