#include <stdio.h>
#include <string.h>
char str[20];
char c[83682][6]={{},
	{"a"},{"b"},{"c"},{"d"},{"e"},{"f"},{"g"},
	{"h"},{"i"},{"j"},{"k"},{"l"},{"m"},{"n"},
	{"o"},{"p"},{"q"},{"r"},{"s"},{"t"},
	{"u"},{"v"},{"w"},{"x"},{"y"},{"z"},
};
int n=27;
char t[6];
int cmp(const void *a,const void *b){
	return *(char*)a-*(char*)b;
}
void f2()
{
	int i,j;
	for(i='a';i<='z';i++)
	{
		for(j=i+1;j<='z';j++)
		{
			t[0]=i;
			t[1]=j;
			strcpy(c[n++],t);
		}

	}
}
void f3()
{
	int i,j,k;
	for(i='a';i<='z';i++)
	{
		for(j=i+1;j<='z';j++)
		{
			for(k=j+1;k<='z';k++)
			{
				t[0]=i;t[1]=j;t[2]=k;strcpy(c[n++],t);
			}
		}
	}
}
void f4()
{
	int i,j,k,l;
	for(i='a';i<='z';i++)
	{
		for(j=i+1;j<='z';j++)
		{
			for(k=j+1;k<='z';k++)
			{
				for(l=k+1;l<='z';l++)
				{
					t[0]=i;t[1]=j;t[2]=k;t[3]=l;strcpy(c[n++],t);
				}
			}
		}
	}
}
void f5()
{
	int i,j,k,l,m;
	for(i='a';i<='z';i++)
	{
		for(j=i+1;j<='z';j++)
		{
			for(k=j+1;k<='z';k++)
			{
				for(l=k+1;l<='z';l++)
				{
					for(m=l+1;m<='z';m++)
					{
						t[0]=i;t[1]=j;t[2]=k;t[3]=l;t[4]=m;strcpy(c[n++],t);
					}
				}
			}
		}
	}
}

int main(){
	int i;
	f2();f3();f4();f5();
	char buf[20];
	while(scanf("%s",&str)!=EOF){
		int len=strlen(str);
		if(len==1){
			printf("%d\n",str[0]-'a'+1);
			continue;
		}
		strcpy(buf,str);
		qsort(buf,len,1,cmp);
//		printf("%s\n",buf);
		if(strcmp(buf,str)!=0) {
			printf("0\n");
			continue;
		}
		for(i=1;i<=83681;i++)
		{
			if(strcmp(str,c[i])==0)
			{
				printf("%d\n",i);
				break;
			}
		}



	}
	return 0;
}
