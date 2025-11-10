#pragma once
#ifndef CONTROL_H
#define CONTROL_H

    #define _LABEL(name) name:
    #define _LBL(name) LABEL(name)

    #define _JMP(label) do { \
        goto label; \
    } while (0)

    #define _JE(label) do { \
        if (_ZF) { \
            goto label; \
        } \
    } while (0)

    #define _JNE(label) do { \
        if (!_ZF) { \
            goto label; \
        } \
    } while (0)

    #define _JZ(label) _JE(label)
    #define _JNZ(label) _JNE(label)

    #define _JL(label) do { \
        if (_SF != _OF) { \
            goto label; \
        } \
    } while (0)

    #define _JG(label) do { \
        if (!_ZF && (_SF == _OF)) { \
            goto label; \
        } \
    } while (0)

    #define _JLE(label) do { \
        if (_ZF || (_SF != _OF)) { \
            goto label; \
        } \
    } while (0)

    #define _JGE(label) do { \
        if (_SF == _OF) { \
            goto label; \
        } \
    } while (0)

    #define _JS(label) do { \
        if (_SF) { \
            goto label; \
        } \
    } while (0)

    #define _JNS(label) do { \
        if (!_SF) { \
            goto label; \
        } \
    } while (0)

    #define _JO(label) do { \
        if (_OF) { \
            goto label; \
        } \
    } while (0)

    #define _JNO(label) do { \
        if (!_OF) { \
            goto label; \
        } \
    } while (0)

#endif /* CONTROL_H */
