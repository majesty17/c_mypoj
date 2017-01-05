#include <stdio.h>
#include <string.h>

char str[100];
void getStr(int *a,int len){
	int i,j;
	char *p=(char*)str;
	for(i=0;i<a[0];i++){
		*p='(';
		p++;
	}
	*p=')';
	p++;
	for(i=1;i<len;i++){
		for(j=0;j<a[i]-a[i-1];j++){
			*p='(';
			p++;
		}
		*p=')';
		p++;
	}
}
void handle(){
	int len=strlen(str);
	int i;
	for(i=0;i<len;i++){				//扫描括号串，处理每一个“)”
		if(str[i]=='('){
			continue;
		}
		else{
			int n=i-1;
			int count=0,m=-1;
			for(;n>=0;n--){			//向左找到该“)”匹配的“(”
				if(str[n]==')'){
					m--;
				}
				else{
					count++;
					m++;
				}
				if(m==0){
					break;
				}
			}
			printf("%d",count);
		}
		if(i<len-1) printf(" ");
	}
	printf("\n");

}
int main(){

	int n,m,i;


	scanf("%d",&n);
	if(n<1 || n>10) return -1;

	while(n--){
		scanf("%d",&m);
		int s[m];

		for(i=0;i<m;i++){
			scanf("%d",&s[i]);
		}
		memset(str,0,100);
		getStr(s,m);

		handle();
//		printf("%s\n",str);

	}


	return 0;
}
