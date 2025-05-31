#include "types.h"
#include "waresdes.h"
#define SPEAKER_PORT 0x61

void outw(uint16_t port, uint16_t value) {
    asm volatile ("outw %0, %1" : : "a"(value), "Nd"(port));
}

uint8_t inb(uint16_t port) {
    uint8_t value;
    __asm__ volatile("inb %1, %0" : "=a"(value) : "Nd"(port));
    return value;
}
unsigned short inw(unsigned short port) {
    unsigned short ret;
    asm volatile ("inw %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}
void outb(uint16_t port, uint8_t value) {
    __asm__ volatile("outb %0, %1" : : "a"(value), "Nd"(port));
}

void play_tone(uint16_t frequency) {
    // Frequência em Hz
    // Divida o valor para gerar o tom desejado. O valor deve ser ajustado para o controle de som do PC Speaker
    uint32_t divisor = 1193180 / frequency;

    // Ativar o buzzer (som)
    outb(0x43, 0xB6);  // Comando para o Timer 2
    outb(0x42, divisor & 0xFF);  // Valor baixo do divisor
    outb(0x42, (divisor >> 8) & 0xFF);  // Valor alto do divisor

    // Ativar o PC Speaker
    uint8_t status = inb(SPEAKER_PORT);
    outb(SPEAKER_PORT, status | 0x03);  // Bit 0 e 1 para ligar o som
}

void stop_tone() {
    // Parar o som
    uint8_t status = inb(SPEAKER_PORT);
    outb(SPEAKER_PORT, status & ~0x03);  // Desligar os bits 0 e 1
}



void sleep(int time){
	int pointer  = 0;
	time = time * 1000;
	for(time = time; pointer < time; pointer++){
    	outb(0x80, 0);  // Pequeno delay
	}
}