#include <stdio.h>
#include <math.h>
#define PI 3.1415926535898
int D,V;
double handle(int d,int v){
	return pow((D*D*D-6*(double)V/PI),1.0/3.0);
}
int main(){
	while(1){
		scanf("%d %d",&D,&V);
		if(D==0 && V==0) break;
		printf("%.3f\n",handle(D,V));
	}
	return 0;
}
