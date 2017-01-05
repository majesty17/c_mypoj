#include <stdio.h>

int n;
int num;

int power5(int a){
	int ret=1;
	while(a--) ret*=5;
	return ret;
}
void handle(int a){
	int i5=0,i;
	for(i=1;power5(i)<=a;i++){
		i5+=a/power5(i);
	}
	printf("%d\n",i5);
}

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&num);
		handle(num);
	}
	return 0;
}
