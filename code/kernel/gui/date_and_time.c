#include "../i386.h"

typedef struct {
    int day;
    int month;
    int year;   // Ano completo (ex: 2025)
} date;

typedef struct {
    int hour;
    int minutes;
    int seconds;
} time;

unsigned char cmos_read(unsigned char reg) {
    outb(0x70, reg);
    return inb(0x71);
}

int is_updating() {
    outb(0x70, 0x0A);
    return inb(0x71) & 0x80;
}

void get_time(int* hour, int* min, int* sec) {
    while (is_updating()); // Espera RTC terminar atualização

    *sec  = cmos_read(0x00);
    *min  = cmos_read(0x02);
    *hour = cmos_read(0x04);

    outb(0x70, 0x0B);
    unsigned char status_b = inb(0x71);

    if (!(status_b & 0x04)) {  // Se está em BCD, converte para binário
        *sec  = ((*sec  >> 4) * 10) + (*sec  & 0x0F);
        *min  = ((*min  >> 4) * 10) + (*min  & 0x0F);
        *hour = ((*hour >> 4) * 10) + (*hour & 0x0F);
    }
}

void get_date(int* day, int* month, int* year) {
    while (is_updating()); // Espera o RTC parar de atualizar

    *day   = cmos_read(0x07);
    *month = cmos_read(0x08);
    *year  = cmos_read(0x09);

    outb(0x70, 0x0B);
    unsigned char status_b = inb(0x71);

    if (!(status_b & 0x04)) {  // Se está em BCD, converte para binário
        *day   = ((*day   >> 4) * 10) + (*day   & 0x0F);
        *month = ((*month >> 4) * 10) + (*month & 0x0F);
        *year  = ((*year  >> 4) * 10) + (*year  & 0x0F);
    }

    // O RTC só retorna o ano com 2 dígitos, então convém ajustar
    // Aqui eu assumo que você esteja no século 2000 (ano >= 2000)
    *year += 2000;
}

// Função para ler data e hora e armazenar em structs
void read_date_time(date* d, time* t) {
    get_time(&t->hour, &t->minutes, &t->seconds);
    get_date(&d->day, &d->month, &d->year);
}
