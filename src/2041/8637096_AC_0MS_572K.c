#include <stdio.h>
int n;
char op[10];
char code[15];
int main(){
	int i,j;
	scanf("%d",&n);
	while(n--){
		scanf("%s %s",&op,&code);
		int len=strlen(code);
		for(i=strlen(op)-1;i>=0;i--){
			switch (op[i]){
				case 'J':{
					char tmp=code[len-1];
					for(j=len-1;j>0;j--){
						code[j]=code[j-1];
					}
					code[0]=tmp;
					break;
				}
				case 'C':{
					char tmp=code[0];
					for(j=0;j<len-1;j++){
						code[j]=code[j+1];
					}
					code[len-1]=tmp;
					break;
				}
				case 'E':{
					if(len%2==0){
						for(j=0;j<len/2;j++){
							code[j]=code[j]^code[j+len/2];
							code[j+len/2]=code[j]^code[j+len/2];
							code[j]=code[j]^code[j+len/2];
						}
					}
					else{
						for(j=0;j<len/2;j++){
							code[j]=code[j]^code[j+len/2+1];
							code[j+len/2+1]=code[j]^code[j+len/2+1];
							code[j]=code[j]^code[j+len/2+1];
						}
					}
					break;
				}
				case 'A':{
					strrev(code);
					break;
				}
				case 'P':{
					for(j=0;j<len;j++){
						if(isdigit(code[j])) {
							code[j]-='0';
							code[j]+=9;
							code[j]%=10;
							code[j]+='0';
						}
					}
					break;
				}
				case 'M':{
					for(j=0;j<len;j++){
						if(isdigit(code[j])) {
							code[j]-='0';
							code[j]+=1;
							code[j]%=10;
							code[j]+='0';
						}
					}
					break;
				}
				default:
					break;
			}
		}


		printf("%s\n",code);




	}
	return 0;
}
