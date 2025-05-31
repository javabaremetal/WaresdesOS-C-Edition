#include "types.h"
#include "waresdes.h"

void outw(uint16_t port, uint16_t value);
uint16_t inw(uint16_t port);
uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t value);

void sleep(int);