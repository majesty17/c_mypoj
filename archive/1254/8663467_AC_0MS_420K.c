#include <stdio.h>
#include <math.h>
#define PI acos(-1)
int c;
int x01,y01,arc01;
int x02,y02,arc02;
double x,y;
int main(){
	scanf("%d",&c);
	while(c--){
		scanf("%d %d %d",&x01,&y01,&arc01);
		scanf("%d %d %d",&x02,&y02,&arc02);
		if(arc01==90 || arc01==270){
			y=(double)y01;
			x=x02-tan(arc02*PI/180.0)*(y02-y);
		}
		else if(arc02==90 || arc02==270){
			y=(double)y02;
			x=x01-tan(arc01*PI/180.0)*(y01-y);
		}
		else{
			double t1=tan(arc01*PI/180.0);
			double t2=tan(arc02*PI/180.0);
			y=(x01-x02-y01*t1+y02*t2)/(t2-t1);
			x=x01-y01*t1+y*t1;
		}


		printf("%.4f %.4f\n",x,y);
	}
	return 0;
}
