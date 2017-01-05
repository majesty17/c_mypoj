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



	if(stars==0)
		return 0;
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

//下面是不可能的情况：
	//有洞
	if(ret==-1){
		printf("%s",map[2]);
		return 0;
	}

	//有星星数，但是不等于S
	if(ret>0 && ret!=s){
		printf("%s",map[2]);
		return 0;
	}
	//没星星，但是k决定了这行必须得有，则不符合
	if(ret==0 && s>m/2 && (k>=m-s && k<=s)){
		printf("%s",map[2]);
		return 0;
	}
//唯一确定的情况
	//如果把m填满 可以唯一
	if(ret>0 && s==ret && s==m){
		printf("%s",map[0]);
		return 0;
	}
	//如果都等于1，可以唯一
	if(ret==1 && s==1){
		printf("%s",map[0]);
		return 0;
	}
	//如果ret有数，并等于s；并且k在顶上或者下边，可以唯一
	if(ret>0 && ret==s && (k==1 || k==m)){
		printf("%s",map[0]);
		return 0;
	}

	//如果ret==0，则必须卡死
	if(ret==0 && ( k==s+1 || k==s-1 ) && s>m/2){
		printf("%s",map[0]);
		return 0;
	}




//剩余的是多解的情况
	printf("%s",map[1]);




	free(buff);
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
