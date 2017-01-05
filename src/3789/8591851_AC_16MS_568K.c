#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int hh,mm,ss;
char out0[19];
char out[19];
char buf[7];
int main(){
	int count=0,i;
	scanf("%d",&n);
	while(n--){
		memset(out,'0',18);
		memset(out0,'0',18);
		out[19]='\0';
		out0[19]='\0';
		scanf("%d:%d:%d",&hh,&mm,&ss);

		itoa(hh,buf,2);
		strncpy(out+(6-strlen(buf)),buf,strlen(buf));
		itoa(mm,buf,2);
		strncpy(out+(12-strlen(buf)),buf,strlen(buf));
		itoa(ss,buf,2);
		strncpy(out+(18-strlen(buf)),buf,strlen(buf));
		for(i=0;i<18;i++){
			out0[i]=   out[(i%3)*6+i/3];
		}

		printf("%d %s %s\n",++count,out0,out);
	}
	return 0;
}
