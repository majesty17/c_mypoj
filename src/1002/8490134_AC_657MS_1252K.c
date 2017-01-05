	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	char map[] = "22233344455566677778889999";
	char str[80], telNumbers[100000][9];

	int compare(const void *elem1,const void *elem2) {
	//为函数模板sort 定义数组元素的比较函数
	 return (strcmp((char*)elem1, (char*)elem2));
	};

	void standardizeTel(int n) {
	 int j, k;

	 j = k = -1 ;
 while ( k<8 ) {
 j++;
if ( str[j] == '-' )
 continue;
	k++;
	 if (k==3) {
	telNumbers[n][k]='-';
	 k++;
	 }
	 if(str[j]>='A' && str[j]<='Z') {
	telNumbers[n][k]=map[str[j]-'A'];
	continue;
	 };
	 telNumbers[n][k]=str[j];
	}
	 telNumbers[n][k]='\0';
	 return;
	}

	void main()
	{
	int n,i,j;
	int noduplicate;

	scanf("%d",&n);
	for(i=0;i<n;i++){//输入电话号码，存储到数组telNumbers 中
	scanf("%s",str);

	 standardizeTel(i);
	 //将str 中的电话号码转换成标准形式，存储在telNumbers 的第i 行
	 }

	 qsort(telNumbers,n,9,compare);//对输入的电话号码进行排序

	noduplicate = 1;
	i=0;
	while(i<n){//搜索重复的电话号码，并进行输出
	j=i;
	i++;
	while(i<n&&strcmp(telNumbers[i], telNumbers[j])==0) i++;
	if(i-j>1) {
	printf("%s %d\n", telNumbers[j], i-j);
	noduplicate = 0;
	}
	}
	if ( noduplicate )
	printf("No duplicates.\n");

}
