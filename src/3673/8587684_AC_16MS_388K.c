#include <stdio.h>
char a[15],b[15];
int main(){
	int i;
	scanf("%s %s",&a,&b);
	int len1=strlen(a);
	int len2=strlen(b);
	int sum1=0,sum2=0;

	for(i=0;i<len1;i++) sum1+=a[i]-'0';
	for(i=0;i<len2;i++) sum2+=b[i]-'0';




	printf("%d\n",sum1*sum2);
	return 0;
}
