#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846264338328
int n;
double r;
double point[2][100];
int main(){
	int i;
	scanf("%d %lf",&n,&r);
	for(i=0;i<n;i++){
		scanf("%lf %lf",&point[0][i],&point[1][i]);
	}
	double sum=hypot(point[0][0]-point[0][n-1],point[1][0]-point[1][n-1]);
	for(i=1;i<n;i++){
		sum+=hypot(point[0][i]-point[0][i-1],point[1][i]-point[1][i-1]);
	}
	if(n>=3)printf("%.2f\n",sum+r*(2)*PI);
	else printf("%.2f\n",sum+r*2.0*PI);
	return 0;
}
