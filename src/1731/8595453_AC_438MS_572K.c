#include <stdio.h>
#include <stdlib.h>

char a[1024];
char b[1024];
int len;
int cmp(const void *a,const void *b){
	return *(char*)a-*(char*)b;
}

void next(){
	int i,j,k;
	for(i=2;i<=len;i++){
		for(j=len-1;j>=len-i+1;j--){
			if(a[len-i]<a[j]){
				a[len-i]=a[len-i]^a[j];
				a[j]=a[len-i]^a[j];
				a[len-i]=a[len-i]^a[j];
				qsort(&a[len-i+1],i-1,sizeof(a[0]),cmp);

				return;
			}
		}


	}



}
void handle(){
	qsort(a,len,1,cmp);
	strcpy(b,a);
	strrev(b);
	printf("%s\n",a);
	while(1){

		if(strcmp(a,b)==0) break;
		next();
		printf("%s\n",a);
	}
}
int main(){

	scanf("%s",&a);
	len=strlen(a);
	handle();
	return 0;
}
