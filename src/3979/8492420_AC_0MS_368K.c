#include <stdio.h>
///str:	a/boc/d
///o:		+|-
///res:	m/n
void reduce(int*,int*);
void process(char *str){
//	printf("=====\n ");
	int a,b,c,d,m,n;
	a=str[0]-'0';
	b=str[2]-'0';
	c=str[4]-'0';
	d=str[6]-'0';
	//通分
	a*=d;
	c*=b;
	d*=b;
	b=d;
//	printf("%d/%d%c%d/%d\n",a,b,str[3],c,d);
	//计算
	m=(str[3]=='+')?(a+c):(a-c);
	n=b;
	if(m==0){
		printf("0\n");
		return;
	}
	//约分
	if(m!=1 && n!=1){
		reduce(&m,&n);
	}
	if(n==1){
		printf("%d\n",m);
		return;

	}
//	else if(m*(m>0?1:-1)>n){
//		printf("");
//	}
	//显示
	printf("%d/%d\n",m,n);

//	printf("======\n");
	return;
}
void reduce(int *x,int *y){
	int num1=*x;
	int num2=*y;

	int sign1=num1>0?1:-1;
	int sign2=num2>0?1:-1;

	num1*=sign1;
	num2*=sign2;

	//printf("num1=%d num2=%d\n",num1,num2);
	int len=num1<num2?num1:num2;
	while(len){
		//printf("len=%d,num1=%d,num2=%d\n",len,num1,num2);
		if(num1%len==0 && num2%len==0){
			num1=num1/len;
			num2=num2/len;
			break;
		}
		len--;
	}
	*x=num1*sign1,*y=num2*sign2;
	return;
}

int main(){
	char a[15];
	while(scanf("%s",a)!=EOF){
		if(a[2]=='0' || a[6]=='0'){
			break;
		}
		process(a);
	}
	return 0;
}
