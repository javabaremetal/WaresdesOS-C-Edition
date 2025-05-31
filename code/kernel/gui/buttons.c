#include "../screen.h"
#include "tema.h"
#include "buttons.h"
#include "spscreen.h"
extern int MouseX;
extern int MouseY;
extern int MouseBTNClick;
extern int tema;

int MouseIn(int x,int y,int lar,int alt){
	if(MouseX <= lar + x){
		if(MouseY <= alt + y){
			if(MouseX >= x){
				if(MouseY >= y){
					return 1;
				}
			}
		}
	}
	return 0;
}


int DrawButton(int x,int y,int lar,int alt,int color){
	if(alt < 11)return -1;
	/*if(tema == AERO_TEMA){
		if(color == BTN_COLOR_BRANCO){
			if(MouseIn(x,y,lar,alt) == 0){
				SetReact(x,y,lar,alt,143,143,143);
				SetReact(x+1,y+1,lar-2,alt-2,200,200,200);
				SetReact(x+1,y+1,lar-2,alt-2,220,220,220);
				SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,200,200,200);
				return 0;
			}else{
				if(MouseBTNClick == 0){
					SetReact(x,y,lar,alt,43,43,153);
					SetReact(x+1,y+1,lar-2,alt-2,180,180,200);
					SetReact(x+1,y+1,lar-2,alt-2,180,180,250);
					SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,160,160,255);
					return 1;
				} else {
					SetReact(x,y,lar,alt,43,43,153);
					SetReact(x+1,y+1,lar-2,alt-2,100,100,200);
					SetReact(x+1,y+1,lar-2,alt-2,130,130,250);
					SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,110,110,255);
					return 2;
				}
			}
		} else if(color == BTN_COLOR_VERDE){
			if(MouseIn(x,y,lar,alt) == 0){
				SetReact(x,y,lar,alt,0,163,0);
				SetReact(x+1,y+1,lar-2,alt-2,200,200,200);
				SetReact(x+1,y+1,lar-2,alt-2,150,255,150);
				SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,88,255,88);
				return 0;
			}else{
				if(MouseBTNClick == 0){
					SetReact(x,y,lar,alt,43,43,153);
					SetReact(x+1,y+1,lar-2,alt-2,180,180,200);
					SetReact(x+1,y+1,lar-2,alt-2,180,180,250);
					SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,160,160,255);
					return 1;
				} else {
					SetReact(x,y,lar,alt,43,43,153);
					SetReact(x+1,y+1,lar-2,alt-2,100,100,200);
					SetReact(x+1,y+1,lar-2,alt-2,130,130,250);
					SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,110,110,255);
					return 2;
				}
			}
		} else {
			if(MouseIn(x,y,lar,alt) == 0){
				SetReact(x,y,lar,alt,143,143,143);
				SetReact(x+1,y+1,lar-2,alt-2,200,200,200);
				SetReact(x+1,y+1,lar-2,alt-2,220,220,220);
				SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,200,200,200);
				return 0;
			}else{
				if(MouseBTNClick == 0){
					SetReact(x,y,lar,alt,43,43,153);
					SetReact(x+1,y+1,lar-2,alt-2,180,180,200);
					SetReact(x+1,y+1,lar-2,alt-2,180,180,250);
					SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,160,160,255);
					return 1;
				} else {
					SetReact(x,y,lar,alt,43,43,153);
					SetReact(x+1,y+1,lar-2,alt-2,100,100,200);
					SetReact(x+1,y+1,lar-2,alt-2,130,130,250);
					SetReact(x+2,y + ((alt) / 2),lar-4,(alt / 2)-1,110,110,255);
					return 2;
				}
			}
		}
	}*/
	if(color == BTN_COLOR_VERDE){
		if(MouseIn(x,y,lar,alt)){
			if(MouseBTNClick == 1){
				SetReact(x,y,lar,alt, 0,0,0);
				SetPReact(x+1,y+1,lar-2,(alt / 2) / 2,  0,40,0, 0,150,0 ); //, 190,250,190,  0,200,0  );
				SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 0,150,0);
				SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 0,150,0);
				SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 0,150,0, 150,255,150);
				
				return 2;
			} else {
				SetReact(x,y,lar,alt, 0,0,0);
				SetPReact(x+1,y+1,lar-2,(alt / 2) / 2, 150,255,150,  0,200,0  );
				SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 0,200,0);
				SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 0,200,0);
				SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 0,200,0, 00,100,00);
				return 1;
			}
		}else{
			SetReact(x,y,lar,alt, 0,0,0);
			SetPReact(x+1,y+1,lar-2,(alt / 2) / 2, 150,255,150,  0,200,0  );
			SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 0,200,0);
			SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 0,200,0);
			SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 0,200,0, 00,100,00);
			
			return 0;
		}
		
	} else if(color == BTN_COLOR_BRANCO){
		if(MouseIn(x,y,lar,alt)){
			if(MouseBTNClick == 1){
				SetReact(x,y,lar,alt, 0,0,0);
				SetPReact(x+1,y+1,lar-2,(alt / 2) / 2, 0x4F,0x4F,0x4F,/*0xFF,0xFF,0xFF,*/  150,150,150  );
				SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 150,150,150);
				SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 150,150,150);
				SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 150,150,150, /*0x4F,0x4F,0x4F*/200,200,200);
				return 2;
			} else {
				SetReact(x,y,lar,alt, 0,0,0);
				SetPReact(x+1,y+1,lar-2,(alt / 2) / 2, 0xFF,0xFF,0xFF,  200,200,200  );
				SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 200,200,200);
				SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 200,200,200);
				SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 200,200,200, 0x4F,0x4F,0x4F);
				
				return 1;
			}
		}else{
			SetReact(x,y,lar,alt, 0,0,0);
			SetPReact(x+1,y+1,lar-2,(alt / 2) / 2, 0xFF,0xFF,0xFF,  200,200,200  );
			SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 200,200,200);
			SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 200,200,200);
			SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 200,200,200, 0x4F,0x4F,0x4F);
			return 0;
		}
	} else if(color == BTN_COLOR_AZUL){
		if(MouseIn(x,y,lar,alt)){
			if(MouseBTNClick == 1){
				SetReact(x,y,lar,alt, 0,0,0);
				SetPReact(x+1,y+1,lar-2,(alt / 2) / 2,  0,0,40, 0,0,150 ); //, 190,250,190,  0,200,0  );
				SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 0,0,150);
				SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 0,0,150);
				SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 0,0,150, 150,150,255);
				
				return 2;
			} else {
				SetReact(x,y,lar,alt, 0,0,0);
				SetPReact(x+1,y+1,lar-2,(alt / 2) / 2, 150,150,255,  0,0,200  );
				SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 0,0,200);
				SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 0,0,200);
				SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 0,0,200, 00,00,100);
				return 1;
			}
		}else{
			SetReact(x,y,lar,alt, 0,0,0);
			SetPReact(x+1,y+1,lar-2,(alt / 2) / 2, 150,150,255,  0,0,200  );
			SetReact(x+1,y+1+((alt / 2) / 2),lar-2,(alt / 2) / 2, 0,0,200);
			SetReact(x+1,y+1+((alt / 2) / 2) * 2,lar-2,(alt / 2) / 2, 0,0,200);
			SetPReact(x+1,y+1+((alt / 2) / 2) * 3,lar-2,((alt / 2) / 2)-1, 0,0,200, 00,00,100);
			return 0;
		}
	}
	return -1462;	
}