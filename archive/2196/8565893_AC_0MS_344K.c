#include <stdio.h>

int main(){
	int i;
	for(i=2992;i<10000;i++){
		int sum=i/1000+((i/100)%10)+((i/10)%10)+i%10;
		int sum16=(i>>12)+(i>>8)%16+(i>>4)%16+i%16;
		int sum12=(i/1728)+(i/144)%12+(i/12)%12+i%12;
		if(sum==sum16 && sum==sum12) printf("%d\n",i);
	}
	return 0;
}
