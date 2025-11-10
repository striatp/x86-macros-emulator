#pragma once
#ifndef DATA_H
#define DATA_H

    #define _MOV(destination, source) do { \
        _INT _T = (source); \
        (destination) = _T; \
        \
        /* Update flags register */ \
        _ZF = (_T == 0); \
        _SF = (_T < 0); \
        _CF = 0; \
        _OF = 0; \
        _PF = (__builtin_parity((unsigned)_T) == 0); \
        _AF = 0; \
    } while (0)

    #define _XCHG(a, b) do { \
        if (&(a) != &(b)) { \
            _INT _tmp = (a); \
            (a) = (b); \
            (b) = _tmp; \
        } \
    } while (0)

    #define _XCHGT(a, b) _XCHG(a, b) /* alias, just a name variant */

#endif /* DATA_H */
