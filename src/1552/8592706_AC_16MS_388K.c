#include <stdio.h>
int num[16];
int main(){
	int n,i,j,sum;
	while(1){
		n=0;
		sum=0;
		while(1){
			scanf("%d",&num[n++]);
			if(num[n-1]==0) break;
			else if(num[n-1]==-1) return ;
		}
		n--;
//		printf("n is %d\n",n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j) continue;
				if(num[j]==num[i]*2) sum++;
			}
		}



		printf("%d\n",sum);


	}
	return 0;
}
