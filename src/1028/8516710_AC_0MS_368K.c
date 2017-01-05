#include <stdio.h>
#include <string.h>

///stack
typedef struct{
	char a[100][70];
	int pos;
}stack,*pstack;
void initStack(stack *st){
	st->pos=0;
}
int isEmpty(stack *st){
	return st->pos;
}
void push(stack *st,char *str){
	if(str[0]=='\0') return;
	strcpy(st->a[st->pos],str);
	st->pos++;
}
char *pop(stack *st){
	if(isEmpty(st)==0) return NULL;
	st->pos--;
	return st->a[st->pos];
}
void clear(stack *st){
	st->pos=0;
}
///stack

char cmd[10]={0,};
char cur_url[75]={0,};

int main(){
	stack st_for;
	stack st_back;
	initStack(&st_for);
	initStack(&st_back);
	strcpy(cur_url,"http://www.acm.org/");

//	push(&st_back,cur_url);

//	push(&st_for,"hello1");
//	push(&st_for,"hello2");
//	push(&st_for,"hello3");
//	printf("%s\n",pop(&st_for));
//	printf("%d\n",isEmpty(&st_for));
//
//	printf("%s\n",pop(&st_for));
//	printf("%d\n",isEmpty(&st_for));
//
//	printf("%s\n",pop(&st_for));
//	printf("%d\n",isEmpty(&st_for));
//	return 0;
	while(1){
		scanf("%s",&cmd);
		switch(cmd[0]){
			case 'V':{								//gonna vista a page

				push(&st_back,cur_url);
				clear(&st_for);
				scanf("%s",&cur_url);				//get a new url
				printf("%s\n",cur_url);
				break;
			}
			case 'B':{								//gonna backward

				if(isEmpty(&st_back)==0){
					printf("Ignored\n");
				}else{
					push(&st_for,cur_url);
					strcpy(cur_url,pop(&st_back));
					printf("%s\n",cur_url);
				}
				break;
			}
			case 'F':{								//gonna forward

				if(isEmpty(&st_for)==0){
					printf("Ignored\n");
				}else{
					push(&st_back,cur_url);
					strcpy(cur_url,pop(&st_for));
					printf("%s\n",cur_url);
				}
				break;
			}
			case 'Q':{								//gonna quit
				return ;
			}
		}


	}



	return 0;
}
