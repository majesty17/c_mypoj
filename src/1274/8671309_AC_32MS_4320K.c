#include <stdio.h>
#include <string.h>
int n,m,c;
int adj[1001][1001]={0,};
char used[1001];
int mat[1001];
int search(int k){
	int i;
	for(i=1;i<=adj[k][0];i++){
		int j=adj[k][i];
		if(used[j]==0){
			used[j]=1;
			if(mat[j]==0||search(mat[j])==1){
				mat[j]=k;
				return 1;
			}
		}
	}
	return 0;
}
int hungary(){
	int ret=0,i;
	for(i=1;i<=n;i++){
		memset(used,0,1001);

		ret+=search(i);
	}
	return ret;
}
int main(){
	int i,j;
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(adj,0,4008004);
		memset(mat,0,4004);
		for(i=1;i<=n;i++){
			scanf("%d",&adj[i][0]);
			for(j=1;j<=adj[i][0];j++){
				scanf("%d",&adj[i][j]);
			}
		}

//		for(i=0;i<n;i++){
//			for(j=0;j<=adj[i][0];j++){
//				printf("%d,",adj[i][j]);
//			}
//			printf("\n");
//		}

		printf("%d\n",hungary());
	}
	return 0;
}
