#include <stdio.h>
char word[21];
int isvowel(char a){
	if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u') return 1;
	return 0;
}
int main(){
	int i,len;

	while(1){
		scanf("%s",&word);
		if(strcmp(word,"end")==0) break;
		len=strlen(word);

		int hasvowel=0,sign=0;
		for(i=0;i<len;i++){
			if(isvowel(word[i])==1) hasvowel++;
			if(i<len-2 && ((isvowel(word[i])==1 &&isvowel(word[i+1])==1&&isvowel(word[i+2])==1) || (isvowel(word[i])==0 &&isvowel(word[i+1])==0&&isvowel(word[i+2])==0))){
//				printf("<%s> is not acceptable.\n",word);
				sign=1;
				break;
			}
			if(i<len-1 && word[i]==word[i+1] && word[i]!='e' && word[i]!='o'){
//				printf("<%s> is not acceptable.\n",word);
				sign=1;
				break;
			}
		}
		if(hasvowel==0 || sign==1){
			printf("<%s> is not acceptable.\n",word);

		}
		else{
			printf("<%s> is acceptable.\n",word);
		}



	}
	return 0;
}
