#include <stdio.h>
#include <math.h>
int B,N;
int main(){
	while(1){
		scanf("%d %d",&B,&N);
		if(B==0 && N==0) break;
		double ret=pow((double)B,1.0/(double)N);

		double t1=B-pow((int)(ret),N);
		double t2=pow((int)(ret)+1,N)-B;


		if(t2>t1) printf("%d\n",(int)(ret));
		else printf("%d\n",(int)(ret)+1);



	}
	return 0;
}
