#include <stdio.h>
int n;
int candy[1000];
int allsame(){
	int i;
	for(i=1;i<n;i++){
		if(candy[i]!=candy[0]) return 0;
	}
	return 1;
}
int main(){
	int i,round;
	while(1){
		scanf("%d",&n);
		if(0==n) break;
		for(i=0;i<n;i++) scanf("%d",&candy[i]);
		round=0;
		while(1){
			if(allsame()==1) {
				printf("%d %d\n",round,candy[0]);
				break;
			}

			int tem=candy[n-1]/2;
			for(i=n-1;i>0;i--){
				candy[i]=candy[i]/2+candy[i-1]/2;
			}
			candy[0]=candy[0]/2+tem;

			for(i=0;i<n;i++){
				if(candy[i]%2==1) candy[i]++;
			}
			round++;

		}


//		printf("%d\n",round);







	}
	return 0;
}
