/*
* decode and execute (fetch is easy and is done in control.c)
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/


#include "types.h"
#include "opcodes.h"
#include "control.h"


static void op_invalid() {
    return;
}

void decode_exec(uint8_t opcode) {
    switch(opcode) {
        default:
            op_invalid();
            return;
    }
}
