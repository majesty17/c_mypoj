#include <stdio.h>
#define AM 1
#define PM 2

int T;
char line[20];
int main(){
	int i,aorp;
	scanf("%d",&T);
	while(T--){
		scanf("%s",&line);
		for(i=5;i<=9;i++){
			printf("%c",line[i]);
		}
		printf("/");
		for(i=0;i<=3;i++){
			printf("%c",line[i]);
		}
		printf("-");

		int hh=(line[11]-'0')*10+(line[12]-'0');
//		printf("hh is %d\n",hh);
		if(hh<12){
			if(hh==0) printf("12");
			else if(hh<10) printf("0%d",hh);
			else printf("%d",hh);
			aorp=AM;
		}else{
			if(hh>12) hh-=12;
			if(hh<10) printf("0%d",hh);
			else printf("%d",hh);
			aorp=PM;
		}


		printf(":%s",&line[14]);
		if(aorp==AM) printf("am");
		else printf("pm");
		printf("\n");
	}
	return 0;
}
