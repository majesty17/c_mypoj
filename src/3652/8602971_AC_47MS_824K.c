#include <stdio.h>
int A,B,C,num1;


int num[65536];
char str[19];
int main(){
	int i,j;
	while(1){
		scanf("%d",&A);
		if(A==0) break;
		scanf("%d %d %d",&B,&C,&num1);
		memset(str,0,19);
		memset(num,0,sizeof(int)*65536);
		num[0]=num1;
		for(i=1;i<65536;i++){

			num[i]=(A*num[i-1]+B)%C;
//			printf("num is <%d>\n",num[i]);
		}

//		printf("here\n");


		for(i=0;i<16;i++){
			int sum=0;
			for(j=0;j<65536;j++){
				sum+=(num[j]&(1<<i))>>i;
			}
//			printf("sum is %d\n",sum);
			if(sum==0) str[i]='0';
			else if (sum==65536) str[i]='1';
			else str[i]='?';
		}



		printf("%s\n",strrev(str));


	}
	return 0;
}
