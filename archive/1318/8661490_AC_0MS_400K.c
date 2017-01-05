#include <stdio.h>
#include <string.h>
char dict[100][7];
char dict_asc[100][7];
char word[100][7];
int n,k;
char hr[]="******";
int cmp(const char *a,const char *b){return *a-*b;}
int cmpstr(const char *a,const char *b){
	return strcmp(a,b);
}
int search(int order){
	int i;
	int sign=0;
	for(i=0;i<n;i++){
		if(strcmp(word[order],dict_asc[i])==0) {
			printf("%s\n",dict[i]);
			sign++;
		}
	}
	return sign;
}
int main(){
	int i;
	for(i=0;;i++){
		scanf("%s",&dict[i]);
		if(dict[i][0]=='X')break;
	}
	n=i;
	qsort(dict,n,sizeof(dict[0]),cmpstr);
	for(i=0;i<n;i++){
		strcpy(dict_asc[i],dict[i]);
		qsort(dict_asc[i],strlen(dict[i]),sizeof(char),cmp);
	}



	for(i=0;;i++){
		scanf("%s",&word[i]);
		if(word[i][0]=='X')break;
		qsort(word[i],strlen(word[i]),sizeof(char),cmp);
	}
	k=i;

//	printf("%d %d\n",n,k);

	for(i=0;i<k;i++){
		if(search(i)>0){}
		else printf("NOT A VALID WORD\n");
		printf("%s\n",hr);
	}

	return 0;
}
