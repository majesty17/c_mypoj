#include <stdio.h>
int pos,k1,k2,k3;
int main(){
	while(1){
		scanf("%d %d %d %d",&pos,&k1,&k2,&k3);
		if(pos==0 && k1==0 && k2==0 && k3==0) break;
		int sum=40+40;
		if(pos>=k1) sum+=pos-k1;
		else sum+=pos+40-k1;
		sum+=40;
		if(k2>=k1) sum+=k2-k1;
		else sum+=k2+40-k1;

		if(k2>=k3) sum+=k2-k3;
		else sum+=k2+40-k3;
		printf("%d\n",sum*9);
	}
	return 0;
}
