#include <stdio.h>
#include <math.h>
int n;
float ver[2][1000];
float getArea(){
	float ret=ver[0][n-1]*ver[1][0]-ver[0][0]*ver[1][n-1];
	int i;
	for(i=0;i<n-1;i++){
		ret+=ver[0][i]*ver[1][i+1]-ver[0][i+1]*ver[1][i];
	}
	ret/=2.0;
	ret=fabs(ret);
	return ret;
}
int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			scanf("%f %f",&ver[0][i],&ver[1][i]);
		}
		if(n<=2){
			printf("0\n");
		}
		else{
			printf("%.0f\n",getArea());
		}

	}
	return 0;
}
