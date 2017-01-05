#include <stdio.h>
#include <string.h>
char buff[40];
short pos[2][16];
int cmpwhite(const void *a,const void *b){
	short x=*(short*)a;
	short y=*(short*)b;

	if(x%10!=y%10)return x%10-y%10;
	else return x/10-y/10;
}
int cmpblack(const void *a,const void *b){
	short x=*(short*)a;
	short y=*(short*)b;

	if(x%10!=y%10)return y%10-x%10;
	else return x/10-y/10;
}
void handle(int x,int y,char a){
	short po=(y/4)*10+(8-x);
	switch (a){
		case 'K':{
			pos[0][0]=po;
			break;
		}
		case 'Q':{
			pos[0][1]=po;
			break;
		}
		case 'R':{
			if(pos[0][2]==0)pos[0][2]=po;
			else pos[0][3]=po;
			break;
		}
		case 'B':{
			if(pos[0][4]==0)pos[0][4]=po;
			else pos[0][5]=po;
			break;
		}
		case 'N':{
			if(pos[0][6]==0)pos[0][6]=po;
			else pos[0][7]=po;
			break;
		}
		case 'P':{
			int i=8;
			while(pos[0][i]!=0){
				i++;
			}
			pos[0][i]=po;
			break;
		}

		case 'k':{
			pos[1][0]=po;
			break;
		}
		case 'q':{
			pos[1][1]=po;
			break;
		}
		case 'r':{
			if(pos[1][2]==0)pos[1][2]=po;
			else pos[1][3]=po;
			break;
		}
		case 'b':{
			if(pos[1][4]==0)pos[1][4]=po;
			else pos[1][5]=po;
			break;
		}
		case 'n':{
			if(pos[1][6]==0)pos[1][6]=po;
			else pos[1][7]=po;
			break;
		}
		case 'p':{
			int i=8;
			while(pos[1][i]!=0){
				i++;
			}
			pos[1][i]=po;
			break;
		}
		default:
			break;
	}

}
int main(){
	int i,j;
	gets(buff);
	for(i=0;i<8;i++){
		gets(buff);
		for(j=0;j<strlen(buff);j++){
			if(isalpha(buff[j])){
				handle(i,j,buff[j]);
			}
		}
		gets(buff);
	}


	qsort(pos[0]+2,2,sizeof(short),cmpwhite);
	qsort(pos[0]+4,2,sizeof(short),cmpwhite);
	qsort(pos[0]+6,2,sizeof(short),cmpwhite);
	qsort(pos[0]+8,8,sizeof(short),cmpwhite);

	qsort(pos[1]+2,2,sizeof(short),cmpblack);
	qsort(pos[1]+4,2,sizeof(short),cmpblack);
	qsort(pos[1]+6,2,sizeof(short),cmpblack);
	qsort(pos[1]+8,8,sizeof(short),cmpblack);






	printf("White: ");
	for(i=0;i<16;i++){
		if(pos[0][i]==0) continue;
		switch (i){
			case 0:{
				printf("K");
				break;
			}
			case 1:{
				printf("Q");
				break;
			}
			case 2:
			case 3:{
				printf("R");
				break;
			}
			case 4:
			case 5:{
				printf("B");
				break;
			}
			case 6:
			case 7:{
				printf("N");
				break;
			}
			default:
				break;
		}
		printf("%c%d",pos[0][i]/10+'a',pos[0][i]%10);


		if(i<15) printf(",");
	}

	printf("\n");
	printf("Black: ");
	for(i=0;i<16;i++){
		if(pos[1][i]==0) continue;
		switch (i){
			case 0:{
				printf("K");
				break;
			}
			case 1:{
				printf("Q");
				break;
			}
			case 2:
			case 3:{
				printf("R");
				break;
			}
			case 4:
			case 5:{
				printf("B");
				break;
			}
			case 6:
			case 7:{
				printf("N");
				break;
			}
			default:
				break;
		}
		printf("%c%d",pos[1][i]/10+'a',pos[1][i]%10);


		if(i<15) printf(",");
	}

	printf("\n");
	return 0;
}
