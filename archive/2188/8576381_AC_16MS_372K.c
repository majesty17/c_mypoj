#include <stdio.h>
int n;
int a[3][1000]={0,};
int main(){
	int i,j,sum=0;
	scanf("%d",&n);
	if(n<1 || n>1000) return -1;
	for(i=0;i<n;i++){
		scanf("%d %d",&a[0][i],&a[1][i]);
	}
	for(i=0;i<n;i++){

		int tem=a[0][i];

		for(j=0;j<n;j++){
			if(a[1][j]==tem && a[2][j]==0){
//				printf("a[1][i] is %d\n",a[1][i]);
				a[1][j]=i+1;
				a[2][j]=1;
				break;
			}
		}
		a[0][i]=i+1;
	}
//	for(i=0;i<n;i++){
//		printf("a is %d %d\n",a[0][i],a[1][i]);
//	}
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[1][i]>a[1][j]){
				sum++;
			}
		}
	}
	printf("%d\n",sum);



	return 0;
}
