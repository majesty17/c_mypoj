#include <stdio.h>
int N;
int len;
char code[25];
char buff[15];
int isLetter(char c){
	if (c>='A' && c<='Z') return 1;
	else return 0;
}
int isNumber(char c){
	if (c>='0' && c<='9') return 1;
	else return 0;
}
int mutate(int start){
	int count=0;
	if(start>=len) return 0;
	char c=code[start];

	if(isLetter(c)){
		count = mutate(start+1);
		code[start] = (count%10+'0');
		count++;
		return count;
   }
	else if(c == '0')
    	return 0;
	else if(isNumber(c)){
		code[start] = (char)(c-1);
		if((start+c-'0')< len)
			count = mutate(start+c-'0');
		else
			count = mutate(start+1);
		count++;
		return count;
	}

  return -1;
}

void handle(){
	if(code[0]=='0'){
		printf("%s\n",code);
		return;
	}
	mutate(0);
	printf("%s\n",code);

}
int main(){
	while(1){
		scanf("%s",&buff);
		if(strcmp(buff,"ENDOFINPUT")==0) break;
		scanf("%d %s %s",&N,&code,&buff);
		len=strlen(code);
		handle();



	}



	return 0;
}
