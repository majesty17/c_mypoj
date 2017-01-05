#include <stdio.h>
#include <string.h>

int power;			//store power
char a[10];			//store lower num
char wholerus[150];

int powxy(int x,int y){
	int ret=1;
	while(y--){
		ret*=x;
	}
	return ret;
}
void mul(int lo){							//wholerus*=lower
	int len=strlen(wholerus);
	int c=0,i,temp;

	for(i=0;i<len;i++){
		temp=(wholerus[i]-'0')*lo+c;
		wholerus[i]=temp%10+'0';
		c=temp/10;
	}
	if(c!=0){
		char buf[10];
		itoa(c,buf,10);
		strcat(wholerus,strrev(buf));
	}
}
void myPower(int lower){					//wholerus=lower^power
	int i=power;
	while(i--){
		mul(lower);
	}
}

void handle(){
	int point=a+strlen(a)-strchr(a,'.')-1;		//找到小数位数
	int inter;
	int dec;
	sscanf(a,"%d.%d",&inter,&dec);				//分离整数小数部分
	int whole=inter*powxy(10,point)+dec;			//组合成一个整数

	strcpy(wholerus,"1");						//初始化wholerus
	myPower(whole);								//求whole的power次方

	int de=point*power;					//小数点后总位数
	int i;
	int len=strlen(wholerus);
//	printf("len is %d,de is %d\n",len,de);

	if(len<=de){
		for(i=len;i<de;i++){
			wholerus[i]='0';
		}
		wholerus[de]='.';
		wholerus[de+1]='\0';

	}
	else{
		wholerus[len+1]=0;

		for(i=len;i>de;i--){
			wholerus[i]=wholerus[i-1];
		}
		wholerus[de]='.';

	}
	char *p=wholerus;
	for(i=0;i<strlen(wholerus);i++){
		if(wholerus[i]=='0'){
			p++;
		}else{
			break;
		}
	}
	if(*p=='.') p++;
	printf("%s\n",strrev(p));







}
int main(){

//	sprintf(wholerus,"123456");
//	mul(9);
//	printf("%s\n",wholerus);
//	return 0;




	while(scanf("%s %d",&a,&power)!=EOF){
		handle();

	}
	return 0;
}
