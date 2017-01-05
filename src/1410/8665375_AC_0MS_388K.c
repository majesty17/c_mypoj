#include <stdio.h>
//0 不交叉，1交叉
int c;
int xstart,ystart;
int xend,yend;
int xleft,ytop;
int xright,ybottom;
int ifcrossLR(int x01,int y01,int x02,int y02,int y,int xl,int xr){
	if( (y>y01 && y>y02) || (y<y01 && y<y02))return 0;
	if(y01==y02 && y01==y){
		int minx=x01<x02?x01:x02;
		int maxx=x01>x02?x01:x02;
		if(minx>xr || maxx<xl) return 0;
		else return 1;
	}
	else if(y01==y02 && y01!=y){
		return 0;
	}
	else{
		if(x01==x02){
			int miny=y01<y02?y01:y02;
			int maxy=y01>y02?y01:y02;
			if(miny>y || maxy<y || x01<xl || x01>xr) return 0;
			else return 1;
		}
		else{
			double k=(double)(y01-y02)/(double)(x01-x02);
			double xin=x01-(y01-y)/k;
			if(xin<(double)xl || xin>(double)xr)return 0;
			else return 1;
		}
	}
}
int ifcrossUD(int x01,int y01,int x02,int y02,int x,int yd,int yu){
	if( (x>x01 && x>x02) || (x<x01 && x<x02))return 0;
	if(x01==x02 && x01==x){
		int miny=y01<y02?y01:y02;
		int maxy=y01>y02?y01:y02;
		if(miny>yu || maxy<yd) return 0;
		else return 1;
	}
	else if(x01==x02 && x01!=x){
		return 0;
	}
	else{

		double k=(double)(y01-y02)/(double)(x01-x02);
		double yin=y01-(x01-x)*k;
//		printf("yin is %f,yd is %d,yu is %d\n",yin,yd,yu);
		if(yin<(double)yd || yin>(double)yu)return 0;
		else return 1;

	}
}
int main(){
	scanf("%d",&c);
	while(c--){
		scanf("%d %d %d %d %d %d %d %d",&xstart,&ystart,&xend,&yend,&xleft,&ytop,&xright,&ybottom);

		if(xleft>xright){
			xleft=xleft^xright;
			xright=xleft^xright;
			xleft=xleft^xright;
		}
		if(ytop<ybottom){
			ytop=ytop^ybottom;
			ybottom=ytop^ybottom;
			ytop=ytop^ybottom;
		}
		if(xstart<xright && xstart>xleft && xend<xright && xend>xleft &&
			ystart<ytop && ystart>ybottom && yend<ytop && yend>ybottom){
			printf("T\n");
			continue;
		}
		int sign=0;
		int top=ifcrossLR(xstart,ystart,xend,yend, ytop,xleft,xright);
		int bot=ifcrossLR(xstart,ystart,xend,yend, ybottom,xleft,xright);
		int left=ifcrossUD(xstart,ystart,xend,yend, xleft,ybottom,ytop);
		int right=ifcrossUD(xstart,ystart,xend,yend, xright,ybottom,ytop);
//		printf("%d %d %d %d\n",top,bot,left,right);
		sign=top+bot+left+right;
		if(sign)printf("T\n");
		else printf("F\n");
	}
	return 0;
}
