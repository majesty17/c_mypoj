#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
char str[15];
int cmp(const void *x , const void *y){

	return *(char*)y-*(char*)x;
}
int chartoint(char a){
	return a-'A'+1;
}
int power(int x,int y){
	int ret=1,i;
	for(i=0;i<y;i++){
		ret*=x;
	}
	return ret;
}
int justify(int sum,char a,char b,char c,char d,char e){
	int s=chartoint(a)-power(chartoint(b),2)+power(chartoint(c),3)
		-power(chartoint(d),4)+power(chartoint(e),5);
	if(sum==s)return 1;
	else return 0;
}


int main(){
	int i,j,k,p,q,n;
	int len;
	while(1){
		scanf("%d %s",&n,&str);
		if(n==0 && strcmp(str,"END")==0) break;

		len=strlen(str);

//		printf("%s\n",str);
//		printf("before qsort\n");

		qsort(str,len,sizeof(str[0]),cmp);
//		printf("before loop\n");
		for(i=0;i<len;i++){
			for(j=0;j<len;j++){
				if(j==i) continue;
				for(k=0;k<len;k++){
					if(k==j || k==i) continue;
					for(p=0;p<len;p++){
						if(p==k || p==j || p==i) continue;
						for(q=0;q<len;q++){
							if(q==p || q==k || q==j || q==i) continue;
//							printf("before justify\n");
//							printf("%d,%d,%d,%d,%d\n",i,j,k,p,q);
							if(justify(n,str[i],str[j],str[k],str[p],str[q])) goto Here;
						}
					}
				}
			}
		}

	Here:
//		printf("after here\n");
		if(i==len) printf("no solution\n");
		else printf("%c%c%c%c%c\n",str[i],str[j],str[k],str[p],str[q]);





	}
	return 0;
}
