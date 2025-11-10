#pragma once
#ifndef REGISTRIES_H
#define REGISTRIES_H

    #include "system.h"

    static int32_t _R[16];
    static int32_t _ZF, _SF, _CF, _OF, _PF, _AF;

    #define _R0  _R[0]
    #define _R1  _R[1]
    #define _R2  _R[2]
    #define _R3  _R[3]
    #define _R4  _R[4]
    #define _R5  _R[5]
    #define _R6  _R[6]
    #define _R7  _R[7]
    #define _R8  _R[8]
    #define _R9  _R[9]
    #define _R10 _R[10]
    #define _R11 _R[11]
    #define _R12 _R[12]
    #define _R13 _R[13]
    #define _R14 _R[14]
    #define _R15 _R[15]

    #define EAX _R0
    #define EBX _R1
    #define ECX _R2
    #define EDX _R3
    #define ESI _R4
    #define EDI _R5
    #define EBP _R6
    #define ESP _R7

    #define AX (_R0 & 0xFFFF)
    #define BX (_R1 & 0xFFFF)
    #define CX (_R2 & 0xFFFF)
    #define DX (_R3 & 0xFFFF)

    #define AL (_R0 & 0xFF)
    #define AH ((_R0 >> 8) & 0xFF)
    #define BL (_R1 & 0xFF)
    #define BH ((_R1 >> 8) & 0xFF)

#endif /* REGISTRIES_H */
