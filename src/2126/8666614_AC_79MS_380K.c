#include <stdio.h>

int main(){
  int n,a[21],i;
  scanf("%d",&n);
  for(i=0;i<=n;i++)
  scanf("%d",&a[i]);

  if(n<2)  puts("YES");
  else if (n==2){
     if(a[1]*a[1]-4*a[0]*a[2]>=0)puts("NO");
     else puts("YES");
  }
  else puts("NO");
  return 0;
}