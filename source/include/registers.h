#pragma once
#ifndef REGISTERS_H
#define REGISTERS_H

    #include <stdint.h>

    // 64-bit register
    typedef union {
        uint64_t qword; // 64-bit full register
        struct { uint32_t lo; /* lower 32 bits */ uint32_t hi; /* upper 32 bits */ };
        struct { uint16_t x[4]; }; // 16-bit halves
        struct { uint8_t b[8]; }; // 8-bit bytes
    } register64_t;

    _Static_assert(sizeof(register64_t) == 8, "register64_t must be 8 bytes");

    // CPU registers enum
    typedef enum {
        REG_RAX, REG_RBX, REG_RCX, REG_RDX,
        REG_RSI, REG_RDI, REG_RSP, REG_RBP,
        REG_R8,  REG_R9,  REG_R10, REG_R11,
        REG_R12, REG_R13, REG_R14, REG_R15
    } RegisterIndex;


    static register64_t _R[16] = {0}; // 64-bit general purpose registers storage
    static uint8_t _ZF = 0, _SF = 0, _CF = 0, _OF = 0, _PF = 0, _AF = 0; // CPU flags (1-bit logical values)

    // 64-bit registers
    #define RAX _R[REG_RAX].qword
    #define RBX _R[REG_RBX].qword
    #define RCX _R[REG_RCX].qword
    #define RDX _R[REG_RDX].qword
    #define RSI _R[REG_RSI].qword
    #define RDI _R[REG_RDI].qword
    #define RSP _R[REG_RSP].qword
    #define RBP _R[REG_RBP].qword
    #define R8  _R[REG_R8].qword
    #define R9  _R[REG_R9].qword
    #define R10 _R[REG_R10].qword
    #define R11 _R[REG_R11].qword
    #define R12 _R[REG_R12].qword
    #define R13 _R[REG_R13].qword
    #define R14 _R[REG_R14].qword
    #define R15 _R[REG_R15].qword

    // 32-bit registers
    #define EAX  _R[REG_RAX].lo
    #define EBX  _R[REG_RBX].lo
    #define ECX  _R[REG_RCX].lo
    #define EDX  _R[REG_RDX].lo
    #define ESI  _R[REG_RSI].lo
    #define EDI  _R[REG_RDI].lo
    #define ESP  _R[REG_RSP].lo
    #define EBP  _R[REG_RBP].lo
    #define R8D  _R[REG_R8].lo
    #define R9D  _R[REG_R9].lo
    #define R10D _R[REG_R10].lo
    #define R11D _R[REG_R11].lo
    #define R12D _R[REG_R12].lo
    #define R13D _R[REG_R13].lo
    #define R14D _R[REG_R14].lo
    #define R15D _R[REG_R15].lo

    // 16-bit registers
    #define AX   _R[REG_RAX].x[0]
    #define BX   _R[REG_RBX].x[0]
    #define CX   _R[REG_RCX].x[0]
    #define DX   _R[REG_RDX].x[0]
    #define SI   _R[REG_RSI].x[0]
    #define DI   _R[REG_RDI].x[0]
    #define SP   _R[REG_RSP].x[0]
    #define BP   _R[REG_RBP].x[0]
    #define R8W  _R[REG_R8].x[0]
    #define R9W  _R[REG_R9].x[0]
    #define R10W _R[REG_R10].x[0]
    #define R11W _R[REG_R11].x[0]
    #define R12W _R[REG_R12].x[0]
    #define R13W _R[REG_R13].x[0]
    #define R14W _R[REG_R14].x[0]
    #define R15W _R[REG_R15].x[0]

    // 8-bit registers
    // Low and high parts for RAX-RDX

    // Endianness support
    #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define BYTE_LO 0
        #define BYTE_HI 1
    #else
        #define BYTE_LO 7
        #define BYTE_HI 6
    #endif

    #define AL _R[REG_RAX].b[BYTE_LO]
    #define AH _R[REG_RAX].b[BYTE_HI]
    #define BL _R[REG_RBX].b[BYTE_LO]
    #define BH _R[REG_RBX].b[BYTE_HI]
    #define CL _R[REG_RCX].b[BYTE_LO]
    #define CH _R[REG_RCX].b[BYTE_HI]
    #define DL _R[REG_RDX].b[BYTE_LO]
    #define DH _R[REG_RDX].b[BYTE_HI]

    // Low 8-bit for others
    #define SIL  _R[REG_RSI].b[BYTE_LO]
    #define DIL  _R[REG_RDI].b[BYTE_LO]
    #define SPL  _R[REG_RSP].b[BYTE_LO]
    #define BPL  _R[REG_RBP].b[BYTE_LO]
    #define R8B  _R[REG_R8].b[BYTE_LO]
    #define R9B  _R[REG_R9].b[BYTE_LO]
    #define R10B _R[REG_R10].b[BYTE_LO]
    #define R11B _R[REG_R11].b[BYTE_LO]
    #define R12B _R[REG_R12].b[BYTE_LO]
    #define R13B _R[REG_R13].b[BYTE_LO]
    #define R14B _R[REG_R14].b[BYTE_LO]
    #define R15B _R[REG_R15].b[BYTE_LO]

#endif /* REGISTERS_H */
