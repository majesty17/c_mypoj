#include <stdio.h>
#include <string.h>
int n;
char str[1001][1001];
int main(){
	int i,j,len;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%s",&str[i]);
		}
		len=strlen(str[0]);

		for(i=len-1;i>=0;i--){
			for(j=n-1;j>=0;j--){
				switch (str[j][i]){
					case '_':{
						printf(" ");
						break;
					}
					case '\\':{
						printf("\n");
						break;
					}
					default:
						printf("%c",str[j][i]);
						break;
				}

			}
		}

		printf("\n\n");

	}
	return 0;
}
