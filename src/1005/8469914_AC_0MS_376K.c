#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i,k;
	float *x,*y,p=3.1416;
	int len;
	scanf("%d",&n);
	x=(float*)malloc(n*sizeof(float));
	y=(float*)malloc(n*sizeof(float));
	for(i=0;i<n;i++){
		scanf("%f %f",&x[i],&y[i]);
//		printf("%f\t %f\n",x[i],y[i]);
	}

	for(i=0;i<n;i++){



		len=(int)((x[i]*x[i]+y[i]*y[i])*p/100+1);

		printf("Property %d: This property will begin eroding in year %d.\n",i+1,len);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
