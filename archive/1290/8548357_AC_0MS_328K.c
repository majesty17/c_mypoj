#include <stdio.h>
int n;
char rubik[6][3][3];


int ifok(){
	int i,j;
	for(i=0;i<6;i++){
		for(j=1;j<9;j++){
			if(rubik[i][j/3][j%3]!=rubik[i][0][0]){
				return 0;
			}
		}
	}
	return 1;
}
void rote(int i){
	int temp;
	switch (i){
		case 1:{
			temp=rubik[0][0][0];rubik[0][0][0]=rubik[0][2][0];
			rubik[0][2][0]=rubik[0][2][2];rubik[0][2][2]=rubik[0][0][2];rubik[0][0][2]=temp;
			temp=rubik[0][0][1];rubik[0][0][1]=rubik[0][1][0];
			rubik[0][1][0]=rubik[0][2][1];rubik[0][2][1]=rubik[0][1][2];rubik[0][1][2]=temp;

			temp=rubik[3][0][2];rubik[3][0][2]=rubik[5][2][0];
			rubik[5][2][0]=rubik[1][2][0];rubik[1][2][0]=rubik[4][2][0];rubik[4][2][0]=temp;
			temp=rubik[3][1][2];rubik[3][1][2]=rubik[5][1][0];
			rubik[5][1][0]=rubik[1][1][0];rubik[1][1][0]=rubik[4][1][0];rubik[4][1][0]=temp;
			temp=rubik[3][2][2];rubik[3][2][2]=rubik[5][0][0];
			rubik[5][0][0]=rubik[1][0][0];rubik[1][0][0]=rubik[4][0][0];rubik[4][0][0]=temp;


			break;
		}
		case -1:{
			temp=rubik[0][0][0];rubik[0][0][0]=rubik[0][0][2];
			rubik[0][0][2]=rubik[0][2][2];rubik[0][2][2]=rubik[0][2][0];rubik[0][2][0]=temp;
			temp=rubik[0][0][1];rubik[0][0][1]=rubik[0][1][2];
			rubik[0][1][2]=rubik[0][2][1];rubik[0][2][1]=rubik[0][1][0];rubik[0][1][0]=temp;

			temp=rubik[3][0][2];rubik[3][0][2]=rubik[4][2][0];
			rubik[4][2][0]=rubik[1][2][0];rubik[1][2][0]=rubik[5][2][0];rubik[5][2][0]=temp;
			temp=rubik[3][1][2];rubik[3][1][2]=rubik[4][1][0];
			rubik[4][1][0]=rubik[1][1][0];rubik[1][1][0]=rubik[5][1][0];rubik[5][1][0]=temp;
			temp=rubik[3][2][2];rubik[3][2][2]=rubik[4][0][0];
			rubik[4][0][0]=rubik[1][0][0];rubik[1][0][0]=rubik[5][0][0];rubik[5][0][0]=temp;
			break;
		}
		case 2:{
			temp=rubik[1][0][0];rubik[1][0][0]=rubik[1][2][0];
			rubik[1][2][0]=rubik[1][2][2];rubik[1][2][2]=rubik[1][0][2];rubik[1][0][2]=temp;
			temp=rubik[1][0][1];rubik[1][0][1]=rubik[1][1][0];
			rubik[1][1][0]=rubik[1][2][1];rubik[1][2][1]=rubik[1][1][2];rubik[1][1][2]=temp;

			temp=rubik[0][0][2];rubik[0][0][2]=rubik[5][0][0];
			rubik[5][0][0]=rubik[2][2][0];rubik[2][2][0]=rubik[4][2][2];rubik[4][2][2]=temp;
			temp=rubik[0][1][2];rubik[0][1][2]=rubik[5][0][1];
			rubik[5][0][1]=rubik[2][1][0];rubik[2][1][0]=rubik[4][2][1];rubik[4][2][1]=temp;
			temp=rubik[0][2][2];rubik[0][2][2]=rubik[5][0][2];
			rubik[5][0][2]=rubik[2][0][0];rubik[2][0][0]=rubik[4][2][0];rubik[4][2][0]=temp;
			break;
		}
		case -2:{
			temp=rubik[1][0][0];rubik[1][0][0]=rubik[1][0][2];
			rubik[1][0][2]=rubik[1][2][2];rubik[1][2][2]=rubik[1][2][0];rubik[1][2][0]=temp;
			temp=rubik[1][0][1];rubik[1][0][1]=rubik[1][1][2];
			rubik[1][1][2]=rubik[1][2][1];rubik[1][2][1]=rubik[1][1][0];rubik[1][1][0]=temp;

			temp=rubik[0][0][2];rubik[0][0][2]=rubik[4][2][2];
			rubik[4][2][2]=rubik[2][2][0];rubik[2][2][0]=rubik[5][0][0];rubik[5][0][0]=temp;
			temp=rubik[0][1][2];rubik[0][1][2]=rubik[4][2][1];
			rubik[4][2][1]=rubik[2][1][0];rubik[2][1][0]=rubik[5][0][1];rubik[5][0][1]=temp;
			temp=rubik[0][2][2];rubik[0][2][2]=rubik[4][2][0];
			rubik[4][2][0]=rubik[2][0][0];rubik[2][0][0]=rubik[5][0][2];rubik[5][0][2]=temp;
			break;
		}
		case 3:{
			temp=rubik[2][0][0];rubik[2][0][0]=rubik[2][2][0];
			rubik[2][2][0]=rubik[2][2][2];rubik[2][2][2]=rubik[2][0][2];rubik[2][0][2]=temp;
			temp=rubik[2][0][1];rubik[2][0][1]=rubik[2][1][0];
			rubik[2][1][0]=rubik[2][2][1];rubik[2][2][1]=rubik[2][1][2];rubik[2][1][2]=temp;

			temp=rubik[1][0][2];rubik[1][0][2]=rubik[5][0][2];
			rubik[5][0][2]=rubik[3][2][0];rubik[3][2][0]=rubik[4][0][2];rubik[4][0][2]=temp;
			temp=rubik[1][1][2];rubik[1][1][2]=rubik[5][1][2];
			rubik[5][1][2]=rubik[3][1][0];rubik[3][1][0]=rubik[4][1][2];rubik[4][1][2]=temp;
			temp=rubik[1][2][2];rubik[1][2][2]=rubik[5][2][2];
			rubik[5][2][2]=rubik[3][0][0];rubik[3][0][0]=rubik[4][2][2];rubik[4][2][2]=temp;
			break;
		}
		case -3:{
			temp=rubik[2][0][0];rubik[2][0][0]=rubik[2][0][2];
			rubik[2][0][2]=rubik[2][2][2];rubik[2][2][2]=rubik[2][2][0];rubik[2][2][0]=temp;
			temp=rubik[2][0][1];rubik[2][0][1]=rubik[2][1][2];
			rubik[2][1][2]=rubik[2][2][1];rubik[2][2][1]=rubik[2][1][0];rubik[2][1][0]=temp;

			temp=rubik[1][0][2];rubik[1][0][2]=rubik[4][0][2];
			rubik[4][0][2]=rubik[3][2][0];rubik[3][2][0]=rubik[5][0][2];rubik[5][0][2]=temp;
			temp=rubik[1][1][2];rubik[1][1][2]=rubik[4][1][2];
			rubik[4][1][2]=rubik[3][1][0];rubik[3][1][0]=rubik[5][1][2];rubik[5][1][2]=temp;
			temp=rubik[1][2][2];rubik[1][2][2]=rubik[4][2][2];
			rubik[4][2][2]=rubik[3][0][0];rubik[3][0][0]=rubik[5][2][2];rubik[5][2][2]=temp;
			break;
		}
		case 4:{
			temp=rubik[3][0][0];rubik[3][0][0]=rubik[3][2][0];
			rubik[3][2][0]=rubik[3][2][2];rubik[3][2][2]=rubik[3][0][2];rubik[3][0][2]=temp;
			temp=rubik[3][0][1];rubik[3][0][1]=rubik[3][1][0];
			rubik[3][1][0]=rubik[3][2][1];rubik[3][2][1]=rubik[3][1][2];rubik[3][1][2]=temp;

			temp=rubik[2][0][2];rubik[2][0][2]=rubik[5][2][2];
			rubik[5][2][2]=rubik[0][2][0];rubik[0][2][0]=rubik[4][0][0];rubik[4][0][0]=temp;
			temp=rubik[2][1][2];rubik[2][1][2]=rubik[5][2][1];
			rubik[5][2][1]=rubik[0][1][0];rubik[0][1][0]=rubik[4][0][1];rubik[4][0][1]=temp;
			temp=rubik[2][2][2];rubik[2][2][2]=rubik[5][2][0];
			rubik[5][2][0]=rubik[0][0][0];rubik[0][0][0]=rubik[4][0][2];rubik[4][0][2]=temp;


			break;
		}
		case -4:{
			temp=rubik[3][0][0];rubik[3][0][0]=rubik[3][0][2];
			rubik[3][0][2]=rubik[3][2][2];rubik[3][2][2]=rubik[3][2][0];rubik[3][2][0]=temp;
			temp=rubik[3][0][1];rubik[3][0][1]=rubik[3][1][2];
			rubik[3][1][2]=rubik[3][2][1];rubik[3][2][1]=rubik[3][1][0];rubik[3][1][0]=temp;

			temp=rubik[2][0][2];rubik[2][0][2]=rubik[4][0][0];
			rubik[4][0][0]=rubik[0][2][0];rubik[0][2][0]=rubik[5][2][2];rubik[5][2][2]=temp;
			temp=rubik[2][1][2];rubik[2][1][2]=rubik[4][0][1];
			rubik[4][0][1]=rubik[0][1][0];rubik[0][1][0]=rubik[5][2][1];rubik[5][2][1]=temp;
			temp=rubik[2][2][2];rubik[2][2][2]=rubik[4][0][2];
			rubik[4][0][2]=rubik[0][0][0];rubik[0][0][0]=rubik[5][2][0];rubik[5][2][0]=temp;
			break;
		}
		case 5:{
			temp=rubik[4][0][0];rubik[4][0][0]=rubik[4][2][0];
			rubik[4][2][0]=rubik[4][2][2];rubik[4][2][2]=rubik[4][0][2];rubik[4][0][2]=temp;
			temp=rubik[4][0][1];rubik[4][0][1]=rubik[4][1][0];
			rubik[4][1][0]=rubik[4][2][1];rubik[4][2][1]=rubik[4][1][2];rubik[4][1][2]=temp;

			temp=rubik[0][0][0];rubik[0][0][0]=rubik[1][0][0];
			rubik[1][0][0]=rubik[2][0][0];rubik[2][0][0]=rubik[3][0][0];rubik[3][0][0]=temp;
			temp=rubik[0][0][1];rubik[0][0][1]=rubik[1][0][1];
			rubik[1][0][1]=rubik[2][0][1];rubik[2][0][1]=rubik[3][0][1];rubik[3][0][1]=temp;
			temp=rubik[0][0][2];rubik[0][0][2]=rubik[1][0][2];
			rubik[1][0][2]=rubik[2][0][2];rubik[2][0][2]=rubik[3][0][2];rubik[3][0][2]=temp;



			break;
		}
		case -5:{
			temp=rubik[4][0][0];rubik[4][0][0]=rubik[4][0][2];
			rubik[4][0][2]=rubik[4][2][2];rubik[4][2][2]=rubik[4][2][0];rubik[4][2][0]=temp;
			temp=rubik[4][0][1];rubik[4][0][1]=rubik[4][1][2];
			rubik[4][1][2]=rubik[4][2][1];rubik[4][2][1]=rubik[4][1][0];rubik[4][1][0]=temp;

			temp=rubik[0][0][0];rubik[0][0][0]=rubik[3][0][0];
			rubik[3][0][0]=rubik[2][0][0];rubik[2][0][0]=rubik[1][0][0];rubik[1][0][0]=temp;
			temp=rubik[0][0][1];rubik[0][0][1]=rubik[3][0][1];
			rubik[3][0][1]=rubik[2][0][1];rubik[2][0][1]=rubik[1][0][1];rubik[1][0][1]=temp;
			temp=rubik[0][0][2];rubik[0][0][2]=rubik[3][0][2];
			rubik[3][0][2]=rubik[2][0][2];rubik[2][0][2]=rubik[1][0][2];rubik[1][0][2]=temp;
			break;
		}
		case 6:{
			temp=rubik[5][0][0];rubik[5][0][0]=rubik[5][2][0];
			rubik[5][2][0]=rubik[5][2][2];rubik[5][2][2]=rubik[5][0][2];rubik[5][0][2]=temp;
			temp=rubik[5][0][1];rubik[5][0][1]=rubik[5][1][0];
			rubik[5][1][0]=rubik[5][2][1];rubik[5][2][1]=rubik[5][1][2];rubik[5][1][2]=temp;

			temp=rubik[0][2][0];rubik[0][2][0]=rubik[3][2][0];
			rubik[3][2][0]=rubik[2][2][0];rubik[2][2][0]=rubik[1][2][0];rubik[1][2][0]=temp;
			temp=rubik[0][2][1];rubik[0][2][1]=rubik[3][2][1];
			rubik[3][2][1]=rubik[2][2][1];rubik[2][2][1]=rubik[1][2][1];rubik[1][2][1]=temp;
			temp=rubik[0][2][2];rubik[0][2][2]=rubik[3][2][2];
			rubik[3][2][2]=rubik[2][2][2];rubik[2][2][2]=rubik[1][2][2];rubik[1][2][2]=temp;
			break;
		}
		case -6:{
			temp=rubik[5][0][0];rubik[5][0][0]=rubik[5][0][2];
			rubik[5][0][2]=rubik[5][2][2];rubik[5][2][2]=rubik[5][2][0];rubik[5][2][0]=temp;
			temp=rubik[5][0][1];rubik[5][0][1]=rubik[5][1][2];
			rubik[5][1][2]=rubik[5][2][1];rubik[5][2][1]=rubik[5][1][0];rubik[5][1][0]=temp;

			temp=rubik[0][2][0];rubik[0][2][0]=rubik[1][2][0];
			rubik[1][2][0]=rubik[2][2][0];rubik[2][2][0]=rubik[3][2][0];rubik[3][2][0]=temp;
			temp=rubik[0][2][1];rubik[0][2][1]=rubik[1][2][1];
			rubik[1][2][1]=rubik[2][2][1];rubik[2][2][1]=rubik[3][2][1];rubik[3][2][1]=temp;
			temp=rubik[0][2][2];rubik[0][2][2]=rubik[1][2][2];
			rubik[1][2][2]=rubik[2][2][2];rubik[2][2][2]=rubik[3][2][2];rubik[3][2][2]=temp;
			break;
		}

		default:
			break;
	}


}



int main(){
	int i,j;
	scanf("%d",&n);
	while(n--){
		for(i=0;i<3;i++){
			scanf("      %c %c %c",&rubik[4][i][0],&rubik[4][i][1],&rubik[4][i][2]);
		}
		for(i=0;i<3;i++){
			for(j=0;j<12;j++){
				scanf(" %c",&rubik[j/3][i][j%3]);
			}
		}
		for(i=0;i<3;i++){
			scanf("      %c %c %c",&rubik[5][i][0],&rubik[5][i][1],&rubik[5][i][2]);
		}
		int op;
		while(1){
			scanf("%d",&op);
			if(op==0) break;
			rote(op);
		}

		if(ifok()){
			printf("Yes, grandpa!\n");
		}
		else{
			printf("No, you are wrong!\n");
		}





	}
	return 0;
}
