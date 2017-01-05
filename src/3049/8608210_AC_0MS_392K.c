#include <stdio.h>
int len,n;
char all[30]={0,};
char buff[16]={0,};
int cmp(const void *a,const void *b){
	return *(char*)a-*(char*)b;
}
int isVowel(char a){
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')return 1;
	else return 0;
}
int getOnes(int num){
	int m=0;
	while(num){
		num=num&(num-1);
		m++;
	}
	return m;
}
int main(){



	int i,j;
	scanf("%d %d",&len,&n);
	for(i=0;i<n;i++){
		scanf("\n%c",&all[i]);
	}
	qsort(all,n,1,cmp);

//
//	for(i=0;i<n;i++){
//		printf("%c,",all[i]);
//	}
//	printf("\n");



	for(i=((1<<len)-1)<<(n-len);i>=(1<<len)-1;i--){
		if(getOnes(i)!=len) continue;
//		printf("%d,",i);
		memset(buff,0,16);
		int pos=0;
		int isv=0,nov=0;
		for(j=0;j<n;j++){
			if((i&(1<<(n-j-1)))==0)continue;
			else{
//				printf("j is %d\n",j);
				if(isVowel(all[j])==1) isv++;
				else nov++;
				buff[pos++]=all[j];
			}
		}
//		printf("is v is %d,nov is %d\n",isv,nov);
		if(isv>=1 && nov>=2)
			printf("%s\n",buff);

	}






	return 0;
}
