#include <stdio.h>
#include <string.h>



char a[100]={0,};
char steps[16][100]={0,};
void getInven(char *s,char *des){
	des[0]='\0';
	int len=strlen(s);

	char tem[5];
	short num[10]={0,};
	int i;
	for(i=0;i<len;i++){
		num[s[i]-'0']++;
	}
	for(i=0;i<10;i++){
		if(num[i]!=0){
			itoa(num[i],tem,10);
			strcat(des,tem);
			des[strlen(des)]=i+'0';
		}
	}
}
int isSelf(char *str){
	int len=strlen(str);
	char s[30]={0,};
	char tem[5];
	short num[10]={0,};
	int i;
	for(i=0;i<len;i++){
		num[str[i]-'0']++;
	}
	for(i=0;i<10;i++){
		if(num[i]!=0){
			itoa(num[i],tem,10);
			strcat(s,tem);
			s[strlen(s)]=i+'0';
		}
	}


	return strcmp(s,str);
}
void handle(){
	//step1:is a is a self-in
	if(isSelf(a)==0){
		printf("%s is self-inventorying \n",a);
		return;
	}

	//step2:make 15 steps
	getInven(a,steps[0]);
	int i,j;
	for(i=0;i<15;i++){
		getInven(steps[i],steps[i+1]);
//		printf("steps %d :%s\n",i+1,steps[i]);
		if(isSelf(steps[i])==0){
			printf("%s is self-inventorying after %d steps \n",a,i+1);
			return;
		}
	}
	for(i=0;i<15;i++){

		if(strcmp(steps[i],a)==0){
			printf("%s enters an inventory loop of length %d \n",a,i+1);
			return;
		}
	}
	for(i=0;i<15-1;i++){
		for(j=i+1;j<15;j++){
			if(strcmp(steps[i],steps[j])==0){
				printf("%s enters an inventory loop of length %d \n",a,i>j?(i-j):(j-i));
				return;
			}
		}
	}
	printf("%s can not be classified after 15 iterations \n",a);


}
int main(){
//	printf("%d\n",isSelf("31123314"));
//	return 0;

	while(1){
		memset(a,0,100);
		scanf("%s",a);
		if(strcmp(a,"-1")==0){
			return -1;
		}



		handle();
		int i;
		for(i=0;i<15;i++){
			memset(steps[i],0,100);
		}
	}




	return 0;
}
