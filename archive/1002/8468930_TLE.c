#include <stdio.h>

char a(char b){
	if(b>='0' && b<='9') return b;
	if(b<'Q') return (b-65)/3+50;
	else return (b-66)/3+50;
}
char* trim(char* b){
	char c[9]={0,};
	int n=strlen(b),i,k=0;

	for(i=0;i<n;i++){
		if(b[i]=='-')
			continue;
		else{
			if(k==3) {
				c[k]='-';
				k++;
			}
			c[k]=a(b[i]);
			k++;
		}
	}

	strcpy(b,c);
//	for(i=7;i>=4;i--){
//		b[i]=b[i-1];
//	}
//
//	b[3]='-';
//	b[8]=0;
	return b;
}


int main(){

	int n,i,j;
	scanf("%d",&n);
	char **a=(char**)malloc(n*sizeof(char*));
	int *b=(int*)malloc(n*sizeof(int));
	memset(b,0,n*sizeof(int));

	for(i=0;i<n;i++){
		a[i]=(char*)malloc(20);
		scanf("%s",a[i]);
	}

	for(i=0;i<n;i++){
		a[i]=trim(a[i]);
	}
	char* temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(strcmp(a[j],a[j+1])>0){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}

		}
	}
	//for(i=0;i<n;i++) printf("%s\n",a[i]);

	for(i=0;i<n-1;i++){
		int m=1;
		for(j=i+1;j<n;j++){
			if(b[j]==1)
				break;
			if(strcmp(a[i],a[j])==0){
				m++;
				b[j]=1;
			}
		}
		if(m>1){
			printf("%s\t%d\n",a[i],m);
		}

	}
	return 0;
}
