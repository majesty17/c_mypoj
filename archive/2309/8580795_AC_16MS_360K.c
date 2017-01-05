#include <stdio.h>
int n;
int k;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		if(k%2==1){
			printf("%d %d\n",k,k);
			continue;
		}
		int i=0;
		while (k/(1<<i)*(1<<i)==k){
			i++;
		}


//		printf("i is %d\n",i);
		printf("%d %d\n",k-2*(1<<(i-2))+1,k+2*(1<<(i-2))-1);
	}
	return 0;
}
