#include <stdio.h>
int n;
int main(){
	int i,o,p,q,i3,o3,p3,q3;
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		i3=i*i*i;
		for(o=2;o<=n-2;o++){
			o3=o*o*o;
			for(p=o+1;p<=n-1;p++){
				p3=p*p*p;
				for(q=p+1;q<=n;q++){
					q3=q*q*q;
					if(i3==o3+p3+q3){
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,o,p,q);
						//goto HERE;
					}


				}
			}
		}

HERE:
	continue;


	}


	return 0;
}
