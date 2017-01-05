///这个程序是在已知A99中包含多少个A0，A1，A2的前提下，直接算出A99
///需要构造乘法函数和加法

///从下面这个可以知道，A99中包含A0，A1，A2的个数分别如下：
//1 0 0
//15762679542071167858843489
//0 1 0
//24332675219681431451788241
//0 0 1
//28992087708416717612934417
///所以这个问题最后就成了两个3维向量的内积

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



char *mul(char *des,char *m1,int m2){			//实现功能类似des=m1*m2
	///
	//printf("will calculate %s * %d ...\n",m1,m2);
	///

	int c=0;
	long temp;
	int len=strlen(m1),i;
//	printf("length is %d\n",len);

	for(i=0;i<len;i++){
//		printf("===============\n");
//		printf("c is %d\n",c);
		temp=(m1[i]-'0')*m2+c;
//		printf("temp is %d\n",temp);
		des[i]=temp%10+'0';
		c=temp/10;
//		printf("then, c is %d\n",c);
//		printf("===============\n");
	}

	if(c!=0){
//		printf("c is %d\n",c);
		char t[15];
		itoa(c,t,10);

		strrev(t);
//		printf("%s append to..\n",t);
		strcat(des,t);
	}
	else
		des[i]='\0';
	return des;




}
void sum(char *des,char *s0,char *s1,char *s2){		//实现功能类似des=s0+s1+s2
	///
	//printf("will calculate %s + %s + %s ...\n",s0,s1,s2);
	///


	int len0=strlen(s0);
	int len1=strlen(s1);
	int len2=strlen(s2);
	int maxl=len0>(len1>len2?len1:len2)?len0:(len1>len2?len1:len2);
	//printf("max len is %d\n",maxl);
	int i,temp;
	int c=0;
	for(i=0;i<maxl;i++){
		temp=(s0[i]==0?'0':s0[i])-'0'+(s1[i]==0?'0':s1[i])-'0'+(s2[i]==0?'0':s2[i])-'0'+c;
//		printf("temp=%d\nc=%d\n",temp,c);
		des[i]=temp%10+'0';
		c=temp/10;
	}
	if(c!=0){
		des[i]=c+'0';
		des[i+1]='\0';
	}
	else
		des[i]='\0';
	return;
}

int main(){

//	char b[100]={0,};
//	char x[100]="15762679542071167858843489";
//	strrev(x);
//	short y=12345;
//	mul(b,x,y);
//	printf("%s * %d = %s\n",strrev(x),y,strrev(b));
//	return 0;

//	char b[100]={0,};
//	char x[100]={'1','1','1',0,};
//	char y[100]={'3','3','3','3',0,};
//	char z[100]={'4','4','4','4','4','4',0,};
//	sum(b,x,y,z);
//	printf("%s\n",b);
//	return 0;




	int a0,a1,a2;
	char a[3][100]={	"15762679542071167858843489",
				"24332675219681431451788241",
				"28992087708416717612934417"};
	strrev(a[0]);
	strrev(a[1]);
	strrev(a[2]);


	char de[3][100]={0,};
	char c[100]={0,};
	while(scanf("%d %d %d",&a0,&a1,&a2)!=EOF){
		if(a0<0 || a1<0 || a2<0 || a0>32767 || a1>32767 || a2>32767){
			return -1;
		}
		memset(de[0],0,100);
		memset(de[1],0,100);
		memset(de[2],0,100);
		memset(c,0,100);


		mul(de[0],a[0],a0);
		mul(de[1],a[1],a1);
		mul(de[2],a[2],a2);

		sum(c,de[0],de[1],de[2]);

		printf("%s\n",strrev(c));

	}

	return 0;
}

