#include "../string.h"
#include "../../waresdes.h"
#include "../../i386.h"
#include "../../drivers/disk.h"
#include "../spscreen.h"
#include "../../screen.h"
/*





#include "types.h"
#include "waresdes.h"

#define __SCREEN__
#include "screen.h"

char VRAM1[800*600*4];
char VRAM2[800*600*4];
extern multiboot_info_t *mbi;

void SetPixel(int x, int y, char R, char G, char B) {
    if (x >= 0 && x < 800 && y >= 0 && y < 600) {
        int offset = (y * 800 + x) * 4;
        VRAM1[offset + 0] = B; // BGRA
        VRAM1[offset + 1] = G;
        VRAM1[offset + 2] = R;
        VRAM1[offset + 3] = 0;
    }
}
	
void SetReact(int x, int y, int lar, int alt, char R, char G, char B) {
    // Verifica se está completamente fora da tela (nem tenta desenhar)
    if (x >= 800 || y >= 600 || x + lar <= 0 || y + alt <= 0)
        return;

    uint32_t color = (B << 8) | (G << 8) | (R << 8) | (0 << 8);  // 0xBBGGRR00
    uint32_t *vram = (uint32_t *) VRAM1;

    int start_y = y < 0 ? 0 : y;
    int end_y = (y + alt > 600) ? 600 : y + alt;
    int start_x = x < 0 ? 0 : x;
    int end_x = (x + lar > 800) ? 800 : x + lar;

    for (int tmp_y = start_y; tmp_y < end_y; tmp_y++) {
        int row_offset = tmp_y * 800;
        for (int tmp_x = start_x; tmp_x < end_x; tmp_x++) {
            vram[row_offset + tmp_x] = color;
        }
    }
}

void SetBITMAP(u8 *BITMAP__D__, int x, int y) {
    int lar_BITMAP = BITMAP__D__[0];
    int alt_BITMAP = BITMAP__D__[1];
    int index = 2;

    for (int y_tmp = 0; y_tmp < alt_BITMAP; y_tmp++) {
        int draw_y = y + y_tmp;
        if (draw_y < 0 || draw_y >= 600) {
            index += lar_BITMAP * 3;
            continue;
        }

        for (int x_tmp = 0; x_tmp < lar_BITMAP; x_tmp++) {
            int draw_x = x + x_tmp;
            char R = BITMAP__D__[index++];
            char G = BITMAP__D__[index++];
            char B = BITMAP__D__[index++];

            // Skip transparent pixels (R=G=B=0)
            if ((R | G | B) == 0) continue;

            if (draw_x >= 0 && draw_x < 800) {
                uint32_t color = (B << 16) | (G << 8) | (R << 8) | (0 << 8);
                ((uint32_t*)VRAM1)[draw_y * 800 + draw_x] = color;
            }
        }
    }
}


void clear(char R, char G, char B) {
    uint32_t color = (B << 16) | (G << 8) | (R << 8) | (0 << 8;  // 0x00RRGGBB
    uint32_t *vram = (uint32_t *) VRAM1;
    int total_pixels = 800 * 600;

    for (int i = 0; i < total_pixels; i++) {
        vram[i] = color;
    }
}


void draw() {
    uint32_t *video = (uint32_t *) 0xE0000000;
    uint32_t *vram1 = (uint32_t *) VRAM1;
    uint32_t *vram2 = (uint32_t *) VRAM2;
    uint32_t *end = vram1 + 800 * 600;

    while (vram1 < end) {
        if (*vram1 != *vram2) {
            *video = *vram1;
            *vram2 = *vram1;
        }
        vram1++;
        vram2++;
        video++;
    }
}

void putc(uchar c, int kX, int kY) {
    // função vazia para ser completada com fonte bitmap
}

int print(char *string, int kX, int kY) {
    for (; *string != 0; string++) {
        if (*string == '\n') {
            kY++;
            kX = 0;
        } else {
            putc(*string, kX, kY);
            kX += 10;
            if (kX > 629) {
                kX = 0;
                kY += 10;
            }
        }
    }
    return 0;
}







*/
extern int install;
int TellOfInstaletion = 0;

void DrawSWindowInst(int tam){
	SetReact(100,100,800-200,600-200,  0,0,0);
	/*make bar*/ {
		
		uint8_t color = 0;
		uint8_t color2 = 0;
		color = 245;
		color2 = 140;
		//SetPReact(101,101,800-200-2,tam-2,  color,color,color,  color2,color2,color2);
		
		int local = 0;
		for(;local<=3;local++){
			if(local == 0){
				color = 200;
				color2 = 150;
			} else if(local == 1){
				color = 150;
				color2 = 150;
			} else if(local == 2){
				color = 150;
				color2 = 150;
			} else if(local == 3){
				color = 150;
				color2 = 100;
			} 
			SetPReact(101,101+(tam / 4)*local,800-200-2,tam / 4,  color,color,color,  color2,color2,color2);
		}
	}
	/*make menu principu*/{
		SetReact(101,100+tam,800-200-2,600-200-(tam/4)-1-tam,  240,240,240);
		SetPReact(101,600-100-(tam/4),800-200-2,(tam / 4)-1,  200,200,200,  100,100,100);
	}
}

short install_menu(){
	int tam = 30;
	if(TellOfInstaletion == 0){
		clear(80,255,100);
		DrawSWindowInst(tam);
	} else if(TellOfInstaletion == 1){
	
	}
	return 1;
}