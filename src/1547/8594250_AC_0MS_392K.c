#include <stdio.h>
int n;
struct student{
	int x,y,z;
	char name[9];
	int dimension;
}stu[9];
int cmp(const void *a,const void*b){
	return ((struct student*)a)->dimension-((struct student*)b)->dimension;
}
int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(n==-1) break;
		for(i=0;i<n;i++){
			scanf("%d %d %d %s",&(stu[i].x),&(stu[i].y),&(stu[i].z),&(stu[i].name));
			stu[i].dimension=stu[i].x*stu[i].y*stu[i].z;
		}
		qsort(stu,n,sizeof(stu[0]),cmp);
		printf("%s took clay from %s.\n",stu[n-1].name,stu[0].name);
	}
	return 0;
}
