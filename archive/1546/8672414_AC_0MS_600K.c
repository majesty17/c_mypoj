#include <stdio.h>
#include <string.h>
#include <math.h>
char num_from[8];
char num_to[8];
char base_from,base_to;
int charToInt(char a){
	if(a<='9')return a-'0';
	return a-'A'+10;
}
char intToChar(int a){
	if(a<10)return a+'0';
	return a-10+'A';
}
int toBase10(){
	int i,ret=0;
	int len=strlen(num_from);
	for(i=0;i<len;i++){
		ret+=(int)pow((double)base_from,(double)(len-i-1))*(charToInt(num_from[i]));
	}
	return ret;
}
void changeBase(int n,int b){
	int i=0;
	while(n){
		num_to[i]=intToChar(n%b);
		n/=b;
		i++;
	}
	strrev(num_to);
}
int main(){
	int num;
	while(scanf("%s %d %d",&num_from,&base_from,&base_to)!=EOF){
		memset(num_to,0,sizeof(num_to));
		num=toBase10();

		if(num>=(int)pow((double)base_to,7.0)){	//chaoguo 7 wei
			printf("  ERROR\n");
			continue;
		}

		changeBase(num,base_to);
//		printf("%d\n",num);
		printf("%7s\n",num_to);

	}
	return 0;
}
