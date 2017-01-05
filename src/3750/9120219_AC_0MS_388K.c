#include <stdio.h>
#include <stdlib.h>
int N,W,S;

struct node {
	char name[20];
	struct node* next;
	struct node* pre;	//双向链表
};

int main(){
	scanf("%d",&N);
	struct node* pfirstchild=(struct node*)malloc(sizeof(struct node));
	scanf("%s",pfirstchild->name);
	struct node* pTempchild = pfirstchild;
	int i;
	for(i=1;i<N;i++){
		struct node* pnext=(struct node*)malloc(sizeof(struct node));
		scanf("%s",pnext->name);
		pTempchild->next=pnext;
		pTempchild->next->pre=pTempchild;
		pTempchild=pTempchild->next;
	}
	pTempchild->next=pfirstchild;
	pfirstchild->pre=pTempchild;	//构成环
	pTempchild=pfirstchild;			//回到头
	scanf("%d,%d",&W,&S);

	while(--W){
		pTempchild=pTempchild->next;
	}
	while(N--){
		for(i=1;i<S;i++){	//跟你的区别是直接定位到要删的节点，你是定位到要删的节点的前驱
			pTempchild=pTempchild->next;
		}
		struct node* tmp=pTempchild->pre;
		tmp->next=pTempchild->next;
		pTempchild->next->pre=tmp;
		printf("%s\n",pTempchild->name);
		free(pTempchild);
		pTempchild=tmp->next;
	}
	return 0;
}
