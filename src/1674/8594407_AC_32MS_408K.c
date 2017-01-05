#include <stdio.h>
int n,k;
short num[10001];
int main(){
	int i,count,sign;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		for(i=1;i<=k;i++){
			scanf("%d",&num[i]);
		}

		count=0;
		while(1){
			sign=0;
			for(i=1;i<=k;i++){
				if(num[i]==i) continue;
				else{
					int tem=num[i];
					num[i]=num[i]^num[tem];
					num[tem]=num[i]^num[tem];
					num[i]=num[i]^num[tem];
					count++;
					sign=1;
				}
			}
			if(sign==0) break;
		}



		printf("%d\n",count);

	}
	return 0;
}
