#include <stdio.h>
int n;
int main(){
	scanf("%d",&n);
	int a;
	while(n--){
		scanf("%d",&a);
		printf("%d\n",(a/2)*((a-1)/2));
	}
	return 0;
}
