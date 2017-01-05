#include <stdio.h>
#include <math.h>
int main(){
    int i,n;
    double VR,VS,R,C,w;
    scanf("%lf%lf%lf%d",&VS,&R,&C,&n);
    for (i=0;i<n; i++){
        scanf("%lf",&w);
        VR=C*R*w*VS / sqrt(1.0+C*C*R*R*w*w);
        printf("%.3f\n",VR);
    }
    return 0;
}
