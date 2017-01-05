#include <stdio.h>
char key[11];
char code[101];
char map[11][11];

int main(){
	int weight,height,i,j;
	char buffer[11];
	while(1){
		scanf("%s",&key);
		if(strcmp(key,"THEEND")==0) break;
		scanf("%s",&code);
		weight=strlen(key);
		height=strlen(code)/weight;

		strcpy(buffer,key);
		char minj;
		for(i=0;i<weight;i++){
			minj=0;
			for(j=1;j<weight;j++){
				if(buffer[j]<buffer[minj]) minj=j;
			}
			buffer[minj]='z'+1;

			for(j=0;j<height;j++){
				map[j][minj]=code[i*height+j];
			}




		}







		for(i=0;i<height;i++){
			for(j=0;j<weight;j++){
				printf("%c",map[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
