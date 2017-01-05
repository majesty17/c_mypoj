#include <stdio.h>
#include <string.h>

char map[28]={'_'	,'a','b','c','d','e','f','g'
					,'h','i','j','k','l','m','n'
					,'o','p','q','r','s','t'
					,'u','v','w','x','y','z'
					,'.'};
int charToInt(char a){
	if(a>='a' && a<='z') return a-'a'+1;
	if(a=='.') return 27;
	if(a=='_') return 0;
}


int k;		//0~300
char a[71];
char b[71];


int main(){
	int i,n;
	while(1){
		scanf("%d",&k);
		if(k==0) break;
		scanf("%s",&a);
		memset(b,0,100);
		n=strlen(a);
		for(i=0;i<n;i++){
			int ciphercode=charToInt(a[i]);
			b[(k*i+n)%n]=map[(ciphercode+i+28)%28];

	//		printf("%d\n",(k*i+n)%n);


		}
		printf("%s\n",b);


//		printf("\n");

	}
	return 0;
}
