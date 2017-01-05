#include <stdio.h>
#include <string.h>
char map[]="0123456789ABCDEF";

char mem[257]={0,};
char A,B,temp;
int x,y;
int pos;
char charToNum(char a){
	if(a>'9') return a-'A'+10;
	else return a-'0';
}
char NumToChar(char a){
	return map[a];
}
void handle(){
	//while(mem[pos]!='8'){
	for(pos=0;pos<256;){
		switch(mem[pos]){
			case '0':{			//load to A
				x=charToNum(mem[pos+1]);
				y=charToNum(mem[pos+2]);
				A=charToNum(mem[16*x+y]);
				pos+=3;
				break;
			}
			case '1':{			//write A to addr
				x=charToNum(mem[pos+1]);
				y=charToNum(mem[pos+2]);
				mem[16*x+y]=NumToChar(A);
				pos+=3;

				break;
			}
			case '2':{			//swap A B
				A=A^B;
				B=A^B;
				A=A^B;
				pos+=1;
				break;
			}
			case '3':{			//A+B,higher word to B,lower word to A
				temp=A+B;
				A=temp&0xf;
				B=temp>>4;
				pos+=1;
				break;
			}
			case '4':{			//A++
				A++;
				A=A%16;
				pos+=1;
				break;
			}
			case '5':{			//A--
				A+=0xf;
				A=A%16;
				pos+=1;
				break;
			}
			case '6':{			//Jump if A==0
				x=charToNum(mem[pos+1]);
				y=charToNum(mem[pos+2]);
				if(A==0){
					pos=x*16+y;
				}else{
					pos+=3;
				}
				break;
			}
			case '7':{			//Jump
				x=charToNum(mem[pos+1]);
				y=charToNum(mem[pos+2]);
				pos=x*16+y;
				break;
			}
			case '8':{
				return;
			}
		}
//		printf("A=%d,B=%d\n",A,B);

	}
}



int main(){
	while(1){
		scanf("%s",&mem);
		if(mem[0]=='8') break;
		A=0;B=0;
		handle();
		printf("%s\n",mem);

	}

	return 0;
}