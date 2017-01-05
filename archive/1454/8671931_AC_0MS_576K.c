#include <stdio.h>
#include <string.h>
char num[1000];
short count[10];
int n;
void mul(int lo){							//wholerus*=lower
	int len=strlen(num);
	int c=0,i,temp;

	for(i=0;i<len;i++){
		temp=(num[i]-'0')*lo+c;
		num[i]=temp%10+'0';
		c=temp/10;
	}
	if(c!=0){
		char buf[10];
		itoa(c,buf,10);
		strcat(num,strrev(buf));
	}
}

void cal(int k){
	memset(num,0,sizeof(num));
	num[0]='1';
	int i;
	for(i=2;i<=k;i++){
		mul(i);
	}
	//printf("rut is %s\n",num);
	for(i=0;i<strlen(num);i++){
		count[num[i]-'0']++;
	}
}
int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(!n)break;
		memset(count,0,sizeof(count));
		cal(n);
		printf("%d! --\n",n);
		printf("   (0)%5d    (1)%5d    (2)%5d    (3)%5d    (4)%5d\n",count[0],count[1],count[2],count[3],count[4]);
		printf("   (5)%5d    (6)%5d    (7)%5d    (8)%5d    (9)%5d\n",count[5],count[6],count[7],count[8],count[9]);
	}
	return 0;
}
