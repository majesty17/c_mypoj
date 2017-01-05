#include <stdio.h>
int n;
int getones(int num){
	int count=0;
	int m=num;
	while(m){
		m=m&(m-1);
		count++;
	}
	return count;
}
int handle(int num){
	int i;
	int ones=getones(num);
	for(i=num+1;;i++){
		if(getones(i)==ones){
			return i;
		}
	}
	return -1;
}
int main(){
	while(1){
		scanf("%d",&n);
		if(!n)break;
		printf("%d\n",handle(n));
	}
	return 0;
}
