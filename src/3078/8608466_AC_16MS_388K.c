#include <stdio.h>
int cases,m,n;
char item[20][10];
int a[21],b[21];
int main(){
	int i,tem1,tem2;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d %d\n",&m,&n);

		memset(a,0,sizeof(int)*21);
		memset(b,0,sizeof(int)*21);

		for(i=0;i<m;i++){
			scanf("%s",&item[i]);

		}

		for(i=0;i<n;i++){
			scanf("%d %d",&tem1,&tem2);
			a[tem2]=tem1;
			b[tem1]=1;
		}

//		for(i=1;i<=m;i++){
//			printf("a[] is %d\n",a[i]);
//		}

		for(i=1;i<=m;i++){
			if(b[i]==1) continue;
			int j=1;
			while(a[j]!=0) j++;
			a[j]=i;
		}

		for(i=1;i<=m;i++){
			printf("%s ",item[a[i]-1]);
		}
		printf("\n");
	}
	return 0;
}
