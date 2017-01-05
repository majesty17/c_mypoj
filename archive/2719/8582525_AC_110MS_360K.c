#include <stdio.h>
#include <string.h>
int map[]={0,1,2,3,4,4,5,6,7,8,9};
char num[15];
int mypow(int low,int up){
	int ret=1,i;
	for(i=0;i<up;i++) ret*=low;
	return ret;
}

int main(){
	while(1){
		scanf("%s",&num);
		if(strcmp(num,"0")==0) break;

		int len=strlen(num),i,sum=0;
		for(i=0;i<len;i++){
			sum+=mypow(9,len-i-1)*map[(num[i]-'0')];

		}



		printf("%s: %d\n",num,sum);


	}
	return 0;
}
