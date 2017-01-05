#include <stdio.h>
#include <string.h>

char a[100]={0,};

int k1,k2,k3;

int getPos(char a){
	if(a>='a' && a<='i') return 1;
	if(a>='j' && a<='r') return 2;
	return 3;
}

void rotMe(int n){
	int len=strlen(a);
	int i;
	int count=0;
	int tempi;
	char temp;
//	printf("len=%d\n",len);
	for(i=0;i<len;i++){
		if(getPos(a[i])!=n){
//			printf("%c\n",a[i]);
			continue;
		}

		count++;
		if(count==1) {
			temp=a[i];
			tempi=i;
		}
		else {
//			printf("gonna change\n");
			temp=a[i]^temp;
			a[i]=a[i]^temp;
			temp=a[i]^temp;
		}



	}
	if (count!=0)a[tempi]=temp;
}


void handle(){
	int i;
	for(i=0;i<k1;i++){
		rotMe(1);
	}
	for(i=0;i<k2;i++){
		rotMe(2);
	}
	for(i=0;i<k3;i++){
		rotMe(3);
	}
	printf("%s\n",a);
}
int main(){

	while(1){
		scanf("%d%d%d",&k1,&k2,&k3);
		if(k1==0&&k2==0&&k3==0) break;
		scanf("%s",&a);
		handle();


	}





	return 0;
}
