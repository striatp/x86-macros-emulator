#pragma once
#ifndef REGISTERS_H
#define REGISTERS_H

    #include <stdint.h>

    // 64-bit register
    typedef union {
        int64_t qword; // 64-bit full register
        struct {
            int32_t lo; // lower 32 bits
            int32_t hi; // upper 32 bits
        };
        struct {
            int16_t x[4]; // 16-bit halves
        };
        struct {
            uint8_t b[8]; // 8-bit bytes
        };
    } register64_t;

    static register64_t _R[16]; // 64-bit general purpose registers storage
    static uint8_t _ZF, _SF, _CF, _OF, _PF, _AF; // CPU flags (1-bit logical values)

    // 64-bit registers
    #define RAX _R[0].qword
    #define RBX _R[1].qword
    #define RCX _R[2].qword
    #define RDX _R[3].qword
    #define RSI _R[4].qword
    #define RDI _R[5].qword
    #define RSP _R[6].qword
    #define RBP _R[7].qword
    #define R8  _R[8].qword
    #define R9  _R[9].qword
    #define R10 _R[10].qword
    #define R11 _R[11].qword
    #define R12 _R[12].qword
    #define R13 _R[13].qword
    #define R14 _R[14].qword
    #define R15 _R[15].qword

    // 32-bit registers
    #define EAX  _R[0].lo
    #define EBX  _R[1].lo
    #define ECX  _R[2].lo
    #define EDX  _R[3].lo
    #define ESI  _R[4].lo
    #define EDI  _R[5].lo
    #define ESP  _R[6].lo
    #define EBP  _R[7].lo
    #define R8D  _R[8].lo
    #define R9D  _R[9].lo
    #define R10D _R[10].lo
    #define R11D _R[11].lo
    #define R12D _R[12].lo
    #define R13D _R[13].lo
    #define R14D _R[14].lo
    #define R15D _R[15].lo

    // 16-bit registers
    #define AX   _R[0].x[0]
    #define BX   _R[1].x[0]
    #define CX   _R[2].x[0]
    #define DX   _R[3].x[0]
    #define SI   _R[4].x[0]
    #define DI   _R[5].x[0]
    #define SP   _R[6].x[0]
    #define BP   _R[7].x[0]
    #define R8W  _R[8].x[0]
    #define R9W  _R[9].x[0]
    #define R10W _R[10].x[0]
    #define R11W _R[11].x[0]
    #define R12W _R[12].x[0]
    #define R13W _R[13].x[0]
    #define R14W _R[14].x[0]
    #define R15W _R[15].x[0]

    // 8-bit registers
    // Low and high parts for RAX-RDX
    #define AL _R[0].b[0]
    #define AH _R[0].b[1]
    #define BL _R[1].b[0]
    #define BH _R[1].b[1]
    #define CL _R[2].b[0]
    #define CH _R[2].b[1]
    #define DL _R[3].b[0]
    #define DH _R[3].b[1]

    // Low 8-bit for others
    #define SIL  _R[4].b[0]
    #define DIL  _R[5].b[0]
    #define SPL  _R[6].b[0]
    #define BPL  _R[7].b[0]
    #define R8B  _R[8].b[0]
    #define R9B  _R[9].b[0]
    #define R10B _R[10].b[0]
    #define R11B _R[11].b[0]
    #define R12B _R[12].b[0]
    #define R13B _R[13].b[0]
    #define R14B _R[14].b[0]
    #define R15B _R[15].b[0]

#endif /* REGISTERS_H */
