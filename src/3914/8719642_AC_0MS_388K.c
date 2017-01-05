#include <stdio.h>
#include <string.h>
int n,p,s;
int dll_mem[21];
int pro_mem[10];
char pro_use_dll[10][22];

int running_pro[10];
char running_dll[21];
int loadDLL(int pro){
	int i,ret=0;
	for(i=0;i<strlen(pro_use_dll[pro]);i++){
		if(running_dll[pro_use_dll[pro][i]-'A']==0)ret+=dll_mem[pro_use_dll[pro][i]-'A'];
		running_dll[pro_use_dll[pro][i]-'A']++;
	}

	return ret;
}
int killDLL(int pro){
	int i,ret=0;
	for(i=0;i<strlen(pro_use_dll[pro]);i++){

		if(running_dll[pro_use_dll[pro][i]-'A']==1){
			ret+=dll_mem[pro_use_dll[pro][i]-'A'];
		}
		running_dll[pro_use_dll[pro][i]-'A']--;
	}
	return ret;
}
int main(){
	int i,max_mem;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		scanf("%d %d",&p,&s);

		for(i=0;i<n;i++){
			scanf("%d",&dll_mem[i]);
		}
		for(i=0;i<p;i++){
			scanf("%d %s",&pro_mem[i],pro_use_dll[i]);
		}
		//init
		max_mem=-1;

		memset(running_pro,0,40);
		memset(running_dll,0,21);
		int curr_mem=0;
		int curr_pro;
		for(i=0;i<s;i++){
			scanf("%d",&curr_pro);
			if(curr_pro>0){
				curr_mem+=pro_mem[curr_pro-1];
				if(running_pro[curr_pro-1]==0)curr_mem+=loadDLL(curr_pro-1);
				running_pro[curr_pro-1]++;
			}
			else if(curr_pro<0){
				curr_mem-=pro_mem[-curr_pro-1];
				running_pro[-curr_pro-1]--;
				if(running_pro[-curr_pro-1]==0)curr_mem-=killDLL(-curr_pro-1);
			}

			max_mem=max_mem>curr_mem?max_mem:curr_mem;
		}



		printf("%d\n",max_mem);

	}
	return 0;
}
