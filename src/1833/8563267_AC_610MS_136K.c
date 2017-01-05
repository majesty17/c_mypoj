#include <stdio.h>
#include <stdlib.h>

int m,n,k;
int a[1024];
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

void next(){
	int i,j,k;
	for(i=2;i<=n;i++){
		for(j=n-1;j>=n-i+1;j--){
			if(a[n-i]<a[j]){
				a[n-i]=a[n-i]^a[j];
				a[j]=a[n-i]^a[j];
				a[n-i]=a[n-i]^a[j];
				qsort(&a[n-i+1],i-1,sizeof(a[0]),cmp);

				return;
			}
		}


	}
	qsort(a,n,sizeof(a[0]),cmp);


}
void handle(){
	int i=k;
	while(i--){
		next();
	}

	for(i=0;i<n;i++){
		printf("%d",a[i]);
		if(i<n-1) printf(" ");
	}
	printf("\n");

}
int main(){
	int i;
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&n,&k);

		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		handle();



	}
	return 0;
}
