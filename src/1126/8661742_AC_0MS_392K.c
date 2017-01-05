#include <stdio.h>
#include <string.h>
//p through z and N, C, D, E, and I.
char word[257],len;
char rule0(char ch){
	if(ch>='p'&&ch<='z') return 1;
	else if(ch=='N')return 2;
	else if(ch=='C' || ch=='D' || ch=='E' || ch=='I')return 3;
	else return 0;
}
int prejudge(){//判断是否都由合法字符组成
	int i;
	for(i=0;i<len;i++){
		if(rule0(word[i])==0)return 0;
	}
	return 1;
}
int judge(char *x,char *y){
	if(x==y && rule0(*x)==1) return 1;
	if(rule0(*x)==1 && x!=y)return 0;
	if(rule0(*x)==2) return judge(x+1,y);
	if(rule0(*x)==3 && y-x<2){
		return 0;
	}
	else{
		char *i;
		for(i=x+1;i<y;i++){
			if(judge(x+1,i)==1 && judge(i+1,y)==1)return 1;
		}
		return 0;
	}

}
int main(){
	while (scanf("%s",&word)!=EOF){
		len=strlen(word);
		char *p=word;
		char *q=word+strlen(word)-1;
		if(prejudge()==1 && judge(p,q)==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
