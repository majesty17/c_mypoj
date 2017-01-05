#include <stdio.h>
#include <string.h>
int nephews,cds;
char wholerus[31];
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
void myPower(int lower){					//wholerus=lower^power
	int i=cds;
	while(i--){
		mul(lower);
	}
}
int main(){
	while(1){
		scanf("%d %d",&nephews,&cds);
		if(nephews==0 && cds==0)break;
		memset(wholerus,0,31);
		strcpy(wholerus,"1");
		myPower(nephews);
		printf("%s\n",strrev(wholerus));
	}
	return 0;
}
