#include <stdio.h>
#include <string.h>
#include <ctype.h>
int n;
char a[9],b[9];
int base(char a){
	switch (a){
		case 'm':{
			return 1000;
			break;
		}
		case 'c':{
			return 100;
			break;
		}
		case 'x':{
			return 10;
			break;
		}
		case 'i':{
			return 1;
			break;
		}
	}
}
int tonum(char *str){
	int ret=0;
	int len=strlen(str);
	int i;
	for(i=0;i<len;i++){
		if(isdigit(str[i])) {
			ret+=(str[i]-'0')*base(str[i+1]);
			i++;
		}
		else{
			ret+=base(str[i]);
		}
	}
	return ret;
}
void prints(int a){
	int m=a/1000;
	int c=(a/100)%10;
	int x=(a/10)%10;
	int i=a%10;
	if(m>1) printf("%dm",m);
	else if(m==0) ;
	else printf("m");
	if(c>1) printf("%dc",c);
	else if(c==0) ;
	else printf("c");
	if(x>1) printf("%dx",x);
	else if(x==0) ;
	else printf("x");
	if(i>1) printf("%di",i);
	else if(i==0) ;
	else printf("i");
	printf("\n");
}
void handle(){
	int sum=tonum(a)+tonum(b);
	prints(sum);
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s %s",&a,&b);
		handle();
	}
	return 0;
}
