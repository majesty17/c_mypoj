#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
double x,y,x2,y2,x3,y3;
int main(){

	while(scanf("%lf %lf %lf %lf %lf %lf",&x,&y,&x2,&y2,&x3,&y3)!=EOF){

		double dis12=hypot(x2-x,y2-y);
		double dis13=hypot(x3-x,y3-y);
		double dis23=hypot(x2-x3,y2-y3);
		double p=(dis12+dis13+dis23)/2.0;
		double S=sqrt(p*(p-dis12)*(p-dis13)*(p-dis23));

		printf("%.2f\n",dis12*dis13*dis23*PI/2.0/S);


//		if((y-y2)*(y-y3)+(x-x2)*(x-x3)==0) {
//			printf("%.2lf\n",PI*dis23);
//			continue;
//		}
//		if((y2-y)*(y2-y3)+(x2-x)*(x2-x3)==0) {
//			printf("%.2lf\n",PI*dis13);
//			continue;
//		}
//		if((y3-y2)*(y3-y)+(x3-x2)*(x3-x)==0) {
//			printf("%.2lf\n",PI*dis13);
//			continue;
//		}
//
//
//
//
//
//		y=((y2*y2-y*y+x2*x2+x*x)*(x3-x)-(y3*y3-y*y+x3*x3-x*x)*(x2-x))/((y2-y)*(x3-x)-(x2-x)*(y3-y))/2.0;
//
//		x=((y2*y2-y*y+x2*x2+x*x)*(y3-y)-(y3*y3-y*y+x3*x3-x*x)*(y2-y))/((y2-y)*(x3-x)-(x2-x)*(y3-y))/2.0;
//
//		printf("%.2lf\n",2.0*PI*sqrt((y-y)*(y-y)+(x-x)*(x-x)));



	}
	return 0;
}
