#include <stdio.h>
float speed;
int weight,strength;

int main(){
	while(1){
		scanf("%f %d %d",&speed,&weight,&strength);
		if(speed==0 && weight==0 &&strength==0) break;

		int sign=0;
		if(speed<=4.5 && weight>=150 && strength>=200) {printf("Wide Receiver ");sign=1;}
		if(speed<=6.0 && weight>=300 && strength>=500) {printf("Lineman ");sign=1;}
		if(speed<=5.0 && weight>=200 && strength>=300) {printf("Quarterback ");sign=1;}



		if(speed>6.0 || weight<150 || strength<200 || sign==0) printf("No positions ");


		printf("\n");





	}
	return 0;
}
