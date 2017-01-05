#include <stdio.h>
int n;
char a[9],b[9];
int main(){
	int i,A,B;
	scanf("%d",&n);
	while(n--){
		A=0,B=0;
		scanf("%s %s",&a,&b);
		for(i=0;i<4;i++){
			if (a[i]==b[i]){
				A++;
			}
		}
		printf("%dA",A);

		for(i=0;i<4;i++){
			char *pos=strchr(b,a[i]);
			if(pos!=NULL){
				B++;
				a[i]='*';
			}
		}

		printf("%dB\n",B-A);
	}
	return 0;
}
