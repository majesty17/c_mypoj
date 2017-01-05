#include <stdio.h>
#include <string.h>
char str[101];
char buf[101];
int ifpalindrome(){
	strcpy(buf,str);
	strrev(buf);
	if(strcmp(buf,str)==0) return 1;
	return 0;
}
char change(char a){
	switch (a){
		case 'A':{
			return 'A';
		}
		case 'E':{
			return '3';
		}
		case 'H':{
			return 'H';
		}
		case 'I':{
			return 'I';
		}
		case 'J':{
			return 'L';
		}
		case 'L':{
			return 'J';
		}
		case 'M':{
			return 'M';
		}
		case 'O':{
			return 'O';
		}
		case 'S':{
			return '2';
		}
		case 'T':{
			return 'T';
		}
		case 'U':{
			return 'U';
		}
		case 'V':{
			return 'V';
		}
		case 'W':{
			return 'W';
		}
		case 'X':{
			return 'X';
		}
		case 'Y':{
			return 'Y';
		}
		case 'Z':{
			return '5';
		}
		case '1':{
			return '1';
		}
		case '2':{
			return 'S';
		}
		case '3':{
			return 'E';
		}
		case '5':{
			return 'Z';
		}
		case '8':{
			return '8';
		}
		default:
			return 0;
	}

}
int ifmirror(){
	strcpy(buf,str);
	strrev(buf);

	int i;
	for(i=0;i<strlen(str);i++){
		buf[i]=change(buf[i]);
		if(buf[i]==0)return 0;
	}

	if(strcmp(buf,str)==0) return 1;
	return 0;
}
int main(){
	while(scanf("%s",&str)!=EOF){
		switch(ifpalindrome()*2+ifmirror()){
			case 0:{
				printf("%s -- is not a palindrome.\n\n",str);
				break;
			}
			case 1:{
				printf("%s -- is a mirrored string.\n\n",str);
				break;
			}
			case 2:{
				printf("%s -- is a regular palindrome.\n\n",str);
				break;
			}
			case 3:{
				printf("%s -- is a mirrored palindrome.\n\n",str);
				break;
			}
		}
	}
	return 0;
}
