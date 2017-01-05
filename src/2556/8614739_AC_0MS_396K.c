///  direction:  2
///            1   3
///              0
///

#include <stdio.h>



char line[201];
int main(){
	int i,len,x,y,dire;
	while(scanf("%s",&line)!=EOF){
		len=strlen(line);


		puts("300 420 moveto");
		puts("310 420 lineto");
		dire=0;
		x=310;y=420;
		for(i=0;i<len;i++){
			switch(line[i]){
				case 'A':{
					dire=(dire+1)%4;
					if(dire%2==0) x+=10*(1-dire);
					else y+=10*(dire-2);
					printf("%d %d lineto\n",x,y);
					break;
				}
				case 'V':{
					dire=(dire+3)%4;
					if(dire%2==0) x+=10*(1-dire);
					else y+=10*(dire-2);
					printf("%d %d lineto\n",x,y);
					break;
				}
				default:
					break;
			}
		}






		puts("stroke\nshowpage");
	}
	return 0;
}
