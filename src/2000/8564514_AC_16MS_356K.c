#include <stdio.h>
int n;
int main(){
	while(1){
		scanf("%d",&n);
		if(!n) break;

		int i=1;
		while(i*(i+1)/2<=n){
			i++;
		}
		i--;
		int sum=i*(i+1)*(2*i+1)/6;
		sum+=(n-i*(i+1)/2)*(i+1);
		printf("%d %d\n",n,sum);






	}
	return 0;
}
