//TLE
#include <stdio.h>
#include <string.h>
char *title[]={"South player:","West player:","North player:","East player:"};
char line_fnum[150]="|2 2|4 4|K K|4 4|5 5|6 6|Q Q|A A|4 4|8 8|T T|J J|8 8|";
char line_kind[150]="| C | C | C | D | D | D | D | D | S | S | S | S | H |";
char line[]="+---+---+---+---+---+---+---+---+---+---+---+---+---+";
char order[5];
char str[105];
char str1[53];
char hash_kind[256]="0000000000000000000000000000000000000000000000000000000000000000000120004000000000030000000";
char hash_fnum[256]="00000000000000000000000000000000000000000000000000123456780000000=00000000:<00000;009000000";
struct puck{
	char num;
	char kind;
};
struct player{
	struct puck pucks[13];
}players[4];
int getoff(char a){
	switch (a){
		case 'S':return 1;
		case 'W':return 2;
		case 'N':return 3;
		case 'E':return 4;
	}
}
int cmp(const struct puck *a,const struct puck *b){
	int i=hash_kind[a->kind]-hash_kind[b->kind];
	if(i!=0) return i;
	return hash_fnum[a->num]-hash_fnum[b->num];
}
int main(){
//	printf("%c %c %c %c\n",hash_kind['C'],hash_kind['D'],hash_kind['S'],hash_kind['H']);
//	printf("%c %c %c %c %c %c %c %c %c %c %c %c %c\n",hash_fnum['2'],hash_fnum['3'],hash_fnum['4'],hash_fnum['5'],hash_fnum['6'],hash_fnum['7'],hash_fnum['8'],hash_fnum['9'],hash_fnum['T'],hash_fnum['J'],hash_fnum['Q'],hash_fnum['K'],hash_fnum['A']);
//	return 0;


	int i,j;
	while(1){
		scanf("%s",&order);
		if(order[0]=='#')break;
		scanf("%s %s",&str,&str1);
		strcat(str,str1);
		int offset=getoff(order[0]);
		for(i=0;i<52;i++){
			players[(i+offset)%4].pucks[i/4].kind=str[i*2];
			players[(i+offset)%4].pucks[i/4].num=str[i*2+1];
		}
		for(i=0;i<4;i++)qsort(players[i].pucks,13,sizeof(struct puck),cmp);
		for(j=0;j<4;j++){
			for(i=0;i<13;i++){
				line_fnum[4*i+1]=players[j].pucks[i].num;
				line_fnum[4*i+3]=line_fnum[4*i+1];
				line_kind[4*i+2]=players[j].pucks[i].kind;
			}
			printf("%s\n",title[j]);
			printf("%s\n",line);
			printf("%s\n",line_fnum);
			printf("%s\n",line_kind);
			printf("%s\n",line_fnum);
			printf("%s\n",line);
		}
		printf("\n");
	}
	return 0;
}
