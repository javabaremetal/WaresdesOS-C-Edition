#include "types.h"
/*

 = {
	8,8,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	0x10,0x10,0x10,0x10,0x10,0x10,0x10,0x10,
	
};

*/


#ifdef __SCREEN__
typedef struct multiboot_info {
    uint32_t flags;
    uint32_t mem_lower;
    uint32_t mem_upper;
    uint32_t boot_device;
    uint32_t cmdline;
    uint32_t mods_count;
    uint32_t mods_addr;
    uint32_t syms[4];
    uint32_t mmap_length;
    uint32_t mmap_addr;
    uint32_t drives_length;
    uint32_t drives_addr;
    uint32_t config_table;
    uint32_t boot_loader_name;
    uint32_t apm_table;
    uint32_t vbe_control_info;
    uint32_t vbe_mode_info;
    uint16_t vbe_mode;
    uint16_t vbe_interface_seg;
    uint16_t vbe_interface_off;
    uint16_t vbe_interface_len;
    
    // Framebuffer info
    long framebuffer_addr;
    uint32_t framebuffer_pitch;
    uint32_t framebuffer_width;
    uint32_t framebuffer_height;
    uint8_t  framebuffer_bpp;
    uint8_t  framebuffer_type;
    union {
        struct {
            uint8_t red_field_position;
            uint8_t red_mask_size;
            uint8_t green_field_position;
            uint8_t green_mask_size;
            uint8_t blue_field_position;
            uint8_t blue_mask_size;
        };
    };
} __attribute__((packed)) multiboot_info_t;

#define COR_PRETO       	0x00  // Preto
#define COR_AZUL        	0x01  // Azul
#define COR_VERDE       	0x02  // Verde
#define COR_CIANO      		0x03  // Ciano
#define COR_VERMELHO    	0x04  // Vermelho
#define COR_MAGENTA     	0x05  // Magenta
#define COR_MARROM      	0x06  // Marrom
#define COR_CINZA_CLARO 	0x07  // Cinza Claro
#define COR_CINZA_ESCURO 	0x08 // Cinza Escuro
#define COR_AZUL_CLARO  	0x09  // Azul Claro
#define AZUL_CLARINHO		0x20 // azul em RGB(225,225,255)
#define COR_VERDE_CLARO 	0x0A  // Verde Claro
#define COR_CIANO_CLARO 	0x0B  // Ciano Claro
#define COR_VERMELHO_CLARO 	0x0C // Vermelho Claro
#define COR_MAGENTA_CLARO 	0x0D  // Magenta Claro
#define COR_AMARELO     	0x0E  // Amarelo
#define COR_BRANCO      	0x0F  // Branco
#define BUTTON_COLOR 		0x19 // cinza mais escuro do que o 7 e nao tao escuro cuanto o 8



#define BUFFER 0xE0000000

#else
#define COR_PRETO       	0x00  // Preto
#define COR_AZUL        	0x01  // Azul
#define COR_VERDE       	0x02  // Verde
#define COR_CIANO      		0x03  // Ciano
#define COR_VERMELHO    	0x04  // Vermelho
#define COR_MAGENTA     	0x05  // Magenta
#define COR_MARROM      	0x06  // Marrom
#define COR_CINZA_CLARO 	0x07  // Cinza Claro
#define COR_CINZA_ESCURO 	0x08 // Cinza Escuro
#define COR_AZUL_CLARO  	0x09  // Azul Claro
#define AZUL_CLARINHO		0x20
#define COR_VERDE_CLARO 	0x0A  // Verde Claro
#define COR_CIANO_CLARO 	0x0B  // Ciano Claro
#define COR_VERMELHO_CLARO 	0x0C // Vermelho Claro
#define COR_MAGENTA_CLARO 	0x0D  // Magenta Claro
#define COR_AMARELO     	0x0E  // Amarelo
#define COR_BRANCO      	0x0F  // Branco
#define BUTTON_COLOR 		0x19



#endif				/* __SCREEN__ */

void SetBITMAP(u8 *BITMAP__D__,int x,int y);
void clear(u8 R,u8 G,u8 B);
void draw();
void SetPixel(int,int,u8,u8,u8);
void SetReact(int,  int,  int,  int,  char,  char,  char);
int print(char *, int,int);
void putc(uchar,int,int);



