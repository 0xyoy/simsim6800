/*
* decode and execute (fetch is easy and is done in control.c)
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/

#include "types.h"
#include "opcodes.h"
#include "control.h"

#define OP1     memory[state->pc+1]
#define OP2     memory[state->pc+2]

#define X       state->x

static void op_invalid() {
    return;
}

/* add b to a */
static void op_aba(MPUState * state) {
    uint8_t sign_bit = (state->a)>>7;
    state->a += state->b;

    state->a < state->b ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C);
    state->a == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (state->a)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    sign_bit == (state->b)>>7 && sign_bit != (state->a)>>7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V);
    ((state->a)&0x0f) < ((state->b)&0x0f) ? SET_FLAG(FLAG_H) : CLEAR_FLAG(FLAG_H);
}

/* add operand and carry to a */
static void op_adc_a(MPUState * state, uint8_t operand) {
    uint8_t sign_bit = (state->a)>>7;
    state->a += operand + GET_FLAG(FLAG_C);
    
    state->a < operand ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C);
    state->a == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (state->a)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    sign_bit == (operand)>>7 && sign_bit != (state->a)>>7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V);
    ((state->a)&0x0f) < ((operand)&0x0f) ? SET_FLAG(FLAG_H) : CLEAR_FLAG(FLAG_H);

}

/* add operand and carry to b */
static void op_adc_b(MPUState * state, uint8_t operand) {
    uint8_t sign_bit = (state->b)>>7;
    state->b += operand + GET_FLAG(FLAG_C);
    
    state->b < operand ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C);
    state->b == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (state->b)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    sign_bit == (operand)>>7 && sign_bit != (state->b)>>7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V);
    ((state->b)&0x0f) < ((operand)&0x0f) ? SET_FLAG(FLAG_H) : CLEAR_FLAG(FLAG_H);
}


/* add operand to a */
static void op_add_a(MPUState * state, uint8_t operand) {
    uint8_t sign_bit = (state->a)>>7;
    state->a += operand;
    
    state->a < operand ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C);
    state->a == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (state->a)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    sign_bit == (operand)>>7 && sign_bit != (state->a)>>7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V);
    ((state->a)&0x0f) < ((operand)&0x0f) ? SET_FLAG(FLAG_H) : CLEAR_FLAG(FLAG_H);
}

/* add operand to b */
static void op_add_b(MPUState * state, uint8_t operand) {
    uint8_t sign_bit = (state->b)>>7;
    state->b += operand;
    
    state->b < operand ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C);
    state->b == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (state->b)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    sign_bit == (operand)>>7 && sign_bit != (state->b)>>7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V);
    ((state->b)&0x0f) < ((operand)&0x0f) ? SET_FLAG(FLAG_H) : CLEAR_FLAG(FLAG_H);
}


/* and a and operand */
static void op_and_a(MPUState * state, uint8_t operand) {
    state->a ^= operand;
    
    state->a == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (state->a)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    CLEAR_FLAG(FLAG_V); 

}

/* and b and operand */
static void op_and_b(MPUState * state, uint8_t operand) {
    state->b ^= operand;
    
    state->b == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (state->b)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    CLEAR_FLAG(FLAG_V); 
}



void decode_exec(uint8_t opcode, MPUState * state, uint8_t * memory) {
    
    uint16_t addr_ext = OP1;
    addr_ext <<= 8;
    addr_ext += OP2;

    switch(opcode) { 
        case OP_ABA:
            op_aba(state);
            state->pc += 1;
            break;

        case OP_ADC_A_IMM:
            op_adc_a(state, OP1);
            state->pc += 2;
            break;
        case OP_ADC_A_DIR:
            op_adc_a(state, memory[OP1]);
            state->pc += 2;
            break;
        case OP_ADC_A_IDX:
            op_adc_a(state, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_ADC_A_EXT:
            op_adc_a(state, memory[addr_ext]);
            state->pc += 3;
            break;
        case OP_ADC_B_IMM:
            op_adc_b(state, OP1);
            state->pc += 2;
            break;
        case OP_ADC_B_DIR:
            op_adc_b(state, memory[OP1]);
            state->pc += 2;
            break;
        case OP_ADC_B_IDX:
            op_adc_b(state, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_ADC_B_EXT:
            op_adc_b(state, memory[addr_ext]);
            state->pc += 3;
            break;
        
        case OP_ADD_A_IMM:
            op_add_a(state, OP1);
            state->pc += 2;
            break;
        case OP_ADD_A_DIR:
            op_add_a(state, memory[OP1]);
            state->pc += 2;
            break;
        case OP_ADD_A_IDX:
            op_add_a(state, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_ADD_A_EXT:
            op_add_a(state, memory[addr_ext]);
            state->pc += 3;
            break;
        case OP_ADD_B_IMM:
            op_add_b(state, OP1);
            state->pc += 2;
            break;
        case OP_ADD_B_DIR:
            op_add_b(state, memory[OP1]);
            state->pc += 2;
            break;
        case OP_ADD_B_IDX:
            op_add_b(state, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_ADD_B_EXT:
            op_add_b(state, memory[addr_ext]);
            state->pc += 3;
            break;
        
        case OP_AND_A_IMM:
            op_and_a(state, OP1);
            state->pc += 2;
            break;
        case OP_AND_A_DIR:
            op_and_a(state, memory[OP1]);
            state->pc += 2;
            break;
        case OP_AND_A_IDX:
            op_and_a(state, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_AND_A_EXT:
            op_and_a(state, memory[addr_ext]);
            state->pc += 3;
            break;
        case OP_AND_B_IMM:
            op_and_b(state, OP1);
            state->pc += 2;
            break;
        case OP_AND_B_DIR:
            op_and_b(state, memory[OP1]);
            state->pc += 2;
            break;
        case OP_AND_B_IDX:
            op_and_b(state, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_AND_B_EXT:
            op_and_b(state, memory[addr_ext]);
            state->pc += 3;
            break;

        case OP_ASL_A    :
        case OP_ASL_B    :
        case OP_ASL_IDX  :
        case OP_ASL_EXT  :
        case OP_ASR_A    :
        case OP_ASR_B    :
        case OP_ASR_IDX  :
        case OP_ASR_EXT  :
        case OP_BCC      :
        case OP_BCS      :
        case OP_BEQ      :
        case OP_BGE      :
        case OP_BGT      :
        case OP_BHI      :
        case OP_BIT_A_IMM:
        case OP_BIT_A_DIR:
        case OP_BIT_A_IDX:
        case OP_BIT_A_EXT:
        case OP_BIT_B_IMM:
        case OP_BIT_B_DIR:
        case OP_BIT_B_IDX:
        case OP_BIT_B_EXT:
        case OP_BLE      :
        case OP_BLS      :
        case OP_BLT      :
        case OP_BMI      :
        case OP_BNE      :
        case OP_BPL      :
        case OP_BRA      :
        case OP_BSR      :
        case OP_BVC      :
        case OP_BVS      :
        case OP_CBA      :
        case OP_CLC      :
        case OP_CLI      :
        case OP_CLR_A    :
        case OP_CLR_B    :
        case OP_CLR_IDX  :
        case OP_CLR_EXT  :
        case OP_CLV      :
        case OP_CMP_A_IMM:
        case OP_CMP_A_DIR:
        case OP_CMP_A_IDX:
        case OP_CMP_A_EXT:
        case OP_CMP_B_IMM:
        case OP_CMP_B_DIR:
        case OP_CMP_B_IDX:
        case OP_CMP_B_EXT:
        case OP_COM_A    :
        case OP_COM_B    :
        case OP_COM_IDX  :
        case OP_COM_EXT  :
        case OP_CPX_IMM  :
        case OP_CPX_DIR  :
        case OP_CPX_IDX  :
        case OP_CPX_EXT  :
        case OP_DAA      : 
        case OP_DEC_A    :
        case OP_DEC_B    :
        case OP_DEC_IDX  :
        case OP_DEC_EXT  :
        case OP_DES      :
        case OP_DEX      :
        case OP_EOR_A_IMM:
        case OP_EOR_A_DIR:
        case OP_EOR_A_IDX:
        case OP_EOR_A_EXT:
        case OP_EOR_B_IMM:
        case OP_EOR_B_DIR:
        case OP_EOR_B_IDX:
        case OP_EOR_B_EXT:
        case OP_INC_A    :
        case OP_INC_B    :
        case OP_INC_IDX  :
        case OP_INC_EXT  :
        case OP_INS      :
        case OP_INX      :
        case OP_JMP_IDX  :
        case OP_JMP_EXT  :
        case OP_JSR_IDX  :
        case OP_JSR_EXT  :
        case OP_LDA_A_IMM:
        case OP_LDA_A_DIR:
        case OP_LDA_A_IDX:
        case OP_LDA_A_EXT:
        case OP_LDA_B_IMM:
        case OP_LDA_B_DIR:
        case OP_LDA_B_IDX:
        case OP_LDA_B_EXT:
        case OP_LDS_IMM  :
        case OP_LDS_DIR  :
        case OP_LDS_IDX  :
        case OP_LDS_EXT  :
        case OP_LDX_IMM  :
        case OP_LDX_DIR  :
        case OP_LDX_IDX  :
        case OP_LDX_EXT  :
        case OP_LSR_A    :
        case OP_LSR_B    :
        case OP_LSR_IDX  :
        case OP_LSR_EXT  :
        case OP_NEG_A    :
        case OP_NEG_B    :
        case OP_NEG_IDX  :
        case OP_NEG_EXT  :
        case OP_NOP      :
        case OP_ORA_A_IMM:
        case OP_ORA_A_DIR:
        case OP_ORA_A_IDX:
        case OP_ORA_A_EXT:
        case OP_ORA_B_IMM:
        case OP_ORA_B_DIR:
        case OP_ORA_B_IDX:
        case OP_ORA_B_EXT:
        case OP_PSH_A    :
        case OP_PSH_B    :
        case OP_PUL_A    :
        case OP_PUL_B    :
        case OP_ROL_A    :
        case OP_ROL_B    :
        case OP_ROL_IDX  :
        case OP_ROL_EXT  :
        case OP_ROR_A    :
        case OP_ROR_B    :
        case OP_ROR_IDX  :
        case OP_ROR_EXT  :
        case OP_RTI      :
        case OP_RTS      :
        case OP_SBA      :
        case OP_SBC_A_IMM:
        case OP_SBC_A_DIR:
        case OP_SBC_A_IDX:
        case OP_SBC_A_EXT:
        case OP_SBC_B_IMM:
        case OP_SBC_B_DIR:
        case OP_SBC_B_IDX:
        case OP_SBC_B_EXT:
        case OP_SEC      :
        case OP_SEI      :
        case OP_SEV      :
        case OP_STA_A_DIR:
        case OP_STA_A_IDX:
        case OP_STA_A_EXT:
        case OP_STA_B_DIR:
        case OP_STA_B_IDX:
        case OP_STA_B_EXT:
        case OP_STS_DIR  :
        case OP_STS_IDX  :
        case OP_STS_EXT  :
        case OP_STX_DIR  :
        case OP_STX_IDX  :
        case OP_STX_EXT  :
        case OP_SUB_A_IMM:
        case OP_SUB_A_DIR:
        case OP_SUB_A_IDX:
        case OP_SUB_A_EXT:
        case OP_SUB_B_IMM:
        case OP_SUB_B_DIR:
        case OP_SUB_B_IDX:
        case OP_SUB_B_EXT:
        case OP_SWI      :
        case OP_TAB      :
        case OP_TAP      :
        case OP_TBA      :
        case OP_TPA      :
        case OP_TST_A    :
        case OP_TST_B    :
        case OP_TST_IDX  :
        case OP_TST_EXT  :
        case OP_TSX      :
        case OP_TXS      :




        default:
            op_invalid();
            return;
    }
}
