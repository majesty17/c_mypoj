#include <stdio.h>
#include <string.h>
int n,sum;
char a[12]={0,};
int pailie(int big,int sma){
	int ret=1,i;
	for(i=0;i<sma;i++){
		ret*=big-i;
	}
	for(i=2;i<=sma;i++){
		ret/=i;
	}
//	printf("pailie is %d\n",ret);
	return ret;
}
int getsum(){
	int i;
	int ret=0;
	for(i=0;i<n;i++){
		ret+=a[i]*pailie(n-1,i);
	}
//	printf("ret is %d\n",ret);
	return ret;
}
int cmp(const void *a,const void *b){
	return *(char*)a-*(char*)b;
}
int next(){
	int i,j,k;

	for(i=n-2;i>=0;i--){
		for(j=n-1;j>i;j--){
			if(a[i]<a[j]){

				a[i]=a[i]^a[j];
				a[j]=a[i]^a[j];
				a[i]=a[i]^a[j];
				qsort(&a[i+1],n-i-1,sizeof(a[0]),cmp);

				return 1;
			}
		}
	}
	return 0;
}
int main(){
	int i;
	scanf("%d %d",&n,&sum);
	if(n==1 && sum==1){
		printf("1\n");
		return 0;
	}
	for(i=0;i<n;i++){
		a[i]=i+1;
	}

	while(1){
		if(getsum()==sum){
			for(i=0;i<n;i++){
				printf("%d",a[i]);
				if(i<n-1)printf(" ");
			}
			printf("\n");
			break;
		}
		if(next()==0) break;
	}


	return 0;
}
