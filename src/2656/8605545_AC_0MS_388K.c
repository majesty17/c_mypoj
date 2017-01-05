#include <stdio.h>
int n;

int main(){
	int tem1,tem2,i;
	int day;
	int max=-1;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		day=0;
		max=-1;
		for(i=0;i<n;i++){
			scanf("%d %d",&tem1,&tem2);
			int sum=tem1+tem2;
			if(sum>8){
				if(sum>max){
					max=sum;
					day=i+1;
				}
			}


		}

		printf("%d\n",day);


	}
	return 0;
}
