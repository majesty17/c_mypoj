#include <stdio.h>
int A,X,Y;
int main(){
	scanf("%x,%d,%d",&A,&X,&Y);


	A&=~(1<<(X));
	A|=(1<<(Y));
	A|=(1<<(Y-1));
	A&=~(1<<(Y-2));
	printf("%x\n",A);





	return 0;
}
