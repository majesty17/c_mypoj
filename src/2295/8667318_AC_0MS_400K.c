#include <stdio.h>
#include <string.h>
#include <math.h>
int c;
int a1,b1,a2,b2;
char str[261];
char left[150];
char right[150];
char buff[10];
int main(){
	int i;
	scanf("%d",&c);
	while(c--){
		scanf("%s",&str);
		char *q=strchr(str,'=');
		memset(left,0,150);
		memset(right,0,150);
		strncpy(left,str,q-str);
		strcpy(right,q+1);

		a1=0;b1=0;a2=0;b2=0;
//		printf("%s,%s\n",left,right);
		char *p_plus,*p_minus,*p;
		int sign=1;
		int num;
		for(i=0;i<strlen(left);i++){
			num=0;
			memset(buff,0,10);
			p_plus=strchr(left+i,'+');
			p_minus=strchr(left+i,'-');
			if(p_plus==NULL && p_minus==NULL){
				strcpy(buff,left+i);
				i=strlen(left);
				sscanf(buff,"%d",&num);
				if(num==0)num=1;
				if(strchr(buff,'x')==NULL){
					b1+=num*sign;
				}
				else{
					a1+=num*sign;
				}
			}
			else if(p_plus==NULL){
				memcpy(buff,left+i,p_minus-left-i);
				sscanf(buff,"%d",&num);
				if(num==0)num=1;
				if(strchr(buff,'x')==NULL){
					b1+=num*sign;
				}
				else{
					a1+=num*sign;
				}
				sign=-1;
				i+=p_minus-left-i;
			}
			else if(p_minus==NULL){
				memcpy(buff,left+i,p_plus-left-i);
				sscanf(buff,"%d",&num);
				if(num==0)num=1;
				if(strchr(buff,'x')==NULL){
					b1+=num*sign;
				}
				else{
					a1+=num*sign;
				}
				sign=1;
				i+=p_plus-left-i;
			}
			else{
				if(p_plus<p_minus){
					p=p_plus;
					memcpy(buff,left+i,p-left-i);
					sscanf(buff,"%d",&num);
					if(num==0)num=1;
					i+=p-left-i;
					if(strchr(buff,'x')==NULL){
						b1+=num*sign;
					}
					else{
						a1+=num*sign;
					}
					sign=1;
				}
				else{
					p=p_minus;
					memcpy(buff,left+i,p-left-i);
					sscanf(buff,"%d",&num);
					if(num==0)num=1;
					i+=p-left-i;
					if(strchr(buff,'x')==NULL){
						b1+=num*sign;
					}
					else{
						a1+=num*sign;
					}
					sign=1;
					p=p_minus;
					sign=-1;
				}

			}


//			printf("buff is <%s>\n",buff);
		}
		sign=1;
		for(i=0;i<strlen(right);i++){
			num=0;
			memset(buff,0,10);
			p_plus=strchr(right+i,'+');
			p_minus=strchr(right+i,'-');
			if(p_plus==NULL && p_minus==NULL){
				strcpy(buff,right+i);
				i=strlen(right);
				sscanf(buff,"%d",&num);
				if(num==0)num=1;
				if(strchr(buff,'x')==NULL){
					b2+=num*sign;
				}
				else{
					a2+=num*sign;
				}
			}
			else if(p_plus==NULL){
				memcpy(buff,right+i,p_minus-right-i);
				sscanf(buff,"%d",&num);
				if(num==0)num=1;
				if(strchr(buff,'x')==NULL){
					b2+=num*sign;
				}
				else{
					a2+=num*sign;
				}
				sign=-1;
				i+=p_minus-right-i;
			}
			else if(p_minus==NULL){
				memcpy(buff,right+i,p_plus-right-i);
				sscanf(buff,"%d",&num);
				if(num==0)num=1;
				if(strchr(buff,'x')==NULL){
					b2+=num*sign;
				}
				else{
					a2+=num*sign;
				}
				sign=1;
				i+=p_plus-right-i;
			}
			else{
				if(p_plus<p_minus){
					p=p_plus;
					memcpy(buff,right+i,p-right-i);
					sscanf(buff,"%d",&num);
					if(num==0)num=1;
					i+=p-right-i;
					if(strchr(buff,'x')==NULL){
						b2+=num*sign;
					}
					else{
						a2+=num*sign;
					}
					sign=1;
				}
				else{
					p=p_minus;
					memcpy(buff,right+i,p-right-i);
					sscanf(buff,"%d",&num);
					if(num==0)num=1;
					i+=p-right-i;
					if(strchr(buff,'x')==NULL){
						b2+=num*sign;
					}
					else{
						a2+=num*sign;
					}
					sign=1;
					p=p_minus;
					sign=-1;
				}

			}


//			printf("buff is <%s>\n",buff);
		}

//		printf("xishu is : %d %d %d %d\n",a1,b1,a2,b2);


		if(a1==a2){
			if(b1==b2) printf("IDENTITY\n");
			else printf("IMPOSSIBLE\n");
		}
		else{
			double res=(double)(b1-b2)/(double)(a2-a1);
			//int ret;
			//if(res>=0) ret=(int)floor(res);
			//else ret=floor(res)+1;
			printf("%d\n",(int)floor(res));
		}




	}
	return 0;
}
