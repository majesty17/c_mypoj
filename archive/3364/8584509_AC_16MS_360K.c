#include <stdio.h>
int n,m,c;
int main(){
	while(1){
		scanf("%d %d %d",&n,&m,&c);
		if(n==0&&m==0&&c==0) break;
		if(c==1){
			n-=7;
			m-=7;
			if(n<=0 || m<=0) {printf("0\n");break;}
			if((m*n)%2==0){
				printf("%d\n",(m*n)/2);
			}
			else{
				printf("%d\n",(m*n+1)/2);
			}
		}
		else{
			n-=7;
			m-=7;
			if(n<=0 || m<=0) {printf("0\n");break;}
			if((m*n)%2==0){
				printf("%d\n",(m*n)/2);
			}
			else{
				printf("%d\n",((m*n-1)/2)<0?0:((m*n-1)/2));
			}
		}

	}
	return 0;
}
