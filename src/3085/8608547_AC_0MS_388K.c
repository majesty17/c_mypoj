#include <stdio.h>
int cases;
int k;
int main(){
	int i,count=0;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&k);
		printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",
				++count,k/25,(k%25)/10,((k%25)%10)/5 ,k%5);
	}
	return 0;
}
