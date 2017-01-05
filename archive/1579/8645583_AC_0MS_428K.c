#include <stdio.h>
int num[21][21][21]={0,0,0};
int w(int x,int y,int z){
	if(x<=0 || y<=0 || z<=0)return 1;
	if(x>20 || y>20 || z>20)return w(20,20,20);
	if(num[x][y][z]!=0)return num[x][y][z];
	else {
		num[x][y][z]=w(x-1,y,z)+w(x-1,y-1,z)+w(x-1,y,z-1)-w(x-1,y-1,z-1);\
		return num[x][y][z];
	}

}
int main(){
	int a,b,c;
	while(1){
		scanf("%d %d %d",&a,&b,&c);
		if(a==-1 && b==-1 &&c==-1) break;
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}

	return 0;
}
