#include <stdio.h>
char str1[6],str2[5];
int n;
int low,high;
int lie;
int main(){
	while(1){
		low=1;high=10;
		lie=0;
		while(1){
			scanf("%d",&n);
			if(n==0)return -1;
			scanf("%s %s",&str1,&str2);
			if(strcmp(str1,"right")==0 && strcmp(str2,"on")==0){
				if(n<low || n>high || low>high) lie=1;
				if(lie==1){
					printf("Stan is dishonest\n");
				}
				else{
					printf("Stan may be honest\n");
				}
				break;
			}
			if(strcmp(str1,"too")==0){
				if(strcmp(str2,"high")==0){
					if(n<=low){
						lie=1;
					}
					else{
						if(n<=high)high=n-1;
					}
				}
				else if(strcmp(str2,"low")==0){
					if(n>=high){
						lie=1;
					}
					else{
						if(n>=low)low=n+1;
					}
				}
			}
//			printf("low is %d,high is %d\n",low,high);
		}
	}
	return 0;
}
