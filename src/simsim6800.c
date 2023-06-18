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
    state.pc = 0x0020;
    print_mpustate(&state);

    memory[0x0020] = OP_ADD_A_IMM;
    memory[0x0021] = 0x80;
    memory[0x0022] = OP_ADD_A_IMM;
    memory[0x0023] = 0x80;
    print_memory_frame(memory, 0x0020, 0x0075);

    run_single(&state, memory);
    run_single(&state, memory);

    print_mpustate(&state);
    
    return 0;
}
