#include <stdio.h>
#include <string.h>
char num[5];
char buf[5];
int num1,num2,rus;
int cmp(const char *a,const char *b){
	return *b-*a;
}
int main(){
	int i;
	while(1){
		scanf("%s",&num);
		if(num[0]=='-') break;
		i=0;
		printf("N=%s:\n",num);
		if(strlen(num)!=4){
			printf("No!!\n");
			continue;
		}
		while(1){

			qsort(num,strlen(num),1,cmp);
			strcpy(buf,num);
			strrev(buf);
			num1=atoi(num);
			num2=atoi(buf);
			rus=num1-num2;
			if(i==0 && rus==0){
				printf("No!!\n");
				break;
			}

			printf("%d-%d=%d\n",num1,num2,rus);
			if(rus==0 || rus==6174){
				printf("Ok!! %d times\n",++i);
				break;
			}
			itoa(rus,num,10);
			i++;
		}



	}
	return 0;
}
