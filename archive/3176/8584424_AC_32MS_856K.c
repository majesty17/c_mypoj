#include <stdio.h>


int a[360][360]={0,};
int main(){
	int line,i,j;
	scanf("%d",&line);
	//if(line<=1 || line>350) return -1;
	for(i=1;i<=line;i++){
		for(j=1;j<=i;j++){
			scanf("%d",&a[i][j]);
		}
	}

	for(i=2;i<=line;i++){
		for(j=1;j<=i;j++){
			//a[i][j]
//			if(j==1) {
//				a[i][j]+=a[i-1][j];
//			}
//			else if(j==i){
//				a[i][j]+=a[i-1][j-1];
//			}else{
				a[i][j]+=(a[i-1][j-1]>a[i-1][j])?(a[i-1][j-1]):(a[i-1][j]);
//			}
//			printf("%d,",a[i][j]);
		}
//		printf("\n");
	}
	int max=a[line][1];
	for(i=2;i<=line;i++) max=a[line][i]>max?a[line][i]:max;
	printf("%d\n",max);

}
