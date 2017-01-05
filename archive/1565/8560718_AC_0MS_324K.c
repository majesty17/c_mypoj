#include <stdio.h>
#include <string.h>
char str[40];
void handle(){
	int len=strlen(str);
	int i,sum=0;
	for(i=0;i<len;i++){
//		printf("%d %d\n",str[i]-'0',sum);
		sum+=(str[i]-'0')*((1<<(len-i))-1);
	}

	printf("%d\n",sum);
}
int main(){
	while(1){
		scanf("%s",&str);
		if(strcmp(str,"0")==0) break;

		handle();



	}
	return 0;
}
