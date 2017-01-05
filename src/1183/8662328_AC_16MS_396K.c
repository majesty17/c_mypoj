#include <stdio.h>
#include <math.h>
__int64 a;
int main(){
	int i;
	scanf("%I64d",&a);
	double xi=sqrt((double)a*a+1.0)+a;
//	printf("exact x is %f\n",xi);
	__int64 x_low=(__int64)floor(xi);
	__int64 x_up=(__int64)ceil(xi);
//	printf("nearest x: %I64d %I64d\n",x_low,x_up);

	__int64 aa_1=a*a+1;
	while(x_low>a && aa_1%(x_low-a)!=0) x_low--;
//	printf("legal x: %I64d %I64d\n",x_low,x_up);

	__int64 rus_low=aa_1/(x_low-a)+a+x_low;


	printf("%I64d\n",rus_low);
	return 0;
}
