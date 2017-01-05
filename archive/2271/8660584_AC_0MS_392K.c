#include <stdio.h>
#include <string.h>
char hr[]="--------------------------------------------------------------------------------";
char word[81];
int currlen=0;
int getMean(){
	if(strcmp(word,"<br>")==0) return 1;
	if(strcmp(word,"<hr>")==0) return 2;
	return 0;
}
int main(){
	while(scanf("%s",&word)!=EOF){
		switch(getMean()){
			case 1:{
				printf("\n");
				currlen=0;
				continue;
			}
			case 2:{
				if(currlen!=0)printf("\n");
				printf("%s\n",hr);
				currlen=0;
				continue;
			}
			default:{
				int len=strlen(word);
				if(currlen+len>80){
					printf("\n");
					printf("%s ",word);
					currlen=strlen(word)+1;
				}
				else if(currlen+len==80){
					printf("%s",word);
					currlen=0;
				}
				else{
					printf("%s ",word);
					currlen+=strlen(word)+1;
				}

			}
		}



	}
	return 0;
}
