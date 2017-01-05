#include <stdio.h>
#include <string.h>
char a[81];
int c;
int cmp(const void *a,const void *b){
	return *(char*)a-*(char*)b;
}
void next(){
	int i,j,k;
	int n=strlen(a);
	for(i=n-2;i>=0;i--){
		for(j=n-1;j>i;j--){
			if(a[i]<a[j]){
//				printf("i is %d,j is %d\n",i,j);
				a[i]=a[i]^a[j];
				a[j]=a[i]^a[j];
				a[i]=a[i]^a[j];
				qsort(&a[i+1],n-i-1,sizeof(a[0]),cmp);

				return;
			}
		}


	}
	//qsort(a,n,sizeof(a[0]),cmp);
	sprintf(a,"BIGGEST");
}
int main(){
	int order;
	scanf("%d",&c);
	while(c--){
		scanf("%d %s",&order,&a);

		next();
		printf("%d %s\n",order,a);
	}
	return 0;
}
