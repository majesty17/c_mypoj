#include <stdio.h>
char str[33];
short ip[4];
int n;
int main(){
   scanf("%d",&n);
   int i;
   while(n--){
      scanf("%s",&str);
      memset(ip,0,sizeof(short)*4);
      for(i=0;i<32;i++){
         if(str[i]=='1') ip[i/8]+=1<<(7-i%8);
      }
      printf("%d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
   }
   return 0;
}
