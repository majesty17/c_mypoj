#include <stdio.h>
int a1,a2,a3,a4,a5,a6;

int main(){

	int count;

	while(1){
		scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
		if(a1==0 && a2==0 && a3==0 && a4==0 && a5==0 && a6==0){
			return -1;
		}
		count=0;

		count+=a6+a5+a4+a3/4;			//count至少这么多
		a1=(a1>=a5*11)?(a1-a5*11):(0);	//5×5的填满
		int resOf4x4=5*a4;			//4*4能放2×2的个数
		if(a2>=resOf4x4){				//填满4×4
			a2=a2-resOf4x4;
		}else{
			a1=(a1>((resOf4x4-a2)*4))?(a1-((resOf4x4-a2)*4)):(0);
			a2=0;
		}
		count++;					//3*3不足4个的时候，可能是0，1，2，3
		a3=a3%4;
		switch (a3){
			case 0:{
				count--;
				break;
			}
			case 1:{
				if(a2>=5){
					a2-=5;
					a1=(a1>=7)?(a1-7):(0);
				}
				else{
					a1=(a1>=27-a2*4)?(a1-27+a2*4):(0);
					a2=0;
				}
				break;
			}
			case 2:{
				if(a2>=3){
					a2-=3;
					a1=(a1>=6)?(a1-6):(0);
				}
				else{
					a1=(a1>=18-a2*4)?(a1-18+a2*4):(0);
					a2=0;
				}
				break;
			}
			case 3:{
				if(a2>=1){
					a2-=1;
					a1=(a1>=5)?(a1-5):(0);
				}
				else{
					a1=(a1>=9)?(a1-9):(0);
					a2=0;
				}
				break;
			}
		}
		count+=a2/9;
		a2=a2%9;
		count++;
		if(a2==0){
			count--;
		}else{
			a1=(a1>=36-a2*4)?(a1-36+a2*4):(0);
		}
		count+=(a1+35)/36;
		printf("%d\n",count);
	}


	return 0;
}
