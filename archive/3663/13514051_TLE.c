#include <stdio.h>
int n,s;
int num[20010];
int main(){
	scanf("%d %d",&n,&s);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	int sum=0;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(num[i]+num[j]<=s)
				sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
