#include <stdio.h>
#include <string.h>

int s;				//1 <= s <= 10
char n[10];			//0 <= n <= 99 999 999
char buff[120]={0,};

char sLine[14]={0,};
char sSpace[14]={0,};


void prepare(){
	memset(sLine,0,14);
	memset(sSpace,0,14);
	int i=0;
	sLine[i]=' ';
	sSpace[i]=' ';
	for(i=1;i<=s;i++){
		sLine[i]='-';
		sSpace[i]=' ';
	}
	sLine[s+1]=' ';
	sSpace[s+1]=' ';
}
int hashead(char a){
	if(a=='1' || a=='4') return 0;
	return 1;
}
int hasmiddle(char a){
	if(a=='1' || a=='7' || a=='0') return 0;
	return 1;
}
int hastail(char a){
	if(a=='1' || a=='4' || a=='7') return 0;
	return 1;
}
int hasheadtomiddle(char a){
	if(a=='5' || a=='6') return 1;
	if(a=='1' || a=='2' || a=='3' || a=='7') return 2;
	return 3;
}
int hastailtomiddle(char a){
	if(a=='2') return 1;
	if(a=='1' || a=='3' || a=='4' || a=='5' || a=='7' || a=='9') return 2;
	return 3;
}
void phead(){

	int len=strlen(n),i;
	memset(buff,0,120);
	for(i=0;i<len;i++){
		if(hashead(n[i])){
			strcat(buff,sLine);
		}
		else {
			strcat(buff,sSpace);
		}
		if(i<len-1) strcat(buff," ");
	}
	printf("%s\n",buff);
}
void pheadtomiddle(){
		int len=strlen(n),i,j;
	memset(buff,0,120);
	char *p=buff;
	for(i=0;i<len;i++){
		if(hasheadtomiddle(n[i])==1){
			*p='|';
			p++;
			for(j=0;j<s+1;j++){
				*p=' ';
				p++;
			}
		}
		else if(hasheadtomiddle(n[i])==2){
			for(j=0;j<s+1;j++){
				*p=' ';
				p++;
			}
			*p='|';
			p++;
		}
		else {
			*p='|';
			p++;
			for(j=0;j<s;j++){
				*p=' ';
				p++;
			}
			*p='|';
			p++;
		}
		if(i<len-1){
			*p=' ';
			p++;
		}

	}

	for(i=0;i<s;i++){
		printf("%s\n",buff);
	}
}
void pmiddle(){
	int len=strlen(n),i;
	memset(buff,0,120);
	for(i=0;i<len;i++){
		if(hasmiddle(n[i])){
			strcat(buff,sLine);
		}
		else {
			strcat(buff,sSpace);
		}
		if(i<len-1) strcat(buff," ");
	}
	printf("%s\n",buff);
}
void ptailtomiddle(){
	int len=strlen(n),i,j;
	memset(buff,0,120);
	char *p=buff;
	for(i=0;i<len;i++){
		if(hastailtomiddle(n[i])==1){
			*p='|';
			p++;
			for(j=0;j<s+1;j++){
				*p=' ';
				p++;
			}
		}
		else if(hastailtomiddle(n[i])==2){
			for(j=0;j<s+1;j++){
				*p=' ';
				p++;
			}
			*p='|';
			p++;
		}
		else {
			*p='|';
			p++;
			for(j=0;j<s;j++){
				*p=' ';
				p++;
			}
			*p='|';
			p++;
		}
		if(i<len-1){
			*p=' ';
			p++;
		}

	}

	for(i=0;i<s;i++){
		printf("%s\n",buff);
	}
}
void ptail(){
	int len=strlen(n),i;
	memset(buff,0,120);
	for(i=0;i<len;i++){
		if(hastail(n[i])){
			strcat(buff,sLine);
		}
		else {
			strcat(buff,sSpace);
		}
		if(i<len-1) strcat(buff," ");
	}
	printf("%s\n",buff);

}
void handle(){
	int i,j;
	//print head
	phead();
	//print head to middle for s times
	pheadtomiddle();
	//print middle
	pmiddle();
	//print tail to middle for s times
	ptailtomiddle();
	//print tail
	ptail();

	printf("\n");
}


int main(){
	while(1){
		scanf("%d %s",&s,&n);
		if(s==0) break;

		prepare();

		handle();







	}



}
