#include <stdio.h>
#include <string.h>

char s[3],d[3];
int getAbs(char a,char b){
	return a>b?(a-b):(b-a);
}
void Process(){
	int x=getAbs(s[0],d[0]);
	int y=getAbs(s[1],d[1]);

	if(x==0 && y==0) {
		printf("0 0 0 0\n");
		return ;
	}

	//step1:king
	printf("%d ",x>y?x:y);


	//step2:queen
	if(x==y || x*y==0){
		printf("1 ");
	}else{
		printf("2 ");
	}


	//step3:car
	if(x*y==0){
		printf("1 ");
	}else{
		printf("2 ");
	}



	//step4:elephent
	if(x==y){
		printf("1\n");
	}else if((x+y)%2==0){
		printf("2\n");

	}else {
		printf("Inf\n");
	}




	return ;
}
int main(){
	int n;
	scanf("%d",&n);
	if(n<1 || n>20) return -1;
	int i;
	for(i=0;i<n;i++){
		memset(s,0,3);
		memset(d,0,3);
		scanf("%s %s",s,d);
		//printf("%s %s\n",s,d);
		Process();


	}

	return 0;
}
