/*
* control functions header (print, reset, the like)
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/

#ifndef CONTROL
#define CONTROL

#include "types.h"

#define GET_FLAG(state, flag)   ((state->ccr)>>(flag)&(1U))
#define SET_FLAG(state, flag)   ((state->ccr)|=1U<<flag)
#define CLEAR_FLAG(state, flag) ((state->ccr)&=~(1U<<flag))

void print_memory_frame(uint8_t *, uint16_t, uint16_t); 
void print_mpustate(MPUState *);
void reset_mpustate(MPUState *);
void run_single(MPUState *, uint8_t *);

#endif
