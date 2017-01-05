#include <stdio.h>

char a(char b){
	if(b>='0' && b<='9') return b;
	if(b<'Q') return (b-5)/3+30;
	else return b/3+28;
}
int compstr(char *a,char *b){
	int la=strlen(a);
	int lb=strlen(b);
	int i;
	for(i=0;i<la;i++){
		if(a[i]==b[i]) continue;
		else if(a[i]>b[i]) return 1;
		else  return -1;
	}

	return 0;
}
void trim(char* b){
	char *c=(char*)malloc(9);
	memset(c,0,9);
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
		trim(a[i]);
	}
	char* temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(compstr(a[j],a[j+1])>0){
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
			if(compstr(a[i],a[j])==0){
				m++;
				b[j]=1;
			}
		}
		if(m>1){
			printf("%s %d\n",a[i],m);
		}

	}
	return 0;
}
