#include <stdio.h>
#include <stdlib.h>

char *map[]={"Unique","Ambiguous","Impossible"};
int m,n,s,k;
char *buff;

// 0 means no s,-1 means has a hole,>0 means S;
int getS(){
	int i;
	int stars=0;
	int dot=0;

	for(i=0;i<n;i++){
		if(buff[i]=='*'){
			stars++;
		}
	}

	for(i=0;i<n;i++){
		if(buff[i]=='*')
			break;
		dot++;
	}
	for(i=n-1;i>=0;i--){
		if(buff[i]=='*')
			break;
		dot++;
	}

	if(dot+stars!=n)
		return -1;
	return stars;

}

int main(){

	scanf("%d %d %d %d",&m,&n,&s,&k);
	buff=(char*)malloc(sizeof(char)*n);
	scanf("%s",buff);

	//printf("num is %d %d %d %d,buff is %s\n",m,n,s,k,buff);
	//printf("getS() is %d\n",getS());



	int ret=getS();

	free(buff);



	if(ret>0){
		if(k==1 || k==m || m==s || s==1){
			printf("%s",map[0]);
			return 0;
		}
		printf("%s",map[1]);
		return 0;
	}

	if(ret==0){
		if(k-1<s && m-k<s){
			printf("%s",map[2]);
			return 0;
		}
		if(n>s){
			printf("%s",map[1]);
			return 0;
		}
		if(   (k-1==s&&m-k<s)||(k-1<s&&m-k==s)       ){
			printf("%s",map[0]);
			return 0;
		}
		printf("%s",map[1]);
		return 0;
	}

	printf("%s",map[2]);
	return 0;
}



/*

s=3
  1 2 3 . . . n
1 . . . . . . .
2 . * * * . . .
3 . * * * . . .
. . * * * . . .
. . . . . . . .
. . . . . . . .
m . . . . . . .

*/
