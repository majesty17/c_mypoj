#include <stdio.h>
int a[8],b[32];
int main(){
	int n,i,sum,t,ans,j,l;
	scanf("%d",&n);
	while(n--)	{
		for(i=0; i<32; i++)b[i]=0;
		for(i=0; i<8; i++)scanf("%x",&a[i]);
		scanf("%x",&sum);
		ans=0;
		for(i=0; i<32; i++)	{
			t=0;
			for(j=0; j<8; j++)t+=(a[j]^0)&1;
			t=(t+ans)&1;
			if(t==(((sum)^0)&1)) b[i]=0;
			else b[i]=1;

			t=0;
			if(b[i]==1)for(j=0; j<8; j++)t+=(a[j]^1)&1;
			else for(j=0; j<8; j++)t+=(a[j]^0)&1;
			for(j=0; j<8; j++)a[j]=a[j]>>1;
			ans=(ans+t)>>1;
			sum=sum>>1;
		}
		ans=0;
		for(i=31; i>=0; i--){
			ans=ans+(b[i]<<i);
		}

		printf("%x\n",ans);
	}
	return 0;
}
