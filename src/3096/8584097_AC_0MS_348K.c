#include <stdio.h>
#include <ctype.h>
#include <string.h>
char line[100];
char hashmap[2626];
int handle(){
	int len=strlen(line);
	int i,j,k;
	for(i=0;i<len-1;i++){
		memset(hashmap,0,2626);
		for(j=0;j<len-i-1;j++){
			if(hashmap[(line[j]-'A'+1)*100+(line[j+i+1]-'A'+1)]==1) return 0;
			else{
				hashmap[(line[j]-'A'+1)*100+(line[j+i+1]-'A'+1)]=1;
			}
		}
	}

	return 1;
}
int main(){
	int sum,i;
	while(1){
		gets(line);
		if(strcmp(line,"*")==0) break;

		switch (handle()){
			case 1:{
				printf("%s is surprising.\n",line);
				break;
			}
			case 0:{
				printf("%s is NOT surprising.\n",line);
				break;
			}
		}
	}
	return 0;
}
