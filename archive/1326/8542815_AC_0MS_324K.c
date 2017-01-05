#include <stdio.h>
#include <string.h>
#include <math.h>

char from[20]={0,},to[20]={0,};
int miles;
char mode;

int main(){
	int sum;
	while(1){
		sum=0;
		while(1){
			scanf("%s",&from);
			if(strcmp(from,"#")==0) return;
			else if(strcmp(from,"0")==0) break;
			scanf("%s %d %c",&to,&miles,&mode);
			switch(mode){
				case 'F':{
					sum+=miles*2;
					break;
				}
				case 'B':{
					sum+=miles+(miles+1)/2;
					break;
				}
				case 'Y':{
					if(miles<=500) sum+=500;
					else sum+=miles;
					break;
				}
			}
		}
		printf("%d\n",sum);




	}



	return 0;
}
