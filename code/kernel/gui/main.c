#include "../screen.h"
#include "../drivers/disk.h"
#include "tema.h"
#include "buttons.h"
#define FUNDCOLOR 0,255,0
extern char VRAM1[800*600*4];
int tema = AERO_TEMA;
int color = COLOR_PRETO;
int install = 1;


void DrawBar(int,int);
void DrawButton(int,int,int,int,int);
/*
int color = 0;
int yB = y;
for(int i = 0;i < alt;i++){
	SetReact(x,yB,lar,1,0,0x00 + ((0xFF - 0x00) * i) / alt,0);
	color++;
	yB++;
}return 0;
*/
void SetTPixel(int x, int y, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha) {
    if (x < 0 || x >= 800 || y < 0 || y >= 600 || alpha == 0)
        return;

    int offset = (y * 800 + x) * 4;

    unsigned char bgB = VRAM1[offset + 0];
    unsigned char bgG = VRAM1[offset + 1];
    unsigned char bgR = VRAM1[offset + 2];

    // Blend fórmula: result = (src * alpha + dst * (255 - alpha)) / 255
    VRAM1[offset + 0] = (B * alpha + bgB * (255 - alpha)) / 255;
    VRAM1[offset + 1] = (G * alpha + bgG * (255 - alpha)) / 255;
    VRAM1[offset + 2] = (R * alpha + bgR * (255 - alpha)) / 255;
    VRAM1[offset + 3] = 255; // Alpha final fixo (opaco). Opcional.
}

void SetTReact(int x, int y, int lar, int alt, unsigned char R, unsigned char G, unsigned char B, unsigned char alpha) {
    // Clipping inicial para evitar chamadas fora da tela
    int start_x = (x < 0) ? 0 : x;
    int start_y = (y < 0) ? 0 : y;
    int end_x = ((x + lar) > 800) ? 800 : (x + lar);
    int end_y = ((y + alt) > 600) ? 600 : (y + alt);

    for (int py = start_y; py < end_y; py++) {
        int offset = py * 800 * 4 + start_x * 4;
        for (int px = start_x; px < end_x; px++) {
            unsigned char *pixel = &VRAM1[offset];
            unsigned char bgB = pixel[0];
            unsigned char bgG = pixel[1];
            unsigned char bgR = pixel[2];

            pixel[0] = (B * alpha + bgB * (255 - alpha)) / 255;
            pixel[1] = (G * alpha + bgG * (255 - alpha)) / 255;
            pixel[2] = (R * alpha + bgR * (255 - alpha)) / 255;
            pixel[3] = 255;

            offset += 4;
        }
    }
}

void SetTPReact(int x, int y, int lar, int alt,
                unsigned char R1, unsigned char G1, unsigned char B1,
                unsigned char R2, unsigned char G2, unsigned char B2,
                unsigned char alpha) {
    if (alt <= 0 || lar <= 0 || alpha == 0) return;

    // Clipping
    int start_x = (x < 0) ? 0 : x;
    int end_x   = ((x + lar) > 800) ? 800 : (x + lar);
    int start_y = (y < 0) ? 0 : y;
    int end_y   = ((y + alt) > 600) ? 600 : (y + alt);

    int visible_height = end_y - start_y;
    if (visible_height <= 0 || end_x <= start_x) return;

    for (int i = 0; i < visible_height; i++) {
        int dy = start_y + i;

        // Gradiente interpolado vertical
        unsigned char R = R1 + ((R2 - R1) * i) / (alt - 1);
        unsigned char G = G1 + ((G2 - G1) * i) / (alt - 1);
        unsigned char B = B1 + ((B2 - B1) * i) / (alt - 1);

        int offset = (dy * 800 + start_x) * 4;
        for (int px = start_x; px < end_x; px++) {
            // Background
            unsigned char bB = VRAM1[offset + 0];
            unsigned char bG = VRAM1[offset + 1];
            unsigned char bR = VRAM1[offset + 2];

            // Mistura de cores com alpha blending
            VRAM1[offset + 0] = (B * alpha + bB * (255 - alpha)) / 255;
            VRAM1[offset + 1] = (G * alpha + bG * (255 - alpha)) / 255;
            VRAM1[offset + 2] = (R * alpha + bR * (255 - alpha)) / 255;
            VRAM1[offset + 3] = 255; // Alpha final fixo
            offset += 4;
        }
    }
}

void SetPReact(int x, int y, int lar, int alt, 
               unsigned char R1, unsigned char G1, unsigned char B1,
               unsigned char R2, unsigned char G2, unsigned char B2) {
    if (alt <= 0 || lar <= 0) return;

    // Clipping básico
    int start_x = (x < 0) ? 0 : x;
    int end_x = ((x + lar) > 800) ? 800 : (x + lar);
    int start_y = (y < 0) ? 0 : y;
    int end_y = ((y + alt) > 600) ? 600 : (y + alt);

    int visible_height = end_y - start_y;
    if (visible_height <= 0 || end_x <= start_x) return;

    for (int i = 0; i < visible_height; i++) {
        int dy = start_y + i;

        // Gradiente vertical
        unsigned char R = R1 + ((R2 - R1) * i) / (alt - 1);
        unsigned char G = G1 + ((G2 - G1) * i) / (alt - 1);
        unsigned char B = B1 + ((B2 - B1) * i) / (alt - 1);

        // Linha horizontal
        int offset = (dy * 800 + start_x) * 4;
        for (int px = start_x; px < end_x; px++) {
            VRAM1[offset + 0] = B;
            VRAM1[offset + 1] = G;
            VRAM1[offset + 2] = R;
            VRAM1[offset + 3] = 255;
            offset += 4;
        }
    }
}

void printf(char *ff,...){
	
}
void putchar(char ff){
	
}

short install_menu();

// ____________________________________________________
void gui_main(){
	//read_volume_id();
	if(install == 0){
		SetPReact(0,0,800,600,  0,255,0,  0,100,0  );
		DrawBar(tema,color);
		DrawButton(5,600-40+7,50,25,BTN_COLOR_BRANCO);
	} else {
		install_menu();
	}
}

