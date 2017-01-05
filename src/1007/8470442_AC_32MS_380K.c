#include <stdio.h>


int o(char *s,int l){
	int n=0,i,j;
	for(i=0;i<l-1;i++){
		for(j=i;j<l-1;j++){
			if(s[i]>s[j+1]){
				n++;
			}
		}
	}

	return n;
}
int main(){

	int l,n,i,j;
	scanf("%d%d",&l,&n);

	int tempint;
	char* tempchar;

	//printf("l=%d,n=%d\n",l,n);
	char **s=(char**)malloc(sizeof(char*)*n);
	int *m=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++){

		s[i]=(char*)malloc(sizeof(char)*l+5);

		scanf("%s",s[i]);
		m[i]=o(s[i],l);
		//printf("%d\n",m[i]);
	}

	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(m[j]>m[j+1]){
				tempint=m[j];
				m[j]=m[j+1];
				m[j+1]=tempint;

				tempchar=s[j];
				s[j]=s[j+1];
				s[j+1]=tempchar;
			}




		}
	}
	for(i=0;i<n;i++) printf("%s\n",s[i]);


	return 0;
}
