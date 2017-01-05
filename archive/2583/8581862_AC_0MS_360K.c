#include <stdio.h>
int f0,f1,f2;
int main(){
	while(scanf("%d %d %d",&f0,&f1,&f2)!=EOF){

		if(f2-f1==f1-f0){
			printf("%d %d %d\n",f2+(f1-f0),f2+2*(f1-f0),f2+3*(f1-f0));
			continue;
		}
//		int A,B,C=f0;
//		A=(f2-2*f1)/2;
//		B=(4*f1-f2)/2;
//		printf("%d %d %d\n",A*9+B*3+C,A*16+B*4+C,A*25+B*5+C);
		printf("%d %d %d\n",f0-3*f1+3*f2,3*f0-8*f1+6*f2,6*f0-15*f1+10*f2);
	}
	return 0;
}
