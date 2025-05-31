#include "../screen.h"
#include "tema.h"
#include "spscreen.h"

void DrawBar(int tema,int color){
	int y = 600 - 40;
	int alt = 40;
	if(tema == NORMAL_TEMA){
		if(color == COLOR_VERDE){
			SetPReact(0,y,800,(alt / 2) / 2, 150,255,150,  0,200,0  );
			SetReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 0,200,0);
			SetReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 0,200,0);
			SetPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 0,200,0, 0,100,00);
		}
		if(color == COLOR_AMARELO){
			SetPReact(0,y,800,(alt / 2) / 2, 255,255,150,  200,200,0  );
			SetReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 200,200,0);
			SetReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 200,200,0);
			SetPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 200,200,0, 100,100,00);
		}
		if(color == COLOR_BRANCO){
			SetPReact(0,y,800,(alt / 2) / 2, 255,255,255,  200,200,200  );
			SetReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 200,200,200);
			SetReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 200,200,200);
			SetPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 200,200,200, 100,100,100);
		}
		if(color == COLOR_AZUL){
			SetPReact(0,y,800,(alt / 2) / 2, 100,255,255,  0,0,200  );
			SetReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 0,0,200);
			SetReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 0,0,200);
			SetPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 0,0,200, 0,0,100);
		}
	} else if(tema == AERO_TEMA){
		if(color == COLOR_VERDE){
			SetTPReact(0,y,800,(alt / 2) / 2, 150,255,150,  0,200,0  ,80);
			SetTReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 0,200,0  ,80);
			SetTReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 0,200,0   ,80);
			SetTPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 0,200,0, 0,100,00  ,80);
		}
		if(color == COLOR_AMARELO){
			SetTPReact(0,y,800,(alt / 2) / 2, 255,255,150,  200,200,0  ,80);
			SetTReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 200,200,0  ,80);
			SetTReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 200,200,0  ,80);
			SetTPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 200,200,0, 100,100,00  ,80);
		}
		if(color == COLOR_BRANCO){
			SetTPReact(0,y,800,(alt / 2) / 2, 255,255,255,  200,200,200  ,80);
			SetTReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 200,200,200  ,80);
			SetTReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 200,200,200  ,80);
			SetTPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 200,200,200, 100,100,100  ,80);
		}
		if(color == COLOR_AZUL){
			SetTPReact(0,y,800,(alt / 2) / 2, 100,255,255,  0,0,200  ,80);
			SetTReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 0,0,200  ,80);
			SetTReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 0,0,200  ,80);
			SetTPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 0,0,200, 0,0,70  ,80);
		}
		if(color == COLOR_PRETO){
			SetTPReact(0,y,800,(alt / 2) / 2, 60,60,60,  30,30,30  ,140);
			SetTReact(0,y+((alt / 2) / 2),800,(alt / 2) / 2, 30,30,30  ,140);
			SetTReact(0,y+((alt / 2) / 2) * 2,800,(alt / 2) / 2, 30,30,30  ,140);
			SetTPReact(0,y+((alt / 2) / 2) * 3,800,((alt / 2) / 2), 30,30,30, 00,00,00  ,140);
		}
	}
}