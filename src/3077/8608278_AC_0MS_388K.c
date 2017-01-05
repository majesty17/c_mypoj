#include <stdio.h>
int n;
char num[20];
int main(){
	int i,len;
	scanf("%d",&n);
	while(n--){
		scanf("%s",&num);
		len=strlen(num);
		int c=0;
		for(i=len-1;i>=0;i--){
			if(i==0 &&c==0) {
				break;
			}
			else if(i==0 && c==1){
				if(num[0]<'9'){
					num[0]++;
					c=0;
				}
				else{
					num[0]='0';
					c=1;
				}
				break;
			}


			char p=num[i]+c;
			if(p<'5') {
				num[i]='0';
				c=0;
			}
			else {//if(p>='5' && p<='9'){
				num[i]='0';
				c=1;
			}


		}

		if(c==1)printf("1");
		printf("%s\n",num);

	}
	return 0;
}
