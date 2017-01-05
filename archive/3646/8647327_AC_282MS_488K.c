#include <stdio.h>
int n,m;		//n heads,m knights
int dra[20001];
int kni[20001];
int cmpj(int *a,int *b){	//降序
	return *b-*a;
}
int cmps(int *a,int *b){	//升序
	return *a-*b;
}
int main(){
	int i,j;
	while(1){
		scanf("%d %d",&n,&m);
		if(m==0 && n==0)break;

		for(i=0;i<n;i++){
			scanf("%d",&dra[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d",&kni[i]);
		}
		if(m<n){
			printf("Loowater is doomed!\n");
			continue;
		}
		qsort(dra,n,sizeof(int),cmpj);
		qsort(kni,m,sizeof(int),cmps);
		int min=0;
		int res=n;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if(kni[j]==-1)continue;
				if(dra[i]<=kni[j]){
					min+=kni[j];
					kni[j]=-1;
					res--;
					break;
				}
			}
		}

		if(res!=0){
			printf("Loowater is doomed!\n");
			continue;
		}

		printf("%d\n",min);
	}
	return 0;
}
