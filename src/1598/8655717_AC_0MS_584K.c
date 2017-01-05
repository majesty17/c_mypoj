#include <stdio.h>
#include <string.h>
int k,n;
char keys[21][21];

struct st{
	char line[100];
	int num;
}excute[21];
char buf[21];


int cmp(const struct st* a,const struct st* b){
	return a->num-b->num;
}
int main(){
	int i,j,order=0;
	while(scanf("%d %d\n",&k,&n)!=EOF){
		for(i=0;i<k;i++){
			gets(keys[i]);
		}
		memset(excute,0,sizeof(struct st)*n);
		for(i=0;i<n;i++){
			gets(excute[i].line);
		}

		for(i=0;i<k;i++){
			strcpy(buf,keys[i]);
			strupr(buf);
			int len=strlen(buf);
			for(j=0;j<n;j++){
				char *p=excute[j].line;
				char *p1=strstr(p,keys[i]);
				char *p2=strstr(p,buf);
				if(p1!=NULL){
					if(p1>p && isalpha(*(p1-1))!=0 ) continue;
					if(p1<p+strlen(p)-len && isalpha(*(p1+len))!=0 ) continue;
					excute[j].num++;
				}
				else if(p2!=NULL){
					if(p2>p && isalpha(*(p2-1))!=0 ) continue;
					if(p2<p+strlen(p)-len && isalpha(*(p2+len))!=0 ) continue;
					excute[j].num++;
				}

			}
		}

		qsort(excute,n,sizeof(excute[0]),cmp);
		printf("Excuse Set #%d\n",++order);
		i=n-1;
		int tmp=excute[n-1].num;
		while(excute[i].num==tmp) {
			printf("%s\n",excute[i].line);
			i--;
		}
		printf("\n");
	}
	return 0;
}
