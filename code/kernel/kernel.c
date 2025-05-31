
__attribute__((section(".multiboot")))
const unsigned int multiboot_header[] = {
    // Header principal
    0xE85250D6, // magic
    0,          // architecture (0 = i386)
    32,         // tamanho do header (em bytes)
    -(0xE85250D6 + 0 + 32), // checksum

    // Tag: Framebuffer (type 5)
    5,          // tipo da tag (framebuffer)
    20,         // tamanho da tag (em bytes)
    800,        // largura
    600,        // altura
    32,         // profundidade (bits por pixel)

    // Tag de fim
    0,          // tipo 0 = end tag
    0           // tamanho da tag end (sempre 8)
};
#ifndef __WARESDES_DEFINES__
#define __WARESDES_DEFINES__


typedef long uint64_t;
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;


#endif
typedef struct {
    uint32_t type;
    uint32_t size;
} __attribute__((packed)) multiboot_tag_t;
typedef struct {
    uint32_t size;
    uint64_t addr;
    uint64_t len;
    uint32_t type;
    uint32_t zero;
} __attribute__((packed)) multiboot_mmap_entry_t;
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
    uint64_t framebuffer_addr;
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
typedef struct {
    multiboot_tag_t tag;
    uint64_t framebuffer_addr;
    uint32_t framebuffer_pitch;
    uint32_t framebuffer_width;
    uint32_t framebuffer_height;
    uint8_t  framebuffer_bpp;
    uint8_t  framebuffer_type;
    uint8_t  reserved[2];
} __attribute__((packed)) multiboot_tag_framebuffer_t;


typedef struct {
    uint32_t type;
    uint32_t size;
    uint32_t mod_start;
    uint32_t mod_end;
    // seguido de char name[];
} multiboot_tag_module_t;

multiboot_info_t *mbi = 0;
#include "types.h"
#include "screen.h"
#include "drivers/mouse.h"
void enable_ps2_mouse();

int main(void);
void gui_main();
void InitDisk();


void _start(uint32_t multiboot_magic, uint32_t mb2_addr) {
	clear(0x00, 0x00, 0x00);
	
	 // usa mmap do multiboot1

	InitDisk();     // agora malloc tem heap real
	draw();
	enable_ps2_mouse();

	while (1) {
		gui_main();
		MouseUPDate();
		//MouseUPDate();MouseUPDate();MouseUPDate();MouseUPDate();MouseUPDate();MouseUPDate();MouseUPDate();MouseUPDate();MouseUPDate();MouseUPDate();MouseUPDate();
		draw();
	}
}

