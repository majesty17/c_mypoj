#include <stdio.h>
int n;
typedef struct {
	char name[20];
	int ACs;
	int points;
}stu;
stu s[1000];
int cmp( const void *a , const void *b ){
	stu *c = (stu *)a;
	stu *d = (stu *)b;
	if(c->ACs != d->ACs) return d->ACs - c->ACs;
	else return c->points - d->points;
}


int main(){
	int i,j;
	int sub[4];
	int time[4];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",s[i].name);
		s[i].ACs=0;
		s[i].points=0;
		for(j=0;j<4;j++){
			scanf("%d %d",&sub[j],&time[j]);
			if(time[j]!=0) {
				s[i].ACs++;
				s[i].points+=time[j]+20*(sub[j]-1);
			}
		}








	}qsort(s,n,sizeof(s[0]),cmp);

		printf("%s %d %d\n",s[0].name,s[0].ACs,s[0].points);
	return 0;
}
