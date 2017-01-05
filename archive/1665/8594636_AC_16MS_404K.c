#include <stdio.h>
#define PI 3.1415927
float diameter,time;
int revolution;
int main(){
	int count=0;
	while(1){
		scanf("%f %d %f",&diameter,&revolution,&time);
		if(revolution==0) break;
		float miles=diameter*PI*revolution/63360.0;
		printf("Trip #%d: %.2f %.2f\n",++count,miles,miles/(time/3600.0));
	}
	return 0;
}
