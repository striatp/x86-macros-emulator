#pragma once
#ifndef DATA_H
#define DATA_H

    #include <stdint.h>

    #define MOV(destination, source) do { \
        int64_t _T = (source); \
        (destination) = _T; \
    } while (0)

    #define XCHG(a, b) do { \
        if (&(a) != &(b)) { \
            _INT _tmp = (a); \
            (a) = (b); \
            (b) = _tmp; \
        } \
    } while (0)

    #define XCHGT(a, b) _XCHG(a, b) /* alias, just a name variant */

#endif /* DATA_H */
