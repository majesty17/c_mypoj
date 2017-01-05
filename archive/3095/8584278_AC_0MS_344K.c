#include <stdio.h>
#include <ctype.h>
#include <string.h>
char line[100];
int handle(){
	int len=strlen(line),i,j;
	int sum=0;
	for(i=0;i<len;i++){
//		printf("before now sum is %d\n",sum);
		if(line[i]=='.'){	//调洞里
			sum+=100;
			continue;
		}
		if(line[i]=='_'){	//停止
			continue;
		}
		if(line[i]=='/'){	//往左走
			j=i;
			while(1){
				j--;
				if(j<0){
					sum+=100;
					break;
				}
				if(line[j]=='.'){
					sum+=100;
					break;
				}
				else if(line[j]=='\\' || line[j]=='|'){
					break;
				}
				else{
					continue;
				}
			}
			continue;
		}
		if(line[i]=='\\'){	//往右走
			j=i;
			while(1){
				j++;
				if(j>=len){
					sum+=100;
					break;
				}
				if(line[j]=='.'){
					sum+=100;
					break;
				}
				else if(line[j]=='/' || line[j]=='|'){
					break;
				}
				else{
					continue;
				}
			}
			continue;
		}
		if(line[i]=='|'){	//左右各二分之一
			int ret=0;
			j=i;
			while(1){
				j--;
				if(j<0){
					ret+=100;
					break;
				}
				if(line[j]=='\\' || line[j]=='|'){
					break;
				}
				else if(line[j]=='.'){
					ret+=100;
					break;
				}
				else{
					continue;
				}
			}
			j=i;
			while(1){
				j++;
				if(j>=len){
					ret+=100;
					break;
				}
				if(line[j]=='/' || line[j]=='|'){
					break;
				}
				else if(line[j]=='.'){
					ret+=100;
					break;
				}
				else{
					continue;
				}
			}
			sum+=ret/2;
			continue;
		}


	}
	return sum/len;

}
int main(){
	int sum,i;
	while(1){
		gets(line);
		if(strcmp(line,"#")==0) break;
		printf("%d\n",handle());
	}
	return 0;
}
