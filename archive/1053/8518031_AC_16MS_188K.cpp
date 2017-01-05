#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

char ss[13][5];

int main()
{
    int i,j,k,num;
    set<char>tmp[4];
    while(scanf("%s",ss[0])!=EOF)
    {
        for(i=1;i<12;i++)
            scanf("%s",ss[i]);
        printf("CARDS: ");
        for(i=0;i<12;i++)
           printf(" %s",ss[i]);
        printf("\n");
        num=0;
        for(i=0;i<12;i++)
         for(j=i+1;j<12;j++)
          for(k=j+1;k<12;k++)
          {
              tmp[0].insert(ss[i][0]);                                                                                        //将3个字符串的第1列元素插入到编号为0的set容器中
              tmp[0].insert(ss[j][0]);
              tmp[0].insert(ss[k][0]);
              tmp[1].insert(ss[i][1]);
              tmp[1].insert(ss[j][1]);
              tmp[1].insert(ss[k][1]);
              tmp[2].insert(ss[i][2]);
              tmp[2].insert(ss[j][2]);
              tmp[2].insert(ss[k][2]);
              tmp[3].insert(ss[i][3]);
              tmp[3].insert(ss[j][3]);
              tmp[3].insert(ss[k][3]);
              if((tmp[0].size()==1||tmp[0].size()==3)&&(tmp[1].size()==1||tmp[1].size()==3)&&(tmp[2].size()==1||tmp[2].size()==3)&&(tmp[3].size()==1||tmp[3].size()==3))
              {
                  num++;
                  if(num==1)
                     printf("SETS:   1. %s %s %s\n",ss[i],ss[j],ss[k]);
                  else
                     printf("        %d. %s %s %s\n",num,ss[i],ss[j],ss[k]);
              }
              tmp[0].clear();
              tmp[1].clear();
              tmp[2].clear();
              tmp[3].clear();
          }
        if(num==0)
           printf("SETS:   *** None Found ***\n");
        printf("\n");
    }
    system("pause");
    return 0;
}