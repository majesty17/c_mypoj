#include <stdio.h>
int n;
int a1,a2,a3,a4;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
		if(a2-a1==a3-a2 && a3-a2==a4-a3){
			printf("%d %d %d %d %d\n",a1,a2,a3,a4,a4+(a4-a3));
		}
		else{
			printf("%d %d %d %d %d\n",a1,a2,a3,a4,a4*(a4/a3));
		}




	}
	return 0;
}
