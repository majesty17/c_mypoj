#include <stdio.h>
int n;
int num[1000][1000];
int main(){
	int i,j,k,h;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&num[i][j]);
			}
		}
		int sign=0;
		///方法1，判断所有2×2子矩阵，超时。。。
//		for(i=0;i<n-1;i++){
//			for(j=i+1;j<n;j++){
//				for(k=0;k<n-1;k++){
//					for(h=k+1;h<n;h++){
//						if(num[i][k]+num[j][h]!=num[i][h]+num[j][k]) sign=1;
//					}
//				}
//			}
//		}
		///方法2，判断每列差值，
		for(i=1;i<n;i++){
			int minus=num[i][0]-num[i-1][0];
			for(j=1;j<n;j++){
				if(num[i][j]-num[i-1][j]!=minus) sign=1;
			}
		}

		if(sign==1) printf("not homogeneous\n");
		else printf("homogeneous\n");

	}
	return 0;
}
