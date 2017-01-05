#include <stdio.h>
int l,n;
char irregular[2][20][50]={0,};
char buff[50];
int aeiou(char a){
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return 1;
	else return 0;
}
void handle(){
	int i,j;
	for(i=0;i<l;i++){
		if(strcmp(buff,irregular[0][i])==0){
			printf("%s\n",irregular[1][i]);
			return ;
		}
	}

	int len=strlen(buff);
	if(buff[len-1]=='y' && aeiou(buff[len-2])==0){
		buff[len-1]='\0';
		strcat(buff,"ies");
		printf("%s\n",buff);
		return ;
	}
	else if(  (buff[len-1]=='o')||(buff[len-1]=='s')||(buff[len-1]=='x')||(buff[len-1]=='h'&&buff[len-2]=='c')||(buff[len-1]=='h'&&buff[len-2]=='s')        ){
		printf("%ses\n",buff);
		return;
	}
	else{
		printf("%ss\n",buff);
	}




}
int main(){
	int i,j;
	scanf("%d %d",&l,&n);
	for(i=0;i<l;i++){
		scanf("%s %s",&irregular[0][i],&irregular[1][i]);
	}

	for(i=0;i<n;i++){
		scanf("%s",&buff);
		handle();
	}



	return 0;
}
