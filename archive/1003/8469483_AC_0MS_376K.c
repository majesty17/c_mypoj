#include <stdio.h>

int cardNum(float d){
	int i=2,n=1;
	while(d-1.0/i >= 0.000001){
		n++;
		d-=1.0/i;
		i++;
	}


	return n;
}

int main(){

	float d;
	while(scanf("%f",&d)!=EOF){
		if(d==0.0) return 1;
		printf("%d card(s)\n",cardNum(d));
	}
	return 0;
}
