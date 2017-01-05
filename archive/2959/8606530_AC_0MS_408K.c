#include <stdio.h>
#define PI 3.14159
int n;
float D,d,s;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%f %f %f",&D,&d,&s);
		printf("%d\n",(int)(PI/( asin((d+s)/(D-d))  ) ) );
	}
	return 0;
}
