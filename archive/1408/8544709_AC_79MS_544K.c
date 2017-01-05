#include <stdio.h>
#include <math.h>

typedef struct{
	double x;
	double y;
}point,*ppoint;
int n;
float a[4][35];
point points[35][35]={0,};
double getArea(int x,int y){
	double area=0.0;
	double A1=hypot((points[x][y].x-points[x][y+1].x),(points[x][y].y-points[x][y+1].y));
	double B1=hypot((points[x][y].x-points[x+1][y].x),(points[x][y].y-points[x+1][y].y));
	double C1=hypot((points[x+1][y].x-points[x][y+1].x),(points[x+1][y].y-points[x][y+1].y));
	double P1=(A1+B1+C1)/2.0;
	area+=sqrt(P1*(P1-A1)*(P1-B1)*(P1-C1));

	double A2=hypot((points[x+1][y+1].x-points[x][y+1].x),(points[x+1][y+1].y-points[x][y+1].y));
	double B2=hypot((points[x+1][y+1].x-points[x+1][y].x),(points[x+1][y+1].y-points[x+1][y].y));
	double C2=C1;
	double P2=(A2+B2+C2)/2.0;
	area+=sqrt(P2*(P2-A2)*(P2-B2)*(P2-C2));

	return area;
}
void getCross(ppoint pp,point A,point B,point C,point D){

	pp->x+=A.x;
	pp->y+=A.y;

	 double t=((A.x-C.x)*(C.y-D.y)-(A.y-C.y)*(C.x-D.x))
  /((A.x-B.x)*(C.y-D.y)-(A.y-B.y)*(C.x-D.x));
 	pp->x+=(B.x-A.x)*t;
 	pp->y+=(B.y-A.y)*t;
}
void makePoints(){
	int i,j;
	points[0][0].x=0.0;
	points[0][0].y=0.0;

	points[0][n+1].x=0.0;
	points[0][n+1].y=1.0;

	points[n+1][0].x=1.0;
	points[n+1][0].y=0.0;

	points[n+1][n+1].x=1.0;
	points[n+1][n+1].y=1.0;

	for(i=1;i<n+1;i++){
		points[0][i].x=0.0;
		points[0][i].y=a[2][i-1];

		points[n+1][i].x=1.0;
		points[n+1][i].y=a[3][i-1];

		points[i][0].x=a[0][i-1];
		points[i][0].y=0.0;

		points[i][n+1].x=a[1][i-1];
		points[i][n+1].y=1.0;

	}

	for(i=1;i<n+1;i++){
		for(j=1;j<n+1;j++){
			getCross(&points[i][j],points[i][0],points[i][n+1],points[0][j],points[n+1][j]);
		}
	}


//
//	for(i=0;i<n+2;i++){
//		for(j=0;j<n+2;j++){
//			printf("(%.7f %.7f),",points[i][j].x,points[i][j].y);
//		}
//		printf("\n");
//	}

}
void handle(){
	int i,j;
	double max=0.0,tem;
	for(i=0;i<n+1;i++){
		for(j=0;j<n+1;j++){
			tem=getArea(i,j);
			max=max>tem?max:tem;
		}
	}

	printf("%.6f\n",max);

}
int main(){
	int i,j;
	while(1){
		scanf("%d",&n);
		if(!n) break;
		for(i=0;i<4;i++){
			for(j=0;j<n;j++){
				scanf("%f",&a[i][j]);
			}
		}
		memset(points,0,35*35*sizeof(point));
//
//		for(i=0;i<4;i++){
//			for(j=0;j<n;j++){
//				printf("%.7f,",a[i][j]);
//			}
//			printf("\n");
//		}


		makePoints();
		handle();
	}
	return 0;
}
