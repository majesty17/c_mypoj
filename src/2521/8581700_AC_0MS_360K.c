//N is the cost price of Jame good.
//M is the sell price.
//P is the total fake money the customer gave Jame.
//C is how much Jame paid back to the customer.

#include <stdio.h>
int N,M,P,C;
int main(){
	while(1){
		scanf("%d %d %d %d",&N,&M,&P,&C);
		if((N|M|P|C)==0) break;

		int truemoney=M+C-P;


		printf("%d\n",N+C-truemoney);



	}
	return 0;
}
