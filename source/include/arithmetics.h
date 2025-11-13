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

    // ADD instruction
    #define ADD(destination, source) do { \
        _Static_assert( \
            __builtin_types_compatible_p(__typeof__(destination), __typeof__(source)) || \
            IS_INTEGER_LITERAL(source), \
            "destination and source must have the same type or source must be an integer literal" \
        ); \
        int64_t _T1 = (destination); \
        int64_t _T2 = (source); \
        int64_t _RES = _T1 + _T2; \
        (destination) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = ((unsigned)_T1 + (unsigned)_T2 < (unsigned)_T1); \
        _OF = ((_T1 > 0 && _T2 > 0 && _RES < 0) || (_T1 < 0 && _T2 < 0 && _RES > 0)); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while (0)

    // SUB instruction
    #define SUB(destination, source) do { \
        _Static_assert(__builtin_types_compatible_p(__typeof__(destination), __typeof__(source)) || \
                       IS_INTEGER_LITERAL(source), \
                       "destination and source must be the same type or source must be an integer literal"); \
        int64_t _T1 = (destination); \
        int64_t _T2 = (source); \
        int64_t _RES = _T1 - _T2; \
        (destination) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = ((uint64_t)_T1 < (uint64_t)_T2); \
        _OF = ((_T1 < 0 && _T2 > 0 && _RES > 0) || (_T1 > 0 && _T2 < 0 && _RES < 0)); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while(0)

    // MUL instruction
    #define MUL(destination, source) do { \
        _Static_assert(__builtin_types_compatible_p(__typeof__(destination), __typeof__(source)) || \
                       IS_INTEGER_LITERAL(source), \
                       "destination and source must be the same type or source must be an integer literal"); \
        int64_t _T1 = (destination); \
        int64_t _T2 = (source); \
        int64_t _RES = _T1 * _T2; \
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
        int64_t _T1 = (destination); \
        int64_t _T2 = (source); \
        int64_t _RES = (_T2 != 0) ? (_T1 / _T2) : 0; \
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
        int64_t _T1 = (destination); \
        int64_t _T2 = (source); \
        int64_t _RES = (_T2 != 0) ? (_T1 % _T2) : 0; \
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
        int64_t _T = (registry); \
        int64_t _RES = -_T; \
        (registry) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T != 0); \
        _OF = (_T == INT64_MIN); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = ((_T ^ _RES) & 0x10) != 0; \
    } while(0)

    // ABS instruction
    #define ABS(registry) do { \
        int64_t _T = (registry); \
        int64_t _RES = (_T < 0) ? -_T : _T; \
        (registry) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T < 0); \
        _OF = (_T == INT64_MIN); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = ((_T ^ _RES) & 0x10) != 0; \
    } while(0)

    // INC instruction
    #define INC(registry) do { \
        int64_t _T = (registry); \
        int64_t _RES = _T + 1; \
        (registry) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _OF = (_T == INT64_MAX); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T ^ 1 ^ _RES) & 0x10) != 0); \
    } while(0)

    // DEC instruction
    #define DEC(registry) do { \
        int64_t _T = (registry); \
        int64_t _RES = _T - 1; \
        (registry) = _RES; \
        \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _OF = (_T == INT64_MIN); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T ^ 1 ^ _RES) & 0x10) != 0); \
    } while(0)

#endif /* ARITHMETICS_H */
