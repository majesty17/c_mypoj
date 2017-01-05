#include <stdio.h>
#include <string.h>
char n[3];
char line[26];
char num[14];
int main(){
	int i,j,min,sum;
	while(1){

		gets(n);
		if(atoi(n)==0) break;
		min=0x7fffffff;
		sum=0;
		memset(num,0,14);
//		printf("n is %d\n",atoi(n));
		for(i=0;i<atoi(n);i++){
			gets(line);
//			printf("line is %s\n",line);

			for(j=0;j<25;j++){
				if(line[j]==' ') num[i]++;
			}

//			printf("num[%d] is %d\n",i,num[i]);
			min=min<num[i]?min:num[i];

		}
//		printf("min is %d\n",min);
		for(i=0;i<atoi(n);i++){
			sum+=num[i]-min;
		}


		printf("%d\n",sum);
	}
	return 0;
}
