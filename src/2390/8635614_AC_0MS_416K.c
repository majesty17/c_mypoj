#include <stdio.h>
#include <math.h>
int R,M,Y;
int main(){
	scanf("%d %d %d",&R,&M,&Y);


	printf("%d\n",(int)((double)M*pow((double)(1.0+(double)R/100),Y)));
	return 0;
}
