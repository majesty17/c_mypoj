#include <stdio.h>




int main(){
	int m,n;

	while(scanf("%d %d",&m,&n)!=EOF){
		//printf("%d\n",m%n);
		if(m<n) printf("%d\n",m);
		else{
			while(m>=n){
				m-=n;
			}
			printf("%d\n",m);
		}
	}

	return 0;
}
