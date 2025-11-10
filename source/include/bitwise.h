#ifndef BITWISE_H
#define BITWISE_H
#pragma once

    #define _AND(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = _T1 & _T2; \
        (destination) = _RES; \
        \
        /* Flags */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _CF = 0; \
        _OF = 0; \
        _AF = 0; \
    } while (0)

    #define _OR(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = _T1 | _T2; \
        (destination) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _CF = 0; \
        _OF = 0; \
        _AF = 0; \
    } while (0)

    #define _XOR(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = _T1 ^ _T2; \
        (destination) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _CF = 0; \
        _OF = 0; \
        _AF = 0; \
    } while (0)

    #define _NOT(registry) do { \
        _INT _RES = ~(registry); \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _CF = 0; \
        _OF = 0; \
        _AF = 0; \
    } while (0)

    #define _SHL(registry, n) do { \
        _INT _T = (registry); \
        _INT _RES = _T << (n); \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _CF = (_T >> (32 - (n)) & 1); /* last bit shifted out */ \
        _OF = ((reg & (1 << 31)) != (_T & (1 << 31))); \
        _AF = 0; \
    } while (0)

    #define _SHR(registry, n) do { \
        _INT _T = (registry); \
        _INT _RES = (u32)_T >> (n); \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _CF = (_T >> (n-1)) & 1; /* last bit shifted out */ \
        _OF = (_T & (1 << 31)) != 0; \
        _AF = 0; \
    } while (0)

    #define _SAR(registry, n) do { \
        _INT _T = (registry); \
        _INT _RES = _T >> (n); \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _CF = (_T >> (n-1)) & 1; \
        _OF = 0; \
        _AF = 0; \
    } while (0)

    #define _ROL(registry, n) do { \
        _INT _T = (registry); \
        _INT _RES = (_T << (n)) | ((u32)_T >> (32 - (n))); \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _CF = (_RES & 1); \
        _OF = ((_RES >> 31) ^ (_RES & 1)); \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = 0; \
    } while (0)

    #define _ROR(registry, n) do { \
        _INT _T = (registry); \
        _INT _RES = ((u32)_T >> (n)) | (_T << (32 - (n))); \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _CF = (_RES >> 31) & 1; \
        _OF = ((_RES >> 31) ^ (_RES >> 30)) & 1; \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = 0; \
    } while (0)

    #define _BT(value, bit) (((value) >> (bit)) & 1)
    #define _BTS(registry, bit) ((registry) |= (1 << (bit)))
    #define _BTR(registry, bit) ((registry) &= ~(1 << (bit)))
    #define _BTC(registry, bit) ((registry) ^= (1 << (bit)))

#endif /* BITWISE_H */
