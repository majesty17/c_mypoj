#include <stdio.h>

long long int a[4][5];
int main(){
int n,i,j;
long long int det1,det2,det3,det;
scanf("%d",&n);
double x;
while(n--){
for(i=1;i<=3;i++)
for(j=1;j<=4;j++)
scanf("%lld",&a[i][j]);
det=a[1][1]*(a[2][2]*a[3][3]-a[2][3]*a[3][2])-a[1][2]*(a[2][1]*a[3][3]-a[2][3]*a[3][1])+a[1][3]*(a[2][1]*a[3][2]-a[2][2]*a[3][1]);
det1=a[1][4]*(a[2][2]*a[3][3]-a[2][3]*a[3][2])-a[1][2]*(a[2][4]*a[3][3]-a[2][3]*a[3][4])+a[1][3]*(a[2][4]*a[3][2]-a[2][2]*a[3][4]);
det2=a[1][1]*(a[2][4]*a[3][3]-a[2][3]*a[3][4])-a[1][4]*(a[2][1]*a[3][3]-a[2][3]*a[3][1])+a[1][3]*(a[2][1]*a[3][4]-a[2][4]*a[3][1]);
det3=a[1][1]*(a[2][2]*a[3][4]-a[2][4]*a[3][2])-a[1][2]*(a[2][1]*a[3][4]-a[2][4]*a[3][1])+a[1][4]*(a[2][1]*a[3][2]-a[2][2]*a[3][1]);
printf("%lld %lld %lld %lld\n",det1,det2,det3,det);
if(det==0)
printf("No unique solution\n");
else
{printf("Unique solution: ");
x=(double)det1/(double)det;
if(x>-0.0005&&x<0.0005)
x=0;
printf("%.3lf ",x);
x=(double)det2/(double)det;
if(x>-0.0005&&x<0.0005)
x=0;
printf("%.3lf ",x);
x=(double)det3/(double)det;
if(x>-0.0005&&x<0.0005)
x=0;
printf("%.3lf\n",x);
}
printf("\n");
}
return 1;
}
