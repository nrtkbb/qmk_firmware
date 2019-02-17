#pragma once

#include "../petit_split.h"

//void promicro_bootloader_jmp(bool program);
#include "quantum.h"

#ifdef RGBLIGHT_ENABLE
//rgb led driver
#include "ws2812.h"
#endif

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

//void promicro_bootloader_jmp(bool program);
#define LAYOUT( \
    L00, L01, L02,   R00, R01, R02, \
    L10, L11, L12,   R10, R11, R12, \
    L20, L21, L22,   R20, R21, R22 \
  ) \
  { \
    { L00, L01, L02 }, \
    { L10, L11, L12 }, \
    { L20, L21, L22 }, \
    { R02, R01, R00 }, \
    { R12, R11, R10 }, \
    { R22, R21, R20 } \
  }
