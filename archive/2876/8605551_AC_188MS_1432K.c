#include <stdio.h>
int n;
char mem[531441];
char buf[531441];
int pow3(int up){
	int ret=1;
	while(up--){
		ret*=3;
	}
	return ret;
}

void init(){
	memset(mem,' ',531441);
	int i;
	mem[0]='-';
	mem[1]=' ';
	for(i=1;i<=12;i++){
		memcpy(mem+pow3(i)-pow3(i-1),mem,pow3(i-1));
	}
}
int main(){
	init ();

	while(scanf("%d",&n)!=EOF){
		memset(buf,0,531441);
		strncpy(buf,mem,sizeof(char)*pow3(n));

		printf("%s\n",buf);

	}
	return 0;
}
