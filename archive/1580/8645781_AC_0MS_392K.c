#include <stdio.h>
#include <string.h>
char str1[30],str2[30];
char buf[10];
void makeSim(int low,int up){
	memset(buf,0,10);
	if(low==up){
		strcpy(buf,"1");
		return;
	}
	else if(up==0){
		strcpy(buf,"0");
		return;
	}
	int t=low<up?low:up;
//	printf("low is %d,up is %d,t is %d\n",low,up,t);
	do{
		if(low%t==0 && up%t==0){
			low/=t;
			up/=t;
			break;
		}
	}while(t--);
	sprintf(buf,"%d/%d",up,low);
}
int main(){
	int len1,len2,i,j,maxcom;
	while(1){
		scanf("%s",&str1);
		if(strcmp(str1,"-1")==0) break;
		scanf("%s",&str2);
		len1=strlen(str1);
		len2=strlen(str2);
		maxcom=-1;
		for(i=0;i<len1;i++){
			int tmp=0;
			char *p=strchr(str2,str1[i]);
			if(p==NULL)continue;

			for(j=0;;j++){
				if(i+j>=len1 || p+j>=str2+len2) break;

				else if(str1[i+j]==*(p+j)){
					tmp++;
				}

			}

			maxcom=maxcom>tmp?maxcom:tmp;

		}
		if(maxcom<0)maxcom=0;
		makeSim(len1+len2,maxcom*2);
		printf("appx(%s,%s) = %s\n",str1,str2,buf);
	}
	return 0;
}
