///C(m)=c(2m,m)-c(2m,m+1)
///catlanÊý
#include <stdio.h>
#include <limits.h>
//long long getFactorial(int n){
//	if(n==0 || n==1) return 1;
//
//	long long rus=1;
//	int i;
//	for(i=2;i<=n;i++){
//		rus*=i;
//	}
//	return rus;
//}
//long long getCmn(int m,int n){
//	long long rus=(getFactorial(m)/getFactorial(n))/getFactorial(m-n);
//	return rus;
//}
//long long getCatlan(int nodes){
//	long long rus=getCmn(nodes*2,nodes)-getCmn(nodes*2,nodes+1);
//	return rus;
//}
__int64 a[21]={1, 1, 2, 5, 14, 42,
			132, 429, 1430, 4862, 16796,
			58786, 208012, 742900, 2674440, 9694845,
			35357670, 129644790, 477638700ll,1767263190ll,6564120420ll};
__int64 b[21]={0,};
int getNodes(int m,int *p){
	__int64 k=(__int64)m;
	int i=0;
	while(1){
		if(k>=a[i]){
			k-=a[i];
//			printf("%I64d,",a[i]);
			i++;
		}
		else{
			break;
		}
	}
	*p=k;
	return i;
}
void getLeftAndRight(int *n1,int *n2,int *step1,int* step2,int node,int step){
	int node1,node2,st1,st2;
	int st=step;
	int i;
	for(i=0;i<node;){
		if(st>=a[i]*a[node-i-1]){
//			node1=i;
//			node2=node-i-1;
			st-=a[i]*a[node-i-1];
			i++;
		}
		else{
			break;
		}
	}
	///
	node1=i;node2=node-i-1;

	if(st==0){
		st1=0;
		st2=0;
	}else{
		st1=st/a[node2];
		st2=st%a[node2];
	}
	*n1=node1;
	*n2=node2;
	*step1=st1;
	*step2=st2;
}
void search(int nodes,int step){

	if(nodes==1){
		printf("X");
		return;
	}
	int n1,n2,step1,step2;
	getLeftAndRight(&n1,&n2,&step1,&step2,nodes,step);
//	printf("left %d,right %d,step1 %d,step2 %d..\tall node %d,all step %d********",n1,n2,step1,step2,nodes,step);
	if(n1==0 && n2!=0) {
		printf("X(");
		search(n2,step2);
		printf(")");
	}
	if(n1!=0 && n2==0){
		printf("(");
		search(n1,step1);
		printf(")X");
	}
	if(n1==0 && n2==0){
		printf("X");
	}
	if(n1*n2!=0){
		printf("(");
		search(n1,step1);
		printf(")X(");
		search(n2,step2);
		printf(")");
	}

	return;
}
int main(){
	int i;
//	b[0]=a[0];
//	for(i=1;i<21;i++){
//		b[i]=b[i-1]+a[i];
//		printf("%I64d,",b[i]);
//	}
//	return 0;





	int n;
	while(1){
		scanf("%d",&n);
		if(n<=0) return -1;
		int pos;
		int nodes=getNodes(n,&pos);
	//	printf("nodes:%d,pos:%d\n",nodes,pos);
		search(nodes,pos);
		printf("\n");
	}
	return 0;
}
