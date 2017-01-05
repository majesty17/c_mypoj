#include <stdio.h>
#include <math.h>
#include <limits.h>
short sixteen[16][3];
short des[3];
double getDis(int i){
	int d1=des[0]-sixteen[i][0];
	int d2=des[1]-sixteen[i][1];
	int d3=des[2]-sixteen[i][2];
	int D=d1*d1+d2*d2+d3*d3;
	//printf("dis is %d\n",D);
	return sqrt((double)D);
}
void find(){
	double minDis=500.0,dis;
	int i,mini;
	for(i=0;i<16;i++){
		dis=getDis(i);
//		printf("dis[%d] is %f\n",i,dis);
		if(dis<minDis){
			minDis=dis;
			mini=i;
		}
	}

	printf("(%d,%d,%d) maps to (%d,%d,%d)\n",des[0],des[1],des[2],sixteen[mini][0],sixteen[mini][1],sixteen[mini][2]);


}


int main(){
	int i,j;
	for(i=0;i<16;i++){
		scanf("%d%d%d",&sixteen[i][0],&sixteen[i][1],&sixteen[i][2]);
	}

	while(1){
		scanf("%d%d%d",&des[0],&des[1],&des[2]);
		if(des[0]==-1 && des[1]==-1 && des[2]==-1){
			return -1;
		}
		find();

	}



	return 0;
}
