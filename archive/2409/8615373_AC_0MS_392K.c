//Polya定理应用
#include <stdio.h>
int c,s;
int map[33][33];	//
int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int pow(int a,int b){
	int ret=1;
	while (b--)ret*=a;
	return ret;
}
int handle(){
	int ret=0;
	int i;
	for (i = 1; i <= s; i++)
		ret=ret+pow(c,gcd(s,i));
	if (s&1) {
		ret=ret+s*pow(c,s/2+1);
	} else
		ret=ret+s/2*(pow(c,s/2)+ pow(c, s/2+1));
	return ret;
}
int main(){

	while(1){
		scanf("%d %d",&c,&s);
		if(c==0&&s==0) break;
		printf("%d\n",handle()/2/s);
	}
	return 0;
}
