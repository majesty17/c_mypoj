#include <stdio.h>
short a[6];
int count,sum,i;

int add(){
	int t=0;
	for(i=0;i<6;i++){
		t+=a[i]*(i+1);
	}
	return t;
}
int findit(int n){ 				///time overflow
//	printf("gonna find %d\n",n);
	int i_1,i_2,i_3,i_4,i_5,i_6;

	for(i_1=0;i_1<=a[5];i_1++){
		for(i_2=0;i_2<=a[4];i_2++){
			for(i_3=0;i_3<=a[3];i_3++){
				for(i_4=0;i_4<=a[2];i_4++){
					for(i_5=0;i_5<=a[1];i_5++){
						for(i_6=0;i_6<=a[0];i_6++){
							if(n==(i_1*6+i_2*5+i_3*4+i_4*3+i_5*2+i_6*1)){
//								printf("%d*1+%d*2+%d*3+%d*4+%d*5+%d*6=%d,",i_1,i_2,i_3,i_4,i_5,i_6,n);
								return 1;
							}
						}
					}
				}
			}
		}
	}

	return 0;
}

void handle(){
	//step1:sum of them
	int su=add();
	//step2:if sum is odd print cannot!!
	if(su&1==1){
		printf("Collection #%d:\nCan't be divided.\n",count);
		return;
	}

		//剪支：如果全为偶数，可分
	if(a[0]%2==0 && a[1]%2==0 && a[2]%2==0 && a[3]%2==0 && a[4]%2==0 && a[5]%2==0){
		printf("It works!!!!!!!\n");
		printf("Collection #%d:\nCan be divided.\n",count);
		return;
	}


	//step3:if sum is even, find a combination of sum/2 among a[]
	int res=findit(su/2);
	if(res==0){
		printf("Collection #%d:\nCan't be divided.\n",count);
		return;
	}else{
		printf("Collection #%d:\nCan be divided.\n",count);
		return;
	}
}
int main(){

	while(1){
		scanf("%d%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5]);
		if(a[0]==0 &&a[1]==0 &&a[2]==0 &&a[3]==0 &&a[4]==0 &&a[5]==0 ){
			break;
		}
		a[0]%=8;a[1]%=8;a[2]%=8;a[3]%=8;a[4]%=8;a[5]%=8;

		count++;

		handle();
		printf("\n");
	}
	return 0;
}
