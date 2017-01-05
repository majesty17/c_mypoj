#include <stdio.h>
char white[100]={0,};
char black[100]={0,};
char map[50][50]={
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+",
	"|...|:::|...|:::|...|:::|...|:::|",
	"+---+---+---+---+---+---+---+---+",
	"|:::|...|:::|...|:::|...|:::|...|",
	"+---+---+---+---+---+---+---+---+"
};

int main(){
	gets(white);
	gets(black);

	char *p=strchr(white,':');
	p+=2;

	while(*p!='\0'){
		switch (*p){
			case 'K':
			case 'Q':
			case 'R':
			case 'B':
			case 'N':{
				map[18-(*(p+2)-'0')*2-1][(*(p+1)-'a')*4+2]=*p;
				p+=4;
				break;
			}

			default:{
				map[18-(*(p+1)-'0')*2-1][(*(p)-'a')*4+2]='P';
				p+=3;
			}
				break;
		}
	}



	p=strchr(black,':');
	p+=2;

	while(*p!='\0'){
		switch (*p){
			case 'K':
			case 'Q':
			case 'R':
			case 'B':
			case 'N':{
				map[18-(*(p+2)-'0')*2-1][(*(p+1)-'a')*4+2]=tolower(*p);
				p+=4;
				break;
			}

			default:{
				map[18-(*(p+1)-'0')*2-1][(*(p)-'a')*4+2]='p';
				p+=3;
			}
				break;
		}
	}




	int i;
	for(i=0;i<18;i++){
		puts(map[i]);
	}

	return 0;
}