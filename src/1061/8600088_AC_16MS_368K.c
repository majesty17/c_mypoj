#include <stdio.h>
__int64 x,y,m,n,L;
__int64 a,b,c;

__int64 q[1000];
__int64 s[1001]={1,0,};

__int64 getGCD(__int64 num1, __int64 num2){
	while(num2 != 0){
		__int64 r = num2;
		num2 = num1 % num2;
		num1 = r;
	}
	return num1>0?num1:-num1;
}
void getQ(__int64 num1, __int64 num2,__int64 *deep,__int64 *got){
	__int64 i=0;
	while(num2 != 0){
		__int64 r = num2;
		q[i++]=num1/num2;
		num2 = num1 % num2;
		num1 = r;
	}
	*deep=i;
	__int64 j;
	for(j=2;j<=i;j++){
		s[j]=s[j-2]-s[j-1]*q[j-2];
	}

	*got=s[i];

}
__int64 main(){
//	__int64 deep,n,j;
//	getQ(256,37,&deep,&n);
//	printf("deep is %d\n",deep);
//	printf("got is %d\n",n);
//	for(j=0;j<deep;j++){
//		printf("%d,",q[j]);
//	}
//	return 0;

	__int64 i;
	scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&L);
	if(x==y){
		printf("0\n");
		return 0;
	}
	else if(m==n){
		printf("Impossible\n");
		return -1;
	}
//	printf("L is %d\n",L);

	b = L;

	if(n>m){
		a=n-m;
		c=x-y;
	}
	else{
		a=m-n;
		c=y-x;
	}



	__int64 GCD=getGCD(a,b);


	if(c%GCD!=0) {
		printf("Impossible\n");
		return 0;
	}
	a/=GCD;
	b/=GCD;
	c/=GCD;

//	printf("GCD is %d\n",GCD);
//	printf("a=%d,b=%d,c=%d\n",a,b,c);

	__int64 deep,t;
	getQ(a,b,&deep,&t);
//	printf("t is %d\n",t);
	if(t*c>0){
		printf("%lld\n",(t*c)%b);
	}
	else{
		printf("%lld\n",(t*c)%b+b);
	}

	return 0;
}
