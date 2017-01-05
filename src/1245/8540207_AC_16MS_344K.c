#include <stdio.h>
#include <string.h>
#include <math.h>
int c;
typedef struct {
	char name[11];
	short times[7];
	int noZero;
	int sum;
	int avg;
}stu,*pstu;

stu s[20];

int cmp( stu *a ,stu *b){

	if(a->noZero < b->noZero) return 1;
	else if(a->noZero > b->noZero) return -1;
	else{
		if(a->sum > b->sum) return 1;
		if(a->sum < b->sum) return -1;
		else{
			if(a->avg > b->avg) return 1;
			if(a->avg < b->avg) return -1;
			else {
				return strcmp(a->name,b->name);
			}
		}
	}

	return 0;
}
int cmpnoname( stu *a ,stu *b){

	if(a->noZero < b->noZero) return 1;
	else if(a->noZero > b->noZero) return -1;
	else{
		if(a->sum > b->sum) return 1;
		if(a->sum < b->sum) return -1;
		else{
			if(a->avg > b->avg) return 1;
			if(a->avg < b->avg) return -1;
			else {
				return 0;//strcmp(a->name,b->name);
			}
		}
	}

	return 0;
}




void make(pstu ps){
	int i,j;
	ps->noZero=0;
	int sum=0;
	double lnsum=0.0;
	for(i=0;i<7;i++){
		sum+=ps->times[i];
		if (ps->times[i]!=0) {
			ps->noZero++;
			lnsum+=log(ps->times[i]);
		}

	}
	ps->sum=sum;
	if(ps->noZero!=0){
		ps->avg=floor(exp(lnsum/ps->noZero)+.5);
	}else{
		ps->avg=0;
	}

}
void putBlank(int n){
	while(n--) printf(" ");
}
int main(){
	int i,j,count=0;
	while(1){
		scanf("%d",&c);
		if(!c) break;
		memset(s,0,sizeof(stu)*20);
		for(i=0;i<c;i++){
			scanf("%s",&s[i].name);
			for(j=0;j<7;j++){
				scanf("%d",&(s[i].times[j]));
			}

			make(&s[i]);
		}

		qsort(s,c,sizeof(s[0]),cmp);


		printf("CONTEST %d\n",++count);
		int reali=0,last;
		for(i=0;i<c;i++){
			if(i==0) {
				reali=1;
				printf("01");
			}
			if(i>0){
				if(cmpnoname(&s[i],&s[i-1])==0){
					reali=last;
				}
				else reali=i+1;
				if(reali<10) printf("0");
				printf("%d",reali);

			}
			last=reali;



			printf(" %s",s[i].name);
			putBlank(10-strlen(s[i].name));
			printf(" %d %4d %3d",s[i].noZero,s[i].sum,s[i].avg);
			for(j=0;j<7;j++){
				printf(" %3d",s[i].times[j]);
			}
			printf("\n");
		}




	}
}
