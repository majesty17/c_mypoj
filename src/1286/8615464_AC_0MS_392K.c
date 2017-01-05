//Polya定理应用
#include <stdio.h>
int c,s;
int map[33][33];	//
long long gcd(long long a,long long b){
	if (b==0) return a;
	return gcd(b,a%b);
}
long long pow(int a, int b){
	long long ret=1;
	while (b--)ret*=a;
	return ret;
}
long long handle(){
	long long ret=0;
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
	c=3;
	while(1){
		scanf("%d",&s);
		if(0==s) {printf("0\n"); continue;}

		if(s==-1) break;

		printf("%d\n",handle()/2/s);
	}
	return 0;
}
