#include<stdio.h>
#include<string.h>
int main()
{
       int n,i,j,k,m,max,s[101];
       int a[101][101];
       while(scanf("%d",&n)!=EOF)
       {
           for(i=0;i<n;i++)
           {
               for(j=0;j<n;j++)
               {
                   scanf("%d",&a[i][j]);
               }
           }
           max=0;
           for(i=0;i<n;i++)
           {
               memset(s,0,sizeof(s));
               for(j=i;j<n;j++)
               {
                   m=0;
                   for(k=0;k<n;k++)
                   {
                       s[k]+=a[j][k];
                       if(m>0)
                       {
                           m+=s[k];
                       }
                       else
                       {
                           m=s[k];
                       }
                       if(m>max)
                       {
                           max=m;
                       }
                   }
               }
           }
           printf("%d\n",max);
       }
}