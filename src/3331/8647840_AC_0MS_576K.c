#include <stdio.h>
int c;
int n;
char digit;
char wholerus[800];
void mul(int lo){							//wholerus*=lower
	int len=strlen(wholerus);
	int c=0,i,temp;

	for(i=0;i<len;i++){
		temp=(wholerus[i]-'0')*lo+c;
		wholerus[i]=temp%10+'0';
		c=temp/10;
	}
	if(c!=0){
		char buf[10];
		itoa(c,buf,10);
		strcat(wholerus,strrev(buf));
	}
}
int main(){
	int i;
	scanf("%d",&c);
	while(c--){
		scanf("%d %c",&n,&digit);
		strcpy(wholerus,"1");
		for(i=2;i<=n;i++){
			mul(i);
		}
//		printf("%s\n",wholerus);
		int sum=0;
		for(i=0;i<strlen(wholerus);i++){
			if(wholerus[i]==digit) sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
