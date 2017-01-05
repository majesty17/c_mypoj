#include <stdio.h>
#include <stdlib.h>

char *HaabMonth[]={
	"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
	"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char *TzolkinDay[]={
	"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
	"chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
typedef struct{
 	int day;
 	char *month;
 	int year;
 	}Haab,*pHaab;

void toTzolkin(pHaab ph){
	//printf("%d. %s %d\n",ph->day,ph->month,ph->year);
	int i,mon,days;
	for(i=0;i<20;i++){
		if(strcmp(HaabMonth[i],ph->month)==0){
			mon=i+1;
			break;
		}
	}
	days=ph->year*365+ph->day+(mon-1)*20;
	//printf("%d\n",days);


	printf("%d %s %d\n",days%260%13+1,TzolkinDay[days%20],days/260);
}
int main(){

	int n,i;
	scanf("%d",&n);

	Haab *ha=(Haab*)malloc(sizeof(Haab)*n);


	for(i=0;i<n;i++){
		ha[i].month=(char*)malloc(sizeof(char)*10);
		scanf("%d. %s %d",&(ha[i].day),ha[i].month,&(ha[i].year));
		//printf("%d. %s %d\n",ha[i].day,ha[i].month,ha[i].year);
	}
	//printf("%s\n",TzolkinDay[4]);
	printf("%d\n",n);
	for(i=0;i<n;i++){

		toTzolkin(ha+i);
	}
}
