#include <stdio.h>
int n;
int a[1501];
void handle(){
	a[1]=1;

	int p2=1,p3=1,p5=1;
	int i;
	for(i=2;i<=1500;i++)
	{
		int *x;
		int min=1000000000;
		int c2=a[p2]*2,c3=a[p3]*3,c5=a[p5]*5;
		if(min>c2){min=c2;x=&p2;}
		if(min>c3){min=c3;x=&p3;}
		if(min>c5){min=c5;x=&p5;}
		a[i]=min;
		(*x)++;
		while(a[p2]*2<=a[i])p2++;
		while(a[p3]*3<=a[i])p3++;
		while(a[p5]*5<=a[i])p5++;
	}
}
int main(){
	handle();
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		printf("%d\n",a[n]);
	}
	return 0;
}
