#include <stdio.h>
int n;
int num[1001];
int a,b,c,d,e,f,g,h,i;


int func(int arg){

	if(arg%2==1) return mymod(d*num[arg-1]+e*num[arg-2]-f*num[arg-3],g);
	if(arg%2==0) return mymod(f*num[arg-1]-d*num[arg-2]+e*num[arg-3],h);
}
int mymod(int num1,int num2){
	int m=num1%num2;
	if(m<0)return m+num2;
	else return m;

}
int main(){
	int j;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h,&i);
		num[0]=a;num[1]=b;num[2]=c;
		for(j=3;j<=i;j++){
			num[j]=func(j);
		}

		printf("%d\n",num[i]);
	}
	return 0;
}
