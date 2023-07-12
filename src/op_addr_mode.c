/*
* TODO operation mode
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/

#include "op_addr_mode.h"

#include "types.h"
#include "opcode.h"

uint8_t get_op_addr_mode(uint8_t opcode) {
    switch(opcode) {
        case OP_ABA        :
            return MODE_ACC; 

        case OP_ADC_A_IMM  :
            return MODE_IMM; 
        case OP_ADC_A_DIR  : 
            return MODE_DIR; 
        case OP_ADC_A_IDX  : 
            return MODE_IDX; 
        case OP_ADC_A_EXT  : 
            return MODE_EXT; 
        case OP_ADC_B_IMM  : 
            return MODE_IMM; 
        case OP_ADC_B_DIR  : 
            return MODE_DIR; 
        case OP_ADC_B_IDX  : 
            return MODE_IDX; 
        case OP_ADC_B_EXT  : 
            return MODE_EXT; 
        
        case OP_ADD_A_IMM  : 
            return MODE_IMM; 
        case OP_ADD_A_DIR  : 
            return MODE_DIR; 
        case OP_ADD_A_IDX  : 
            return MODE_IDX; 
        case OP_ADD_A_EXT  : 
            return MODE_EXT; 
        case OP_ADD_B_IMM  : 
            return MODE_IMM; 
        case OP_ADD_B_DIR  : 
            return MODE_DIR; 
        case OP_ADD_B_IDX  : 
            return MODE_IDX; 
        case OP_ADD_B_EXT  : 
            return MODE_EXT; 
        
        case OP_AND_A_IMM  : 
            return MODE_IMM; 
        case OP_AND_A_DIR  : 
            return MODE_DIR; 
        case OP_AND_A_IDX  : 
            return MODE_IDX; 
        case OP_AND_A_EXT  : 
            return MODE_EXT; 
        case OP_AND_B_IMM  : 
            return MODE_IMM; 
        case OP_AND_B_DIR  : 
            return MODE_DIR; 
        case OP_AND_B_IDX  : 
            return MODE_IDX; 
        case OP_AND_B_EXT  : 
            return MODE_EXT; 

        case OP_ASL_A      : 
            return MODE_ACC; 
        case OP_ASL_B      : 
            return MODE_ACC; 
        case OP_ASL_IDX    : 
            return MODE_IDX; 
        case OP_ASL_EXT    : 
            return MODE_EXT; 
        
        case OP_ASR_A      : 
            return MODE_ACC; 
        case OP_ASR_B      : 
            return MODE_ACC; 
        case OP_ASR_IDX    : 
            return MODE_IDX; 
        case OP_ASR_EXT    : 
            return MODE_EXT; 

        case OP_BCC        : 
            return MODE_REL; 
        case OP_BCS        : 
            return MODE_REL; 
        case OP_BEQ        : 
            return MODE_REL; 
        case OP_BGE        : 
            return MODE_REL; 
        case OP_BGT        : 
            return MODE_REL; 
        case OP_BHI        : 
            return MODE_REL; 
        
        case OP_BIT_A_IMM  : 
            return MODE_IMM; 
        case OP_BIT_A_DIR  : 
            return MODE_DIR; 
        case OP_BIT_A_IDX  : 
            return MODE_IDX; 
        case OP_BIT_A_EXT  : 
            return MODE_EXT; 
        case OP_BIT_B_IMM  : 
            return MODE_IMM; 
        case OP_BIT_B_DIR  : 
            return MODE_DIR; 
        case OP_BIT_B_IDX  : 
            return MODE_IDX; 
        case OP_BIT_B_EXT  : 
            return MODE_EXT; 
        
        case OP_BLE        : 
            return MODE_REL; 
        case OP_BLS        : 
            return MODE_REL; 
        case OP_BLT        : 
            return MODE_REL; 
        case OP_BMI        : 
            return MODE_REL; 
        case OP_BNE        : 
            return MODE_REL; 
        case OP_BPL        : 
            return MODE_REL; 
        case OP_BRA        : 
            return MODE_REL; 
        case OP_BSR        : 
            return MODE_REL; 
        case OP_BVC        : 
            return MODE_REL; 
        case OP_BVS        : 
            return MODE_REL; 

        case OP_CBA        :
            return MODE_INH;

        case OP_CLC        : 
            return MODE_INH;
        case OP_CLI        : 
            return MODE_INH;

        case OP_CLR_A      : 
            return MODE_ACC; 
        case OP_CLR_B      : 
            return MODE_ACC; 
        case OP_CLR_IDX    : 
            return MODE_IDX; 
        case OP_CLR_EXT    : 
            return MODE_EXT; 

        case OP_CLV        : 
            return MODE_INH;

        case OP_CMP_A_IMM  : 
            return MODE_IMM; 
        case OP_CMP_A_DIR  : 
            return MODE_DIR; 
        case OP_CMP_A_IDX  : 
            return MODE_IDX; 
        case OP_CMP_A_EXT  : 
            return MODE_EXT; 
        case OP_CMP_B_IMM  : 
            return MODE_IMM; 
        case OP_CMP_B_DIR  : 
            return MODE_DIR; 
        case OP_CMP_B_IDX  : 
            return MODE_IDX; 
        case OP_CMP_B_EXT  : 
            return MODE_EXT; 

        case OP_COM_A      : 
            return MODE_ACC; 
        case OP_COM_B      : 
            return MODE_ACC; 
        case OP_COM_IDX    : 
            return MODE_IDX; 
        case OP_COM_EXT    : 
            return MODE_EXT; 

        case OP_CPX_IMM    : 
            return MODE_IMM; 
        case OP_CPX_DIR    : 
            return MODE_DIR; 
        case OP_CPX_IDX    : 
            return MODE_IDX; 
        case OP_CPX_EXT    : 
            return MODE_EXT; 

        case OP_DAA        :  
            return MODE_INH;
        
        case OP_DEC_A      : 
            return MODE_ACC; 
        case OP_DEC_B      : 
            return MODE_ACC; 
        case OP_DEC_IDX    : 
            return MODE_IDX; 
        case OP_DEC_EXT    : 
            return MODE_EXT; 

        case OP_DES        : 
            return MODE_INH;
        case OP_DEX        : 
            return MODE_INH;

        case OP_EOR_A_IMM  : 
            return MODE_IMM; 
        case OP_EOR_A_DIR  : 
            return MODE_DIR; 
        case OP_EOR_A_IDX  : 
            return MODE_IDX; 
        case OP_EOR_A_EXT  : 
            return MODE_EXT; 
        case OP_EOR_B_IMM  : 
            return MODE_IMM; 
        case OP_EOR_B_DIR  : 
            return MODE_DIR; 
        case OP_EOR_B_IDX  : 
            return MODE_IDX; 
        case OP_EOR_B_EXT  : 
            return MODE_EXT; 
        
        case OP_INC_A      : 
            return MODE_ACC; 
        case OP_INC_B      : 
            return MODE_ACC; 
        case OP_INC_IDX    : 
            return MODE_IDX; 
        case OP_INC_EXT    : 
            return MODE_EXT; 

        case OP_INS        : 
            return MODE_INH;
        case OP_INX        : 
            return MODE_INH;

        case OP_JMP_IDX    : 
            return MODE_IDX; 
        case OP_JMP_EXT    : 
            return MODE_EXT; 

        case OP_JSR_IDX    : 
            return MODE_IDX; 
        case OP_JSR_EXT    : 
            return MODE_EXT; 

        case OP_LDA_A_IMM  : 
            return MODE_IMM; 
        case OP_LDA_A_DIR  : 
            return MODE_DIR; 
        case OP_LDA_A_IDX  : 
            return MODE_IDX; 
        case OP_LDA_A_EXT  : 
            return MODE_EXT; 
        case OP_LDA_B_IMM  : 
            return MODE_IMM; 
        case OP_LDA_B_DIR  : 
            return MODE_DIR; 
        case OP_LDA_B_IDX  : 
            return MODE_IDX; 
        case OP_LDA_B_EXT  : 
            return MODE_EXT; 

        case OP_LDS_IMM    : 
            return MODE_IMM; 
        case OP_LDS_DIR    : 
            return MODE_DIR; 
        case OP_LDS_IDX    : 
            return MODE_IDX; 
        case OP_LDS_EXT    : 
            return MODE_EXT; 

        case OP_LDX_IMM    : 
            return MODE_IMM; 
        case OP_LDX_DIR    : 
            return MODE_DIR; 
        case OP_LDX_IDX    : 
            return MODE_IDX; 
        case OP_LDX_EXT    : 
            return MODE_EXT; 

        case OP_LSR_A      : 
            return MODE_ACC; 
        case OP_LSR_B      : 
            return MODE_ACC; 
        case OP_LSR_IDX    : 
            return MODE_IDX; 
        case OP_LSR_EXT    : 
            return MODE_EXT; 
        
        case OP_NEG_A      : 
            return MODE_ACC; 
        case OP_NEG_B      : 
            return MODE_ACC; 
        case OP_NEG_IDX    : 
            return MODE_IDX; 
        case OP_NEG_EXT    : 
            return MODE_EXT; 

        case OP_NOP        : 
            return MODE_INH;
        
        case OP_ORA_A_IMM  : 
            return MODE_IMM; 
        case OP_ORA_A_DIR  : 
            return MODE_DIR; 
        case OP_ORA_A_IDX  : 
            return MODE_IDX; 
        case OP_ORA_A_EXT  : 
            return MODE_EXT; 
        case OP_ORA_B_IMM  : 
            return MODE_IMM; 
        case OP_ORA_B_DIR  : 
            return MODE_DIR; 
        case OP_ORA_B_IDX  : 
            return MODE_IDX; 
        case OP_ORA_B_EXT  : 
            return MODE_EXT; 

        case OP_PSH_A      : 
            return MODE_ACC; 
        case OP_PSH_B      : 
            return MODE_ACC; 
        
        case OP_PUL_A      : 
            return MODE_ACC; 
        case OP_PUL_B      : 
            return MODE_ACC; 
        
        case OP_ROL_A      : 
            return MODE_ACC; 
        case OP_ROL_B      : 
            return MODE_ACC; 
        case OP_ROL_IDX    : 
            return MODE_IDX; 
        case OP_ROL_EXT    : 
            return MODE_EXT; 

        case OP_ROR_A      : 
            return MODE_ACC; 
        case OP_ROR_B      : 
            return MODE_ACC; 
        case OP_ROR_IDX    : 
            return MODE_IDX; 
        case OP_ROR_EXT    : 
            return MODE_EXT; 

        case OP_RTI        : 
            return MODE_INH;
        case OP_RTS        : 
            return MODE_INH;

        case OP_SBA        : 
            return MODE_INH;
        
        case OP_SBC_A_IMM  : 
            return MODE_IMM; 
        case OP_SBC_A_DIR  : 
            return MODE_DIR; 
        case OP_SBC_A_IDX  : 
            return MODE_IDX; 
        case OP_SBC_A_EXT  : 
            return MODE_EXT; 
        case OP_SBC_B_IMM  : 
            return MODE_IMM; 
        case OP_SBC_B_DIR  : 
            return MODE_DIR; 
        case OP_SBC_B_IDX  : 
            return MODE_IDX; 
        case OP_SBC_B_EXT  : 
            return MODE_EXT; 

        case OP_SEC        : 
            return MODE_INH;
        case OP_SEI        : 
            return MODE_INH;
        case OP_SEV        : 
            return MODE_INH;

        case OP_STA_A_DIR  : 
            return MODE_DIR; 
        case OP_STA_A_IDX  : 
            return MODE_IDX; 
        case OP_STA_A_EXT  : 
            return MODE_EXT; 
        case OP_STA_B_DIR  : 
            return MODE_DIR; 
        case OP_STA_B_IDX  : 
            return MODE_IDX; 
        case OP_STA_B_EXT  : 
            return MODE_EXT; 
       
        case OP_STS_DIR    : 
            return MODE_DIR; 
        case OP_STS_IDX    : 
            return MODE_IDX; 
        case OP_STS_EXT    : 
            return MODE_EXT; 

        case OP_STX_DIR    : 
            return MODE_DIR; 
        case OP_STX_IDX    : 
            return MODE_IDX; 
        case OP_STX_EXT    : 
            return MODE_EXT; 

        case OP_SUB_A_IMM  : 
            return MODE_IMM; 
        case OP_SUB_A_DIR  : 
            return MODE_DIR; 
        case OP_SUB_A_IDX  : 
            return MODE_IDX; 
        case OP_SUB_A_EXT  : 
            return MODE_EXT; 
        case OP_SUB_B_IMM  : 
            return MODE_IMM; 
        case OP_SUB_B_DIR  : 
            return MODE_DIR; 
        case OP_SUB_B_IDX  : 
            return MODE_IDX; 
        case OP_SUB_B_EXT  : 
            return MODE_EXT; 

        case OP_SWI        : 
            return MODE_INH;

        case OP_TAB        : 
            return MODE_INH;
        case OP_TAP        : 
            return MODE_INH;
        case OP_TBA        : 
            return MODE_INH;
        case OP_TPA        : 
            return MODE_INH;

        case OP_TST_A      : 
            return MODE_ACC; 
        case OP_TST_B      : 
            return MODE_ACC; 
        case OP_TST_IDX    : 
            return MODE_IDX; 
        case OP_TST_EXT    : 
            return MODE_EXT; 

        case OP_TSX        : 
            return MODE_INH;

        case OP_TXS        : 
            return MODE_INH;

    }
}
