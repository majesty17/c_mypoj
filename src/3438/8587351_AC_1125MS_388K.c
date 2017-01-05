#include <stdio.h>
int n;
char num[1001];
int main(){
	int i,j,len;
	char *p,*q;
	scanf("%d",&n);
	while(n--){
		scanf("%s",&num);
		len=strlen(num);
		p=num;
		q=num;
		while(*p!='\0'){


			while(*q==*p){

				q++;
			}
			printf("%d%c",q-p,*p);
			p=q;

		}
		printf("\n");


	}
	return 0;
}
