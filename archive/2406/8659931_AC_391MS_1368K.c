#include <stdio.h>
#include <string.h>
char str[1000001];
int len;
int split(int segs){			//to test if the str can split to seg segs
	int i;
	for(i=1;i<segs;i++){
		if(memcmp((void*)str,(void*)(str+i*(len/segs)),len/segs)!=0) return 0;
	}
	return 1;
}
int getMaxPower(){
	len=strlen(str);
	if(len==1)return 1;
	int i;
	for(i=len;i>=2;i--){ 		//i is the pow
		if(len%i)continue;		//mod must be 0
		if(split(i)==1) return i;
	}
	return 1;
}
int main(){
	while(1){
		scanf("%s",&str);
		if(str[0]=='.')break;
		printf("%d\n",getMaxPower());
	}
	return 0;
}
