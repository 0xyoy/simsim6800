/*
* control functions (print, reset, the like)
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/

#include <stdio.h>

#include "types.h"
#include "control.h"
#include "decode_exec.h"

void print_memory_frame(uint8_t * memory, uint16_t start, uint16_t end) {
    if(start > end) {
        start ^= end;
        end ^= start;
        start ^= end;
    }

    start &= 0xFFF0;
    end &= 0xFFF0;
    for(uint16_t i = start; i <= end; i+=0x0010) {
        printf("%04x: ", i);
        for(uint16_t addr = i; addr < i+0x0010; ++addr) {
            printf("%02x ", memory[addr]);
        }
        printf("\n");
    }
}

void print_mpustate(MPUState * state) {
    printf("A:\t%#02x\n", state->a);
    printf("B:\t%#02x\n", state->b);
    printf("X:\t%#04x\n", state->x);
    printf("PC:\t%#04x\n", state->pc);
    printf("SP:\t%#04x\n", state->sp);

    printf("%d%d%d%d%d%d\n", 
            GET_FLAG(FLAG_H),
            GET_FLAG(FLAG_I),
            GET_FLAG(FLAG_N),
            GET_FLAG(FLAG_Z),
            GET_FLAG(FLAG_V),
            GET_FLAG(FLAG_C)
            );
    printf("HINZVC\n");
}

void reset_mpustate(MPUState * state) {
    state->a = 0x00; 
    state->b = 0x00; 
    state->x = 0x0000; 
    state->pc = 0x0000; 
    state->sp = 0x0000; 
    state->ccr = 0x00;
    
}

void run_single(MPUState * state, uint8_t * memory) {
    uint8_t opcode = memory[state->pc];
    decode_exec(opcode, state, memory);
}
