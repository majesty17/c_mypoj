#include <stdio.h>
int c;
int x01,y01;
int x02,y02;
int x03,y03;
int x04,y04;
int main(){
	scanf("%d",&c);
	printf("INTERSECTING LINES OUTPUT\n");
	while(c--){
		scanf("%d %d %d %d %d %d %d %d",&x01,&y01,&x02,&y02,&x03,&y03,&x04,&y04);
		int t=(y02-y01)*(x04-x03)-(y04-y03)*(x02-x01);
		if(t==0){
			if((y02-y01)*(x03-x02)-(y03-y02)*(x02-x01)==0){
				printf("LINE\n");
			}
			else{
				printf("NONE\n");
			}
		}
		else{
			int a1=y01-y02;
			int b1=-x01+x02;
			int c1=a1*x01+b1*y01;
			int a2=y03-y04;
			int b2=-x03+x04;
			int c2=a2*x03+b2*y03;
//			printf("系数：%d %d %d %d %d %d\n",a1,b1,c1,a2,b2,c2);
			double x=(double)(c1*b2-c2*b1)/(double)(a1*b2-a2*b1);
			double y=(double)(a1*c2-a2*c1)/(double)(a1*b2-a2*b1);
			printf("POINT %.2f %.2f\n",x,y);
		}




	}





	printf("END OF OUTPUT\n");
	return 0;
}
