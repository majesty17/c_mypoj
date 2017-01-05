#include <stdio.h>
#include <string.h>
char line[20];
int po[]={26,676,17576,456976,11881376,308915776};
int main(){
	while(1){
		scanf("%s",&line);
		if(strcmp(line,"R0C0")==0) break;

		char *p=strchr(line,'C');
		*p='\0';
		p++;
		int c;
		sscanf(p,"%d",&c);
		int i=0;
		while(c>po[i]){

			c-=po[i];
			i++;

		}
		i++;
//		printf("i is %d,c is %d\n",i,c);
		//printf("c is %d %s\n",c,line);
		c--;
		while(i--){
			if(i>0){
				printf("%c",c/po[i-1]+'A');
				c=c%po[i-1];
			}else{
				printf("%c",c+'A');
			}
		}






		printf("%s\n",line+1);
	}




	return 0;
}
