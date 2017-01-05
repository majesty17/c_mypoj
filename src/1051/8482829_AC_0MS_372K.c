#include <stdio.h>
#include <string.h>


//A 	.- 		H 	.... 	O 	--- 	V 	...-
//B 	-... 	I 	.. 		P 	.--. 	W 	.--
//C 	-.-. 	J 	.--- 	Q 	--.- 	X 	-..-
//D 	-.. 	K 	-.- 	R 	.-. 	Y 	-.--
//E 	. 		L 	.-.. 	S 	... 	Z 	--..
//F 	..-. 	M 	-- 		T 	- 	　 	　
//G 	--. 	N 	-. 		U 	..- 	　 	　

//underscore 	..-- 	period 	---.
//comma 	.-.- 	question mark 	----

char num[100]={0,};			//each code length
char str[100]={0,};			//source string
char code[400]={0,};		//morse code
char *morse[]={"",
	".-",	"-...",	"-.-.",	"-..",	".",	"..-.",	"--.",
	"....",	"..",	".---",	"-.-",	".-..",	"--",	"-.",
	"---",	".--.",	"--.-",	".-.",	"...",	"-",
	"..-",	"...-",	".--",	"-..-",	"-.--",	"--..",
	"..--",	"---.",	".-.-",	"----"
};

char *getMorse(char c){						//get a Morse of a char
	if(c>='A' && c<='Z') return morse[c-64];
	else if(c=='_') return morse[27];
	else if(c=='.') return morse[28];
	else if(c==',') return morse[29];
	else if(c=='?') return morse[30];
	else return 0;
}
void getStr(int l){					//change a sting to Morse code
	int i;
	for(i=0;i<l;i++){
		char *t=getMorse(str[i]);
		strcat(code,t);
		num[i]=strlen(t);
		//printf("%d",num[i]);

	}
}
char getCByMorse(char *t){
	int i;
	for(i=1;i<=30;i++){
		if(strcmp(t,morse[i])==0){
			if(i<=26) return i+64;
			else if(i==27) return '_';
			else if(i==28) return '.';
			else if(i==29) return ',';
			else if(i==30) return '?';
		}
	}

}
void deCode(){							//decode and output
	int l=strlen(str);
	int i;
	int step;
	char tem[5];
	char *p=code;
	for(i=0;i<l;i++){
		step=num[l-i-1];
		memset(tem,0,5);
		memcpy((void*)tem,(void*)p,step);
		p+=step;
		printf("%c",getCByMorse(tem));
	}
	printf("\n");

}





int main(){
	int n,i;
	scanf("%d",&n);

	for(i=0;i<n;i++){


		//printf("%d\n",i);
		scanf("%s",str);
		//printf("%s\n",str);
		memset(code,0,400);
		getStr(strlen(str));
		//printf("%s\n",code);

		printf("%d: ",i+1);
		deCode();

	}


	return 0;
}
