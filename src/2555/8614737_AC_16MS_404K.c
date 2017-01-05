#include <stdio.h>
#define CW 4.19
#define CI 2.09
#define EM 335

float mw,mi,tw,ti,tend;		//水量，冰量，水温，冰温
int main(){
	while(1){
		scanf("%f %f %f %f",&mw,&mi,&tw,&ti);
		if(mw==0 && mi==0 && tw==0 && ti==0) break;

		float iceJ=mi*ti*CI;			//J which ice need to be 0 C
		float waterJ=mw*tw*CW;			//J which water could supply
		float chargeJ=iceJ+waterJ;
		if(chargeJ==0){				//水热量等于冰热量，最终都为0度，质量不变
			tend=0.0;
		}
		else if(chargeJ>0){			//水的热量大，冰到了零度，开始融化
			float meltingJ=EM*mi;
			if(chargeJ==meltingJ){				//如果刚好让冰完全融化
				mw+=mi;
				mi=0.0;
				tend=0.0;
			}
			else if(chargeJ>meltingJ){			//化完，开始增温
				mw+=mi;
				mi=0.0;
				tend=(chargeJ-meltingJ)/mw/CW;
			}
			else{							//没化完
				float tem=chargeJ/EM;
				mw+=tem;
				mi-=tem;
				tend=0.0;
			}
		}
		else{						//冰的热量大，水到了零度，开始结冰
			float freezingJ=EM*mw*(-1);
			if(chargeJ==freezingJ){				//如果刚好让水完全结冰
				mi+=mw;
				mw=0.0;
				tend=0.0;
			}
			else if(chargeJ<freezingJ){			//结冰完，开始降温
				mi+=mw;
				mw=0.0;
				tend=(chargeJ-freezingJ)/mi/CI;
			}
			else{							//没接完
				float tem=chargeJ/EM;
				mw+=tem;
				mi-=tem;
				tend=0.0;
			}

		}
		printf("%.1f g of ice and %.1f g of water at %.1f C\n",mi,mw,tend);

	}
	return 0;
}
