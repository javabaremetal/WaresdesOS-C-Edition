#include "../types.h"
#ifdef __MOUSE_DRIVE__
#ifndef CLICK_BTN
#define CLICK_BTN 0x47
#define CLICK_INFINET_BTN 0x4C
#endif

#define __MOUSE_RETUNR_OK__ 0xF749


#else
#ifndef CLICK_BTN
#define CLICK_BTN 0x47
#endif


void SetMouseCursorPosition(int ,int );
void SetCursorMouse();
void SetMouseCursorIMG();
unsigned char MouseUPDate();

#endif




