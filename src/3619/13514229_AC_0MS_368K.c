#include <stdio.h>
int n,k;
int str[1010][3];

int main(){
	scanf("%d %d",&n,&k);
	int i;
	for(i=0;i<k;i++){
		scanf("%d %d %d",&str[i][0],&str[i][1],&str[i][2]);
	}


	for(i=0;i<k;i++){


		int read_min=n/str[i][0];
		if(n%str[i][0]!=0)
			read_min++;
		int rest=(read_min-1)/str[i][1];
		printf("%d\n",read_min+str[i][2]*rest);

	}
	return 0;
}
