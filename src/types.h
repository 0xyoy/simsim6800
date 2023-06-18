/*
* type declarations 
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/

#ifndef TYPES
#define TYPES

#include <stdlib.h>
#include "opcodes.h"

enum flag {
    FLAG_H = 5,
    FLAG_I = 4,
    FLAG_N = 3,
    FLAG_Z = 2,
    FLAG_V = 1,
    FLAG_C = 0
};

typedef struct {
    uint8_t a;
    uint8_t b;
    uint16_t x;
    uint16_t pc;
    uint16_t sp;
    uint8_t ccr;
} MPUState;

#endif
