#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a(char b){
	if(b>='0' && b<='9') return b;
	if(b<'Q') return (b-2)/3+29;
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
char* trim(char* b){
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


	free(b);
	return c;
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
		a[i]=trim(a[i]);

	}




	char **z=(char**)malloc(sizeof(char*)*100);
	memset(z,0,sizeof(char*)*100);
	//char buff[20];
	for(i=0;i<n-1;i++){
		int m=1;
		for(j=i+1;j<n;j++){
			if(b[j]==1)
				continue;
			if(compstr(a[i],a[j])==0){
				m++;
				b[j]=1;
			}
		}
		if(m>1){
			int c=(a[i][0]-48)*10+(a[i][1]-48);
			z[c]=(char*)malloc(15);
			sprintf(z[c],"%s %d",a[i],m);

		}

	}

	for(i=0;i<n;i++) free(a[i]);
	for(i=0;i<100;i++){
		if(z[i]!=NULL){
			printf("%s\n",z[i]);
			free(z[i]);
		}

	}
	free(z);
	free(a);

	return 0;
}
