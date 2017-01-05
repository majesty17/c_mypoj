#include <stdio.h>
#include <string.h>
#include <stdlib.h>
///it's not ok!!!!
///TLE
char a[51];

int cmp(const void *a,const void *b){
	return *(char*)b - *(char*)a;
}
int cmp2(const void *a,const void *b){
	return *(char*)a - *(char*)b;
}
void handle(){
	char b[51];
	int len=strlen(a);
	strcpy(b,a);
	qsort(b,len,sizeof(char),cmp);
//	printf("b is %s\n",b);
	if(strcmp(b,a)==0){
		printf("No Successor\n");
		return;
	}
	int i,j;
	for(i=len-1;i>0;i--){
		for(j=i-1;j>=0;j--){
			if(a[i]>a[j]){
				goto Here;
			}
		}
	}
Here:
	a[i]=a[i]^a[j];
	a[j]=a[i]^a[j];
	a[i]=a[i]^a[j];
	qsort(a+j+1,len-j-1,1,cmp2);
	printf("%s\n",a);
}


int main(){

	while(1){
		scanf("%s",&a);
		if(strcmp(a,"#")==0){
			break;
		}

		handle();






	}


}
