#include <stdio.h>
float pre,cur;
int main(){
	scanf("%f",&cur);

	while(1){
		pre=cur;
		scanf("%f",&cur);
		if(cur==999) {
			printf("End of Output\n");
			break;
		}
		printf("%.2f\n",cur-pre);


	}
	return 0;
}
