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
    print_mpustate(&state);
    print_memory_frame(memory, 0x0020, 0x0075);

    return 0;
}
