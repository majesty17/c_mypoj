#include <stdio.h>
#include <string.h>
int n;
__int64 mat[512][512];
void handle() {
	int i,j;
	for(i = 0; i <= n; i++)
		memset(mat[i], 0, sizeof(__int64)*512);

	for(i = 1; i <= n; i++)

	{

		mat[0][i] = 1;

		for(j = i/2+1; j <= i; j++)

			mat[i][j] = 1;

	}

	for(i = 2; i <= n; i++ ) {
		for(j = i/2; j > 0; j--)
			mat[i][j] = mat[i-2*j][j] + mat[i][j+1];
	}
	printf("%d %I64d\n",n,mat[n][1]);


}
int main() {
	while(1) {
		scanf("%d",&n);
		if (n==0) break;

		handle();
	}

	return 0;
}
