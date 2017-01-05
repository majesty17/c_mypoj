#include <stdio.h>
#include <string.h>
char str[150];
char buff[15];

int main(){
	int i;
	while(1){
		gets(buff);
		if(strcmp(buff,"ENDOFINPUT")==0) break;
		gets(str);
		gets(buff);


		for(i=0;i<strlen(str);i++){
			if (str[i]>='A' && str[i]<='Z') str[i]=(str[i]-'A'+21)%26+'A';
		}

		printf("%s\n",str);
	}


	return 0;
}
