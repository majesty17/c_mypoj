#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cmp(void *a,void *b ){
	return *(char*)a - *(char*)b;
}
//str*dig
char *multi(char *des,char *str,char dig){
	int c=0;
	int i;
	int temp;
	int buff[10]={0,};
	for(i=0;i<strlen(str);i++){
		temp=(str[i]-'0')*dig+c;
		des[i]=temp%10+'0';
		c=temp/10;
	}
	if(c!=0){
		itoa(c,buff,10);
		strcat(des,buff);
	}

	return des;

}
//if ok return 1
//if not return 0
int compare(char *s1,char *s2){
	//printf("====%s\n====%s\n",s1,s2);

	if(strlen(s1)!=strlen(s2)){
		return 0;
	}
	int len=strlen(s1);
	char str1[80],str2[80];
	strcpy(str1,s1);
	strcpy(str2,s2);

	qsort((void*)str1,len,1,cmp);
	qsort((void*)str2,len,1,cmp);
//	printf("====%s\n====%s\n",str1,str2);
	if(strcmp(str1,str2)==0){
		return 1;
	}
	else{
		return 0;
	}

}
int main(){
	char *buf=(char*)malloc(sizeof(char)*80);		//fetch input
	char *des=(char*)malloc(sizeof(char)*80);		//store the multi

	int round;
	while(scanf("%s",buf)!=EOF){


		strrev(buf);
		int i;
		round=1;
		for(i=1;i<=strlen(buf);i++){
			memset(des,0,80);
			des=multi(des,buf,i);
//			printf("%s\n",strrev(des));
			round=round & compare(des,buf);
		}
		strrev(buf);
		if(round==1){
			printf("%s is cyclic\n",buf);
		}else{
			printf("%s is not cyclic\n",buf);
		}


	}


	return 0;
}
