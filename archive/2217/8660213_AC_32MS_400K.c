#include <stdio.h>
#include <string.h>
int c;
char line1[10001];
char line2[10001];
int len1,len2;
int getComm(int pos1,int pos2){
	int ret=1,i=1;

	while(line1[pos1+i]==line2[pos2+i]){
		i++;
		ret++;
		if(pos1+i>=len1 || pos2+i>=len2) break;
	}
	return ret;
}
int getMaxComm(){
	int ret=-1,i;
	char tmp,*p,*q;
	for(i=0;i<len1;i++){
		tmp=line1[i];
		p=line2;
		while(1){
			q=strchr(p,tmp);
			if(q==NULL)break;
			int t=getComm(i,q-line2);
			ret=ret>t?ret:t;
			p=q+1;
			if(p-line2>=len2)break;
		}
	}
	return ret;
}
int main(){
//	strcpy(line1,"Tady nejsou zadni mimozemstani.");
//	strcpy(line2,"Lide tady take nejsou.");
//	len1=strlen(line1);
//	len2=strlen(line2);
//	printf("%d\n",getComm(4,14));
//	return 0;

	scanf("%d\n",&c);
	while(c--){
		gets(line1);
		gets(line2);
		len1=strlen(line1);
		len2=strlen(line2);

//		printf("%s\n",line1);
//		printf("%s\n",line2);
		printf("Nejdelsi spolecny retezec ma delku %d.\n",getMaxComm());
	}
	return 0;
}
