#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXOFCHD 100
struct node{
	struct node *next[MAXOFCHD];
	char name[9];
};

int n;
char path[85];
char buf[9];
struct node* root;
int dep=0;
void putblank(int d){
	while(d--) printf(" ");
}
void init(){
	root=(struct node*)malloc(sizeof(struct node));
	strcpy(root->name,"root");
	memset(root->next,0,MAXOFCHD*sizeof(struct node*));
}
int cmp(const struct node **a,const struct node **b){
	return strcmp((*a)->name,(*b)->name);
}
void output(struct node* no){
	int i;
	for(i=0;i<MAXOFCHD;i++){
		if(no->next[i]==NULL) break;
	}
	qsort(no->next,i,sizeof(no->next[0]),cmp);


	for(i=0;i<MAXOFCHD;i++){
		if(no->next[i]==NULL)break;
		putblank(dep);
		dep++;
		printf("%s\n",no->next[i]->name);
		output(no->next[i]);
		dep--;
	}
}
void addpath(){
	int i,j;
	char *p=path,*q;
	char *end=path+strlen(path);
	struct node *no=root;
	for(i=0;i<42;i++){
		if(p>=end) return;
		q=strchr(p,'\\');
		if(q==NULL)q=path+strlen(path);
		memset(buf,0,9);
		strncpy(buf,p,q-p);
//		printf("buf is %s\n",buf);
		//handle buf
		for(j=0;j<MAXOFCHD;j++){
			if(no->next[j]==NULL){
				no->next[j]=(struct node*)malloc(sizeof(struct node));
				no=no->next[j];
				memset(no->next,0,MAXOFCHD*sizeof(struct node*));
				strcpy(no->name,buf);
				break;
			}
			else if(strcmp(no->next[j]->name,buf)==0){
				no=no->next[j];
				strcpy(no->name,buf);
				break;
			}
		}
		p=q+1;
	}
	return;
}
int main(){
	init();
	int i;
	scanf("%d",&n);
	while(n--){
		memset(path,0,85);
		scanf("%s",&path);
		addpath();
	}
	output(root);
	return 0;
}
