#include <stdio.h>

int N,M;
int num[101][101]={0,};
char visited[101]={0,};


int visit(){
	int ret=0,i;
	for(i=1;i<=N;i++){
		ret+=visited[i] ;
	}
	return ret;
}
void dfs1(int in){
	visited[in]=1;
	int i;
	for(i=1;i<=N;i++){
		if(num[i][in]==1 && visited[i]==0) dfs1(i);
	}
}
void dfs2(int in){
	visited[in]=1;
	int i;
	for(i=1;i<=N;i++){
		if(num[in][i]==1 && visited[i]==0) dfs2(i);
	}
}

int main(){
	int i,tem1,tem2,count=0;
	scanf("%d %d",&N,&M);
	for(i=0;i<M;i++){
		scanf("%d %d",&tem1,&tem2);
		num[tem1][tem2]=1;
	}
	for(i=1;i<=N;i++){
		memset(visited,0,101);

		dfs1(i);
		dfs2(i);
		if(visit()==N) count++;
	}
	printf("%d\n",count);


	return 0;
}
