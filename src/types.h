/*
* type declarations 
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/

#ifndef TYPES
#define TYPES

#include <stdlib.h>
#include "opcode.h"

/* "by how much should you shift ccr to get the desired flag" */
enum flag {
    FLAG_H = 5,
    FLAG_I = 4,
    FLAG_N = 3,
    FLAG_Z = 2,
    FLAG_V = 1,
    FLAG_C = 0
};

enum addr_mode {
    MODE_ACC = 0,
    MODE_INH = 1,
    MODE_IMM = 2,
    MODE_DIR = 3,
    MODE_IDX = 4,
    MODE_EXT = 5,
    MODE_REL = 6
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
