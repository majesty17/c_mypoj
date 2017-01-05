#include <stdio.h>
#define PI acos(-1)
char buff[11];
int x,y,z;
int main(){
	while(1){
		scanf("%s",&buff);
		if(buff[0]=='E')break;
		scanf("%d %d %d",&x,&y,&z);
		if(z>=180) z=360-z;
		double dis=x*z*PI*2/180.0;
		double alldis=y*5.0;

		if(alldis>=dis){
			printf("YES %d\n",(int)(alldis-dis)/5);
		}
		else{
			printf("NO %d\n",(int)alldis);
		}
		scanf("%s",&buff);
	}
	return 0;
}
