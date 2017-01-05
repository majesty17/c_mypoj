#include <stdio.h>
#include <stdlib.h>

int n;
int *num;
int main(){
	scanf("%d",&n);
	num=(int*)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",num+i);
	}

	int c_s=0;
	for(i=1;i<n;i++){
		if(num[i]!=num[i-1]){
			c_s=i;
			break;
		}
	}
	if(i==n){
		printf("0\n");
		return -1;
	}
	int sum_s=0;
	for(i=c_s;i<n;i++){
		if(num[i]!=num[c_s]){
			sum_s++;
		}
	}

	int c_e=0;
	for(i=n-2;i>=0;i--){
		if(num[i]!=num[i+1]){
			c_e=i;
			break;
		}
	}
	if(i==-1){
		printf("0\n");
		return -1;
	}
	int sum_e=0;
	for(i=c_e;i>=0;i--){
		if(num[i]!=num[c_e]){
			sum_e++;
		}
	}

	printf("%d\n",sum_e<sum_s?sum_e:sum_s);


	free(num);
	return 0;
}
