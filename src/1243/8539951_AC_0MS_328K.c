#include <stdio.h>
int inta[31][31];
int G,L;
int sum;

int main(){

	int i , j ;
	int now = 1 ;
	memset(inta , 0 ,sizeof(inta) ) ;
	for( i =0 ; i < 31 ; i ++ )
		inta[i][0] = i ;
	for( i = 1 ; i < 31 ; i++ ){
		for( j = 1 ; j <= i ; j++ )
			inta[i][j] = inta[i-1][j] + inta[i-1][j-1] + 1 ;
		for( ; j < 31 ; j++ )
			inta[i][j] = inta[i][i] ;
	}






	int count=0;
	while(1){
		scanf("%d%d",&G,&L);
		if(G==0 && L==0) break;

		printf("Case %d: %d\n",++count,inta[G][L]);
	}




	return 0;
}
