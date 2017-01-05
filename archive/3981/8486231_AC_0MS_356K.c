#include <stdio.h>
#include <string.h>
char a[10000];
char b[1000];
void change(){
	int i;
	int l=strlen(a);
	memset(b,0,1000);
	for(i=0;i<l;i++){
		if(i<l-2 && a[i]=='y' && a[i+1]=='o' && a[i+2]=='u'){
			strcat(b,"we");
//			printf("we");
			i+=3;
		}
		b[strlen(b)]=a[i];

		//printf("%c",a[i]);
	}
	printf("%s\n",b);
}
int main(){

	while(gets(a)!=NULL){
		if(strlen(a)>1000){
			break;
		}

		//printf("%s\n",a);
		change();
	}

}
