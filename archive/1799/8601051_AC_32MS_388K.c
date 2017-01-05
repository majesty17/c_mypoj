#include <stdio.h>
#include <math.h>
#define PI acos(-1.0)
int cases;
float R;
int n;

float getr(float r1,int k){
	float si=sin(PI/(float)k);
	return r1*si/(si+1.0);
}
int main(){
	int count=0;
	scanf("%d",&cases);
	while(cases--){
		scanf("%f %d",&R,&n);
		if(n==1|| n==2){
			printf("Scenario #%d:\n%.3f\n\n",++count,R/n);
			continue;
		}
		else printf("Scenario #%d:\n%.3f\n\n",++count,getr(R,n));

	}
	return 0;
}
