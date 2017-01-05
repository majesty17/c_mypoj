#include <stdio.h>
#include <string.h>
int n,k;
char num[19][201][20]={0,};

void sum(char *n1,char *n2){
	int len1=strlen(n1);
	int len2=strlen(n2);
	int len=len1>len2?len1:len2;
	int i,c=0,tmp;
	for(i=0;i<len;i++){
		if(n1[i]=='\0' && n2[i]=='\0') break;
		tmp=c;
		if(n1[i]!='\0') tmp+=n1[i]-'0';
		if(n2[i]!='\0') tmp+=n2[i]-'0';
		n1[i]=tmp%10+'0';
		c=tmp/10;
	}
	if(c!=0)n1[len]='1';
}

void handle(){
	int i,j,k;
	strcpy(num[1][0],"1");
	strcpy(num[2][0],"1");
	strcpy(num[2][1],"1");
	for(i=3;i<=18;i++){
		for(j=0;j<=(i-1)*i/2;j++){
			memset(num[i][j],0,20);
			for(k=j-i+1;k<=j;k++){
				if(k<0) continue;
				sum(num[i][j],num[i-1][k]);
			}
		}
	}

}

int main(){
	handle();
	while(1){
		scanf("%d%d",&n,&k);
		if(n==0 && k==0) break;
		if(strlen(num[n][k])==0)printf("0\n");
		else printf("%s\n",strrev(num[n][k]));
		strrev(num[n][k]);
	}
	return 0;
}
