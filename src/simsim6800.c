/*
* main driver program 
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/

#include "types.h"
#include "control.h"

#define MEMORY_SIZE 65536

int main() {
    MPUState state;

    uint8_t memory[MEMORY_SIZE];

    reset_mpustate(&state);
    state.pc = 0x1020;
    state.sp = 0x2000;
    print_mpustate(&state);

    memory[0x1020] = OP_BSR;
    memory[0x1021] = 0x7;
    memory[0x1029] = OP_ADD_A_IMM;
    memory[0x102a] = 0x12;
    memory[0x102b] = OP_ASR_A;
    memory[0x102c] = OP_ASL_A;
    memory[0x102d] = OP_ASL_A;
    memory[0x102e] = OP_ASL_A;
    memory[0x102f] = OP_ASL_A;
    print_memory_frame(memory, 0x1020, 0x1075);
    print_memory_frame(memory, 0x1ff0, 0x2010);

    run_single(&state, memory);
    run_single(&state, memory);

    print_mpustate(&state);
    
    print_memory_frame(memory, 0x1ff0, 0x2010);
    run_single(&state, memory);
    print_mpustate(&state);
//    run_single(&state, memory);
    run_breakpoint(&state, memory, 0x1030);
    print_mpustate(&state);
    return 0;
}
