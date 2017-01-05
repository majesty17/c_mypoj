#include <stdio.h>
char n[100];

int getRoot(int num){
	if(num<10) return num;
	int i,sum=0;
	for(i=1;i<=1000000000;i*=10){
		sum+=num/i%10;
	}
	return getRoot(sum);
}

int getR(){
	int sum=0;
	int len=strlen(n),i;
	for(i=0;i<len;i++){
		sum+=n[i]-'0';
	}


	return getRoot(sum);
}


int main(){
	while(1){
		scanf("%s",&n);
		if(strcmp(n,"0")==0) break;
		printf("%d\n",getR());
		//printf("%d\n",n%9==0?9:n%9);
	}
	return 0;
}
