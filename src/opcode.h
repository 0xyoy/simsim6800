/*
* operation codes, sorted alphabetically. i purposefully omit flags related to interrupts
* (C) 2023 Anna Niemiec (anna at brokelove dot online)
* this code is licensed under GNU GPLv3. see LICENSE for details
*/

#ifndef OPCODE
#define OPCODE

enum opcode {
    OP_ABA          = 0x1b,

    OP_ADC_A_IMM    = 0x89,
    OP_ADC_A_DIR    = 0x99,
    OP_ADC_A_IDX    = 0xa9,
    OP_ADC_A_EXT    = 0xb9,
    OP_ADC_B_IMM    = 0xc9,
    OP_ADC_B_DIR    = 0xd9,
    OP_ADC_B_IDX    = 0xe9,
    OP_ADC_B_EXT    = 0xf9,
    
    OP_ADD_A_IMM    = 0x8b,
    OP_ADD_A_DIR    = 0x9b,
    OP_ADD_A_IDX    = 0xab,
    OP_ADD_A_EXT    = 0xbb,
    OP_ADD_B_IMM    = 0xcb,
    OP_ADD_B_DIR    = 0xdb,
    OP_ADD_B_IDX    = 0xeb,
    OP_ADD_B_EXT    = 0xfb,
    
    OP_AND_A_IMM    = 0x84,
    OP_AND_A_DIR    = 0x94,
    OP_AND_A_IDX    = 0xa4,
    OP_AND_A_EXT    = 0xb4,
    OP_AND_B_IMM    = 0xc4,
    OP_AND_B_DIR    = 0xd4,
    OP_AND_B_IDX    = 0xe4,
    OP_AND_B_EXT    = 0xf4,

    OP_ASL_A        = 0x48,
    OP_ASL_B        = 0x58,
    OP_ASL_IDX      = 0x68,
    OP_ASL_EXT      = 0x78,
    
    OP_ASR_A        = 0x47,
    OP_ASR_B        = 0x57,
    OP_ASR_IDX      = 0x67,
    OP_ASR_EXT      = 0x77,

    OP_BCC          = 0x24,
    OP_BCS          = 0x25,
    OP_BEQ          = 0x27,
    OP_BGE          = 0x2c,
    OP_BGT          = 0x2e,
    OP_BHI          = 0x22,
    
    OP_BIT_A_IMM    = 0x85,
    OP_BIT_A_DIR    = 0x95,
    OP_BIT_A_IDX    = 0xa5,
    OP_BIT_A_EXT    = 0xb5,
    OP_BIT_B_IMM    = 0xc5,
    OP_BIT_B_DIR    = 0xd5,
    OP_BIT_B_IDX    = 0xe5,
    OP_BIT_B_EXT    = 0xf5,
    
    OP_BLE          = 0x2f,
    OP_BLS          = 0x23,
    OP_BLT          = 0x2d,
    OP_BMI          = 0x2b,
    OP_BNE          = 0x26,
    OP_BPL          = 0x2a,
    OP_BRA          = 0x20,
    OP_BSR          = 0x8d,
    OP_BVC          = 0x28,
    OP_BVS          = 0x29,

    OP_CBA          = 0x11,

    OP_CLC          = 0x0c,
    OP_CLI          = 0x0e,

    OP_CLR_A        = 0x4f,
    OP_CLR_B        = 0x5f,
    OP_CLR_IDX      = 0x6f,
    OP_CLR_EXT      = 0x7f,

    OP_CLV          = 0x0a,

    OP_CMP_A_IMM    = 0x81,
    OP_CMP_A_DIR    = 0x91,
    OP_CMP_A_IDX    = 0xa1,
    OP_CMP_A_EXT    = 0xb1,
    OP_CMP_B_IMM    = 0xc1,
    OP_CMP_B_DIR    = 0xd1,
    OP_CMP_B_IDX    = 0xe1,
    OP_CMP_B_EXT    = 0xf1,

    OP_COM_A        = 0x43,
    OP_COM_B        = 0x53,
    OP_COM_IDX      = 0x63,
    OP_COM_EXT      = 0x73,

    OP_CPX_IMM      = 0x8c,
    OP_CPX_DIR      = 0x9c,
    OP_CPX_IDX      = 0xac,
    OP_CPX_EXT      = 0xbc,

    OP_DAA          = 0x19, 
    
    OP_DEC_A        = 0x4a,
    OP_DEC_B        = 0x5a,
    OP_DEC_IDX      = 0x6a,
    OP_DEC_EXT      = 0x7a,

    OP_DES          = 0x34,
    OP_DEX          = 0x09,

    OP_EOR_A_IMM    = 0x88,
    OP_EOR_A_DIR    = 0x98,
    OP_EOR_A_IDX    = 0xa8,
    OP_EOR_A_EXT    = 0xb8,
    OP_EOR_B_IMM    = 0xc8,
    OP_EOR_B_DIR    = 0xd8,
    OP_EOR_B_IDX    = 0xe8,
    OP_EOR_B_EXT    = 0xf8,
    
    OP_INC_A        = 0x4c,
    OP_INC_B        = 0x5c,
    OP_INC_IDX      = 0x6c,
    OP_INC_EXT      = 0x7c,

    OP_INS          = 0x31,
    OP_INX          = 0x08,

    OP_JMP_IDX      = 0x6e,
    OP_JMP_EXT      = 0x7e,

    OP_JSR_IDX      = 0xad,
    OP_JSR_EXT      = 0xbd,

    OP_LDA_A_IMM    = 0x86,
    OP_LDA_A_DIR    = 0x96,
    OP_LDA_A_IDX    = 0xa6,
    OP_LDA_A_EXT    = 0xb6,
    OP_LDA_B_IMM    = 0xc6,
    OP_LDA_B_DIR    = 0xd6,
    OP_LDA_B_IDX    = 0xe6,
    OP_LDA_B_EXT    = 0xf6,

    OP_LDS_IMM      = 0x8e,
    OP_LDS_DIR      = 0x9e,
    OP_LDS_IDX      = 0xae,
    OP_LDS_EXT      = 0xbe,

    OP_LDX_IMM      = 0xce,
    OP_LDX_DIR      = 0xde,
    OP_LDX_IDX      = 0xee,
    OP_LDX_EXT      = 0xfe,

    OP_LSR_A        = 0x44,
    OP_LSR_B        = 0x54,
    OP_LSR_IDX      = 0x64,
    OP_LSR_EXT      = 0x74,
    
    OP_NEG_A        = 0x40,
    OP_NEG_B        = 0x50,
    OP_NEG_IDX      = 0x60,
    OP_NEG_EXT      = 0x70,

    OP_NOP          = 0x01,
    
    OP_ORA_A_IMM    = 0x8a,
    OP_ORA_A_DIR    = 0x9a,
    OP_ORA_A_IDX    = 0xaa,
    OP_ORA_A_EXT    = 0xba,
    OP_ORA_B_IMM    = 0xca,
    OP_ORA_B_DIR    = 0xda,
    OP_ORA_B_IDX    = 0xea,
    OP_ORA_B_EXT    = 0xfa,

    OP_PSH_A        = 0x36,
    OP_PSH_B        = 0x37,
    
    OP_PUL_A        = 0x32,
    OP_PUL_B        = 0x33,
    
    OP_ROL_A        = 0x49,
    OP_ROL_B        = 0x59,
    OP_ROL_IDX      = 0x69,
    OP_ROL_EXT      = 0x79,

    OP_ROR_A        = 0x46,
    OP_ROR_B        = 0x56,
    OP_ROR_IDX      = 0x66,
    OP_ROR_EXT      = 0x76,

    OP_RTI          = 0x3b,
    OP_RTS          = 0x39,

    OP_SBA          = 0x10,
    
    OP_SBC_A_IMM    = 0x82,
    OP_SBC_A_DIR    = 0x92,
    OP_SBC_A_IDX    = 0xa2,
    OP_SBC_A_EXT    = 0xb2,
    OP_SBC_B_IMM    = 0xc2,
    OP_SBC_B_DIR    = 0xd2,
    OP_SBC_B_IDX    = 0xe2,
    OP_SBC_B_EXT    = 0xf2,

    OP_SEC          = 0x0d,
    OP_SEI          = 0x0f,
    OP_SEV          = 0x0b,

    OP_STA_A_DIR    = 0x97,
    OP_STA_A_IDX    = 0xa7,
    OP_STA_A_EXT    = 0xb7,
    OP_STA_B_DIR    = 0xd7,
    OP_STA_B_IDX    = 0xe7,
    OP_STA_B_EXT    = 0xf7,
   
    OP_STS_DIR      = 0x9f,
    OP_STS_IDX      = 0xaf,
    OP_STS_EXT      = 0xbf,

    OP_STX_DIR      = 0xdf,
    OP_STX_IDX      = 0xef,
    OP_STX_EXT      = 0xff,

    OP_SUB_A_IMM    = 0x80,
    OP_SUB_A_DIR    = 0x90,
    OP_SUB_A_IDX    = 0xa0,
    OP_SUB_A_EXT    = 0xb0,
    OP_SUB_B_IMM    = 0xc0,
    OP_SUB_B_DIR    = 0xd0,
    OP_SUB_B_IDX    = 0xe0,
    OP_SUB_B_EXT    = 0xf0,

    OP_SWI          = 0x3f,

    OP_TAB          = 0x16,
    OP_TAP          = 0x06,
    OP_TBA          = 0x17,
    OP_TPA          = 0x07,

    OP_TST_A        = 0x4d,
    OP_TST_B        = 0x5d,
    OP_TST_IDX      = 0x6d,
    OP_TST_EXT      = 0x7d,

    OP_TSX          = 0x30,

    OP_TXS          = 0x35
};
#endif
