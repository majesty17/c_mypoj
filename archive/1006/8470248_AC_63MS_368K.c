#include <stdio.h>


int c(int p,int e,int i,int d){

	//int c=(p*28*33*6+e*23*33*19+i*23*28*2-d+21252)%21252;
	int c=(5544*p+14421*e+1288*i-d+21252)%21252;
	return c==0?21252:c;
}

int main(){

	int p,e,i,d;
	int n=0;


	scanf("%d%d%d%d",&p,&e,&i,&d);
	while(p!=-1 && e!=-1 && i!=-1 && d!=-1){



		printf("Case %d: the next triple peak occurs in %d days.\n",n+1,c(p,e,i,d));

		scanf("%d%d%d%d",&p,&e,&i,&d);
		n++;

	}
	return 0;
}
