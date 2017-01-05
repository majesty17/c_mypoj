#include <stdio.h>
#include <string.h>

int n;
char str[80];
char buf[80]={0,};
int num[80]={0,};


int main(){
	int len,i;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		scanf("%s",&str);
		len=strlen(str);
		memset(buf,0,80);
		memset(num,0,80*4);
		int customerWalkout=0;

		for(i=0;i<len;i++){

			if(strchr(buf,str[i])==0){
				num[i+1]=num[i]+1;
				if(num[i+1]>n) customerWalkout++;
			}
			else{
				num[i+1]=num[i]-1;
			}

			buf[i]=str[i];
		}

//		for(i=0;i<len+1;i++) printf("%d,",num[i]);

//		printf("\nbuff is %s\n",buf);
		if(customerWalkout==0) printf("All customers tanned successfully.\n");
		else printf("%d customer(s) walked away.\n",customerWalkout);




	}






	return 0;
}
