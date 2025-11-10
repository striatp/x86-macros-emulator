#ifndef ARITHMETICS_H
#define ARITHMETICS_H
#pragma once

    #define _ADD(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = _T1 + _T2; \
        (destination) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = ((unsigned)_T1 + (unsigned)_T2 < (unsigned)_T1); \
        _OF = ((_T1 > 0 && _T2 > 0 && _RES < 0) || (_T1 < 0 && _T2 < 0 && _RES > 0)); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while (0)

    #define _SUB(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = _T1 - _T2; \
        (destination) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = ((unsigned)_T1 < (unsigned)_T2); \
        _OF = ((_T1 < 0 && _T2 > 0 && _RES > 0) || (_T1 > 0 && _T2 < 0 && _RES < 0)); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while (0)

    #define _MUL(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = _T1 * _T2; \
        (destination) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T1 != 0 && _RES / _T1 != _T2); \
        _OF = (_T1 != 0 && _RES / _T1 != _T2); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while (0)

    #define _IMUL(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = _T1 * _T2; \
        (destination) = _RES; \
        \
        /* Update flags */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T1 != 0 && _RES / _T1 != _T2); \
        _OF = (_T1 != 0 && _RES / _T1 != _T2); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T1 ^ _T2 ^ _RES) & 0x10) != 0); \
    } while (0)

    #define _DIV(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = (_T2 != 0) ? (_T1 / _T2) : 0; \
        (destination) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = 0; \
        _OF = 0; \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = 0; \
    } while (0)

    #define _IDIV(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = (_T2 != 0) ? (_T1 / _T2) : 0; \
        (destination) = _RES; \
        \
        /* Update flags */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = 0; \
        _OF = 0; \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = 0; \
    } while (0)

    #define _MOD(destination, source) do { \
        _INT _T1 = (destination); \
        _INT _T2 = (source); \
        _INT _RES = (_T2 != 0) ? (_T1 % _T2) : 0; \
        (destination) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = 0; \
        _OF = 0; \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = 0; \
    } while (0)

    #define _NEG(registry) do { \
        _INT _T = (registry); \
        _INT _RES = -_T; \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T != 0); \
        _OF = (_T == _INT32_MIN); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = ((_T ^ _RES) & 0x10) != 0; \
    } while (0)

    #define _ABS(registry) do { \
        _INT _T = (registry); \
        _INT _RES = (_T < 0) ? -_T : _T; \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _CF = (_T < 0); \
        _OF = (_T == _INT32_MIN); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = ((_T ^ _RES) & 0x10) != 0; \
    } while (0)

    #define _INC(registry) do { \
        _INT _T = (registry); \
        _INT _RES = _T + 1; \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _OF = (_T == _INT32_MAX); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T ^ 1 ^ _RES) & 0x10) != 0); \
    } while (0)

    #define _DEC(registry) do { \
        _INT _T = (registry); \
        _INT _RES = _T - 1; \
        (registry) = _RES; \
        \
        /* Update flags register */ \
        _ZF = (_RES == 0); \
        _SF = (_RES < 0); \
        _OF = (_T == _INT32_MIN); \
        _PF = (__builtin_parity((unsigned)_RES) == 0); \
        _AF = (((_T ^ 1 ^ _RES) & 0x10) != 0); \
    } while (0)

#endif /* ARITHMETICS_H */
