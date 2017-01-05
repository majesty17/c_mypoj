#include <stdio.h>
int num[1001];
int c;
int k;
int getMinArea(int num){
	int i,j,k;
	int min=0x7fffffff;
	int tmp;
	for(i=1;i<=num;i++){
		if(num%i)continue;
		for(k=1;k<=num/i;k++){
			if((num/i)%k)continue;
			tmp=2*(i*k+num/i+num/k);
			min=min<tmp?min:tmp;
		}
	}
	return min;
}
void maketable(){
	num[0]=0;
	int i;
	for(i=1;i<=1000;i++){
		num[i]=getMinArea(i);
	}

}
int main(){
	maketable();
	scanf("%d",&c);
	while(c--){
		scanf("%d",&k);
		printf("%d\n",num[k]);
	}
	return 0;
}
