#include <stdio.h>
#include <math.h>
int n;
int mypow(int low,int up){
	int ret=1,i;
	for(i=0;i<up;i++){
		ret*=low;
	}
	return ret;
}
int getMaxPower(int num){
	if(num==0x80000000 )return 31;
	int sign=1;
	if(num<0){
		num=-num;
		sign=-1;
	}
	int i;
	double num_d=(double)num;

	double tmp_d;
	int tmp_i;
	//i是指数

	for(i=32;i>=1;i--){
		if(sign==-1 && i%2==0)continue;
		tmp_d=pow(num_d,1.0/(double)i);
//		tmp_i=ceil(tmp_d);
//		printf("tmp_d is %f <%d>\n",tmp_d,tmp_i);
//		if(mypow(tmp_i,i)==num) return i;
		if(tmp_d-(int)tmp_d<1e-12||(int)tmp_d+1-tmp_d<1e-12)return i;
	}
	return 1;
}
int main(){
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		printf("%d\n",getMaxPower(n));
	}
	return 0;
}
