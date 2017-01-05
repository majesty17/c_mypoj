#include <stdio.h>
int n;
char a[10],b[10];
char buffer[12];
int main(){
	int sum,i,len;
	scanf("%d",&n);
	while(n--){
		sum=0;
		scanf("%s %s",&a,&b);
		strrev(a);
		strrev(b);
		sum+=atoi(a);
		sum+=atoi(b);
		itoa(sum,buffer,10);
		strrev(buffer);
		len=strlen(buffer);
		int sign=1;
		for(i=0;i<len;i++){
			if(buffer[i]=='0' && sign==1) continue;
			printf("%c",buffer[i]);
			sign=0;
		}
		printf("\n");
	}
	return 0;
}
