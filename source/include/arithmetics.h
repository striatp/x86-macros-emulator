#pragma once
#ifndef ARITHMETICS_H
#define ARITHMETICS_H

    #include <stdint.h>

    // Checks type compability
    #define IS_INTEGER_LITERAL(x) ( \
        __builtin_constant_p(x) && ( \
            __builtin_types_compatible_p(__typeof__(x), int) || \
            __builtin_types_compatible_p(__typeof__(x), long) || \
            __builtin_types_compatible_p(__typeof__(x), long long) || \
            __builtin_types_compatible_p(__typeof__(x), unsigned int) || \
            __builtin_types_compatible_p(__typeof__(x), unsigned long) || \
            __builtin_types_compatible_p(__typeof__(x), unsigned long long) ) )

    // Converts to 'unsigned X'
    #define TO_UNSIGNED(x) _Generic((x), \
        char: (unsigned char)(x), \
        signed char: (unsigned char)(x), \
        short: (unsigned short)(x), \
        int: (unsigned int)(x), \
        long: (unsigned long)(x), \
        long long: (unsigned long long)(x), \
        default: (unsigned long long)(x) /* fallback */ \
    )

    // ADD instruction
    #define ADD(destination, source) do { \
        _Static_assert( \
            __builtin_types_compatible_p(__typeof__(destination), __typeof__(source)) || \
            IS_INTEGER_LITERAL(source), \
            "destination and source must have the same type or source must be an integer literal" \
        ); \
        __typeof__(destination) _T1 = (destination); \
        __typeof__(source) _T2 = (source); \
        __typeof__(destination) _RES = _T1 + _T2; \
        (destination) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (TO_UNSIGNED(_T1) + TO_UNSIGNED(_T2) < TO_UNSIGNED(_T1)); \
        _OF = ((_T1 > 0 && _T2 > 0 && _RES < 0) || (_T1 < 0 && _T2 < 0 && _RES > 0)); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while (0)

    // SUB instruction
    #define SUB(destination, source) do { \
        _Static_assert(__builtin_types_compatible_p(__typeof__(destination), __typeof__(source)) || \
                       IS_INTEGER_LITERAL(source), \
                       "destination and source must be the same type or source must be an integer literal"); \
        __typeof__(destination) _T1 = (destination); \
        __typeof__(source) _T2 = (source); \
        __typeof__(destination) _RES = _T1 - _T2; \
        (destination) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (TO_UNSIGNED(_T1) < TO_UNSIGNED(_T2)); \
        _OF = ((_T1 < 0 && _T2 > 0 && _RES > 0) || (_T1 > 0 && _T2 < 0 && _RES < 0)); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while(0)

    // MUL instruction
    #define MUL(destination, source) do { \
        _Static_assert(__builtin_types_compatible_p(__typeof__(destination), __typeof__(source)) || \
                       IS_INTEGER_LITERAL(source), \
                       "destination and source must be the same type or source must be an integer literal"); \
        __typeof__(destination) _T1 = (destination); \
        __typeof__(source) _T2 = (source); \
        __typeof__(destination) _RES = _T1 * _T2; \
        (destination) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T1 != 0 && _RES / _T1 != _T2); \
        _OF = (_T1 != 0 && _RES / _T1 != _T2); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while(0)

    // DIV instruction
    #define DIV(destination, source) do { \
        _Static_assert(__builtin_types_compatible_p(__typeof__(destination), __typeof__(source)) || \
                       IS_INTEGER_LITERAL(source), \
                       "destination and source must be the same type or source must be an integer literal"); \
        __typeof__(destination) _T1 = (destination); \
        __typeof__(source) _T2 = (source); \
        __typeof__(destination) _RES = (_T2 != 0) ? (_T1 / _T2) : 0; \
        (destination) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = 0; \
        _OF = 0; \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = 0; \
    } while(0)

    // MOD instruction
    #define MOD(destination, source) do { \
        _Static_assert(__builtin_types_compatible_p(__typeof__(destination), __typeof__(source)) || \
                       IS_INTEGER_LITERAL(source), \
                       "destination and source must be the same type or source must be an integer literal"); \
        __typeof__(destination) _T1 = (destination); \
        __typeof__(source) _T2 = (source); \
        __typeof__(destination) _RES = (_T2 != 0) ? (_T1 % _T2) : 0; \
        (destination) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = 0; \
        _OF = 0; \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = 0; \
    } while(0)

    // NEG instruction
    #define NEG(registry) do { \
        __typeof__(registry) _T = (registry); \
        __typeof__(registry) _RES = -_T; \
        (registry) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T != 0); \
        _OF = (_T == ((__typeof__(_T))1 << (sizeof(_T)*8 - 1))); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = ((_T ^ _RES) & 0x10) != 0; \
    } while(0)

    // ABS instruction
    #define ABS(registry) do { \
        __typeof__(registry) _T = (registry); \
        __typeof__(registry) _RES = (_T < 0) ? -_T : _T; \
        (registry) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T < 0); \
        _OF = (_T == ((__typeof__(_T))1 << (sizeof(_T)*8 - 1))); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = ((_T ^ _RES) & 0x10) != 0; \
    } while(0)

    // INC instruction
    #define INC(registry) do { \
        __typeof__(registry) _T = (registry); \
        __typeof__(registry) _RES = _T + 1; \
        (registry) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _OF = (_T == ((__typeof__(_T))1 << (sizeof(_T)*8 - 1))); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T ^ 1 ^ _RES) & 0x10) != 0); \
    } while(0)

    // DEC instruction
    #define DEC(registry) do { \
        __typeof__(registry) _T = (registry); \
        __typeof__(registry) _RES = _T - 1; \
        (registry) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _OF = (_T == ((__typeof__(_T))1 << (sizeof(_T)*8 - 1))); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T ^ 1 ^ _RES) & 0x10) != 0); \
    } while(0)

#endif /* ARITHMETICS_H */
