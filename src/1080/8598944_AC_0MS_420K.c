#include <stdio.h>
#include <string.h>
int n;
int len1,len2;
char gen1[105],gen2[105];
char score[105][105];
short mem[105][105];
int getScore(char a,char b){
	if(a==b) return 5;
	else{
		if((a=='C'&&b=='A') || (a=='A'&&b=='C') || (a=='A'&&b=='T') ||(a=='T'&&b=='A')){
			return -1;
		}
		else if((a=='C'&&b=='G') || (a=='G'&&b=='C')){
			return -3;
		}
		else{
			return -2;
		}
	}
}
int getLone(char a){
	switch (a){
		case 'A':{
			return -3;
		}
		case 'C':{
			return -4;
		}
		case 'G':{
			return -2;
		}
		case 'T':{
			return -1;
		}
	}
}
int maxof3(int x,int y,int z){
	return x>(y>z?y:z)?x:(y>z?y:z);
}
int maxDis(int l1,int l2){
	if(l1==0 && l2==0) return 0;
	else if(l1==0 && l2!=0){
		int sum=0,i;
		for(i=0;i<l2;i++){
			sum+=getLone(gen2[i]);
		}
		mem[l1][l2]=sum;
		return sum;
	}
	else if(l1!=0 && l2==0){
		int sum=0,i;
		for(i=0;i<l1;i++){
			sum+=getLone(gen1[i]);
		}
		mem[l1][l2]=sum;
		return sum;
	}

	int way1;
	int way2;
	int way3;

	if(mem[l1-1][l2-1]!=0) way1=mem[l1-1][l2-1]+score[l1-1][l2-1];
	else way1=maxDis(l1-1,l2-1)+score[l1-1][l2-1];

	if(mem[l1-1][l2]!=0) way2=mem[l1-1][l2]+getLone(gen1[l1-1]);
	else way2=maxDis(l1-1,l2)+getLone(gen1[l1-1]);

	if(mem[l1][l2-1]!=0) way3=mem[l1][l2-1]+getLone(gen2[l2-1]);
	else way3=maxDis(l1,l2-1)+getLone(gen2[l2-1]);

	mem[l1][l2]=maxof3(way1,way2,way3);
	return mem[l1][l2];
}
int handle(){
	int sco=0;
	int i,j;

	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			score[i][j]=getScore(gen1[i],gen2[j]);
//			printf("%2d,",score[i][j]);
		}
//		printf("\n");
	}

	sco=maxDis(len1,len2);


	return sco;
}






int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d %s",&len1,&gen1);
		scanf("%d %s",&len2,&gen2);
		memset(mem,0,sizeof(short)*102*102);
		printf("%d\n",handle());


	}
	return 0;
}
