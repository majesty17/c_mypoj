#include <stdio.h>
int n;
int hh,mm;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d:%d",&hh,&mm);
		if(mm!=0){
			printf("0\n");
			continue;
		}
		else{
			if(hh==0) printf("12\n");
			else if(hh>=1 && hh<=12) printf("%d\n",hh+12);
			else printf("%d\n",hh-12);
		}


	}
	return 0;
}
