#include <stdio.h>
#include <math.h>
float x[6],y[6];
int getValue(float a,float b){
	float dis=hypot(a,b);
	if(dis<=3.0)return 100;
	if(dis<=6.0)return 80;
	if(dis<=9.0)return 60;
	if(dis<=12.0)return 40;
	if(dis<=15.0)return 20;
	return 0;
}
void getPoints(int *p1,int *p2){
	int _p1=0,_p2=0;
	_p1+=getValue(x[0],y[0]);
	_p1+=getValue(x[1],y[1]);
	_p1+=getValue(x[2],y[2]);
	_p2+=getValue(x[3],y[3]);
	_p2+=getValue(x[4],y[4]);
	_p2+=getValue(x[5],y[5]);

	*p1=_p1;
	*p2=_p2;
}
int main(){
	int i;
	int po1=0,po2=0;
	while(1){
		for(i=0;i<6;i++){
			scanf("%f %f",&x[i],&y[i]);
		}
		if(x[0]+100<0.00000001)break;
		getPoints(&po1,&po2);
		printf("SCORE: %d to %d, ",po1,po2);
		if(po1==po2) printf("TIE.\n");
		else if(po1>po2) printf("PLAYER 1 WINS.\n");
		else printf("PLAYER 2 WINS.\n");
	}
	return 0;
}
