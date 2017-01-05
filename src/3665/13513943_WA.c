#include <stdio.h>
int n,t;
int num[1010];

int main(){
	scanf("%d %d",&n,&t);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}



	for(i=0;i<t;i++){
		//find max rate and output
		int max_pos=0;
		int max=-1;
		for(j=0;j<n;j++){
			if(num[j]>max){
				max_pos=j;
				max=num[j];
			}
		}
		printf("%d\n",max_pos+1);

		//set it to 0,add to others
		num[max_pos]=0;
		for(j=0;j<n;j++){
			if(max_pos==j){
				continue;
			}
			num[j]+=max/(n-1);
		}
		if(max_pos!=0){
			num[0]+=max%(n-1);
		}
		else{
			num[1]+=max%(n-1);
		}

	}
	return 0;
}
