#include "types.h"
#include "waresdes.h"

#define __SCREEN__
#include "screen.h"

char VRAM1[800*600*4];
char VRAM2[800*600*4];
extern multiboot_info_t *mbi;

void SetPixel(int x, int y, u8 R, u8 G, u8 B) {
    if ((unsigned)x < 800 && (unsigned)y < 600) {
        ((uint32_t*)VRAM1)[y * 800 + x] = ((uint32_t)B) | ((uint32_t)G << 8) | ((uint32_t)R << 16);
    }
}

void SetReact(int x, int y, int lar, int alt, char R, char G, char B) {
    for (int tmp_y = 0; tmp_y < alt; tmp_y++) {
        for (int tmp_x = 0; tmp_x < lar; tmp_x++) {
            SetPixel(x + tmp_x, y + tmp_y, R, G, B);
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
            u8 R = BITMAP__D__[index++];
            u8 G = BITMAP__D__[index++];
            u8 B = BITMAP__D__[index++];

            // Pula pixels transparentes
            if ((R | G | B) == 0) continue;

            if (draw_x >= 0 && draw_x < 800) {
                uint32_t color = ((uint32_t)B) | ((uint32_t)G << 8) | ((uint32_t)R << 16);
                ((uint32_t*)VRAM1)[draw_y * 800 + draw_x] = color;
            }
        }
    }
}



void clear(u8 R, u8 G, u8 B) {
    uint32_t color = ((uint32_t)B) | ((uint32_t)G << 8) | ((uint32_t)R << 16);
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
