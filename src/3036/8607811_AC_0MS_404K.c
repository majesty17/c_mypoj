#include <stdio.h>
#define depth 17

int way[15][depth][depth];
int list[15];
int stepNum;

void print_list() {
	int i,j,k;
	way[0][8][8] = 1;
	for(k = 1; k <= 14; k++) {
		for(i = 1; i < depth; i++ ) {
			for (j = 1; j < depth; j++ ) {
				way[k][i][j] = way[k-1][i][j+1]+way[k-1][i][j-1]
							   +way[k-1][i+1][j]+way[k-1][i-1][j]
							   +way[k-1][i+1][j-1]+way[k-1][i-1][j+1];
			}
		}
		list[k] = way[k][8][8];
	}
}

int main() {
	int caseNum;

	print_list();
	scanf("%d",&caseNum);
	while(caseNum--){
		scanf("%d",&stepNum);//cin >> stepNum;
		printf("%d\n",list[stepNum]);//cout << list[stepNum] << endl;
	}
	return 0;
}
