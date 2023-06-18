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

/* add operands with carry */
static void op_adc(MPUState * state, uint8_t * operand1, uint8_t operand2) {
    uint8_t sign_bit = (*operand1)>>7;
    *operand1 += operand2 + GET_FLAG(FLAG_C);
    
    *operand1 < operand2 ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C);
    *operand1 == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (*operand1)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    sign_bit == (operand2)>>7 && sign_bit != (*operand1)>>7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V);
    ((*operand1)&0x0f) < ((operand2)&0x0f) ? SET_FLAG(FLAG_H) : CLEAR_FLAG(FLAG_H);

}

/* add operands */
static void op_add(MPUState * state, uint8_t * operand1, uint8_t operand2) {
    uint8_t sign_bit = (*operand1)>>7;
    *operand1 += operand2;
    
    *operand1 < operand2 ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C);
    *operand1 == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (*operand1)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    sign_bit == (operand2)>>7 && sign_bit != (*operand1)>>7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V);
    ((*operand1)&0x0f) < ((operand2)&0x0f) ? SET_FLAG(FLAG_H) : CLEAR_FLAG(FLAG_H);
}


/* and operands */
static void op_and(MPUState * state, uint8_t * operand1, uint8_t operand2) {
    *operand1 ^= operand2;
    
    *operand1 == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (*operand1)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N);
    CLEAR_FLAG(FLAG_V); 
}

static void op_asl(MPUState * state, uint8_t * operand) {
    uint8_t bit7 = (*operand)&0x80;
    *operand <<= 1;
    bit7 ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C); 
    *operand == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    (*operand)>>7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N); 
    bit7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V); 
}

static void op_asr(MPUState * state, uint8_t * operand) {
    uint8_t bit7 = (*operand)&0x80;
    uint8_t bit0 = (*operand)&0x01;
    *operand >>= 1;
    *operand |= bit7;
    bit0 ? SET_FLAG(FLAG_C) : CLEAR_FLAG(FLAG_C); 
    *operand == 0 ? SET_FLAG(FLAG_Z) : CLEAR_FLAG(FLAG_Z);
    bit7 ? SET_FLAG(FLAG_N) : CLEAR_FLAG(FLAG_N); 
    bit7 ? SET_FLAG(FLAG_V) : CLEAR_FLAG(FLAG_V); 
}

static void op_branch(MPUState * state, int8_t disp) {
    state->pc += disp + 2;
}

static void op_subroutine(MPUState * state, uint8_t * memory, uint16_t addr) {
    memory[state->sp] = state->pc & 0x00ff;
    memory[(state->sp)-1] = (state->pc)>>8;
    state->sp -= 2;
    state->pc = addr;
}

void decode_exec(uint8_t opcode, MPUState * state, uint8_t * memory) {
    
    uint16_t addr_ext = OP1;
    addr_ext <<= 8;
    addr_ext += OP2;

    switch(opcode) { 
        case OP_ABA:
            op_add(state, &state->a, state->b);
            state->pc += 1;
            break;

        case OP_ADC_A_IMM:
            op_adc(state, &state->a, OP1);
            state->pc += 2;
            break;
        case OP_ADC_A_DIR:
            op_adc(state, &state->a, memory[OP1]);
            state->pc += 2;
            break;
        case OP_ADC_A_IDX:
            op_adc(state, &state->a, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_ADC_A_EXT:
            op_adc(state, &state->a, memory[addr_ext]);
            state->pc += 3;
            break;
        case OP_ADC_B_IMM:
            op_adc(state, &state->b, OP1);
            state->pc += 2;
            break;
        case OP_ADC_B_DIR:
            op_adc(state, &state->b, memory[OP1]);
            state->pc += 2;
            break;
        case OP_ADC_B_IDX:
            op_adc(state, &state->b, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_ADC_B_EXT:
            op_adc(state, &state->b, memory[addr_ext]);
            state->pc += 3;
            break;
        
        case OP_ADD_A_IMM:
            op_add(state, &state->a, OP1);
            state->pc += 2;
            break;
        case OP_ADD_A_DIR:
            op_add(state, &state->a, memory[OP1]);
            state->pc += 2;
            break;
        case OP_ADD_A_IDX:
            op_add(state, &state->a, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_ADD_A_EXT:
            op_add(state, &state->a, memory[addr_ext]);
            state->pc += 3;
            break;
        case OP_ADD_B_IMM:
            op_add(state, &state->b, OP1);
            state->pc += 2;
            break;
        case OP_ADD_B_DIR:
            op_add(state, &state->b, memory[OP1]);
            state->pc += 2;
            break;
        case OP_ADD_B_IDX:
            op_add(state, &state->b, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_ADD_B_EXT:
            op_add(state, &state->b, memory[addr_ext]);
            state->pc += 3;
            break;
        
        case OP_AND_A_IMM:
            op_and(state, &state->a, OP1);
            state->pc += 2;
            break;
        case OP_AND_A_DIR:
            op_and(state, &state->a, memory[OP1]);
            state->pc += 2;
            break;
        case OP_AND_A_IDX:
            op_and(state, &state->a, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_AND_A_EXT:
            op_and(state, &state->a, memory[addr_ext]);
            state->pc += 3;
            break;
        case OP_AND_B_IMM:
            op_and(state, &state->b, OP1);
            state->pc += 2;
            break;
        case OP_AND_B_DIR:
            op_and(state, &state->b, memory[OP1]);
            state->pc += 2;
            break;
        case OP_AND_B_IDX:
            op_and(state, &state->b, memory[OP1+X]);
            state->pc += 2;
            break;
        case OP_AND_B_EXT:
            op_and(state, &state->b, memory[addr_ext]);
            state->pc += 3;
            break;

        case OP_ASL_A    :
            op_asl(state, &state->a);
            state->pc += 1;
        case OP_ASL_B    :
            op_asl(state, &state->b);
            state->pc += 1;
        case OP_ASL_IDX  :
            op_asl(state, &memory[OP1+X]);
            state->pc += 2;
        case OP_ASL_EXT  :
            op_asl(state, &memory[addr_ext]);
            state->pc += 3;
        
        case OP_ASR_A    :
            op_asr(state, &state->a);
            state->pc += 1;
        case OP_ASR_B    :
            op_asr(state, &state->b);
            state->pc += 1;
        case OP_ASR_IDX  :
            op_asr(state, &memory[OP1+X]);
            state->pc += 2;
        case OP_ASR_EXT  :
            op_asr(state, &memory[addr_ext]);
            state->pc += 3;
    
        case OP_BCC      :
            op_branch(state, OP1*GET_FLAG(FLAG_C));
            break;
        case OP_BCS      :
            op_branch(state, OP1*!GET_FLAG(FLAG_C));
            break;
        case OP_BEQ      :
            op_branch(state, OP1*GET_FLAG(FLAG_Z));
            break;
        case OP_BGE      :
            op_branch(state, OP1*!(GET_FLAG(FLAG_N) ^ GET_FLAG(FLAG_V)));
            break;
        case OP_BGT      :
            op_branch(state, OP1*!((GET_FLAG(FLAG_N) ^ GET_FLAG(FLAG_V))));
            break;
        case OP_BHI      :
            op_branch(state, OP1*!(GET_FLAG(FLAG_C) | GET_FLAG(FLAG_Z)));
            break;

        case OP_BIT_A_IMM:
        case OP_BIT_A_DIR:
        case OP_BIT_A_IDX:
        case OP_BIT_A_EXT:
        case OP_BIT_B_IMM:
        case OP_BIT_B_DIR:
        case OP_BIT_B_IDX:
        case OP_BIT_B_EXT:

        case OP_BLE      :
            op_branch(state, OP1*(GET_FLAG(FLAG_N) ^ GET_FLAG(FLAG_V)));
            break;
        case OP_BLS      :
            op_branch(state, OP1*(GET_FLAG(FLAG_C) | GET_FLAG(FLAG_Z)));
            break;
        case OP_BLT      :
            op_branch(state, OP1*(GET_FLAG(FLAG_N) ^ GET_FLAG(FLAG_V)));
            break;
        case OP_BMI      :
            op_branch(state, OP1*GET_FLAG(FLAG_N));
            break;
        case OP_BNE      :
            op_branch(state, OP1*!GET_FLAG(FLAG_Z));
            break;
        case OP_BPL      :
            op_branch(state, OP1*!GET_FLAG(FLAG_N));
            break;
        case OP_BRA      :
            op_branch(state, OP1);
            break;
        case OP_BSR      :
            op_subroutine(state, memory, ((int8_t)OP1)+state->pc+2);
            break;
        case OP_BVC      :
            op_branch(state, OP1*GET_FLAG(FLAG_V));
            break;
        case OP_BVS      :
            op_branch(state, OP1*!GET_FLAG(FLAG_V));
            break;

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
