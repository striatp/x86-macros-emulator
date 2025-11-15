#pragma once
#ifndef CONTROL_H
#define CONTROL_H

    // Jump condition helper function
    #define _JC(condition, label) do { \
        if (condition) goto label; \
    } while (0)

    #define LABEL(name) name:

    #define JMP(label) do { goto label; } while (0)

    #define JE(label) _JC(_ZF, label)
    #define JNE(label) _JC(!_ZF, label)
    #define JZ(label) JE(label)
    #define JNZ(label) JNE(label)

    #define JL(label) _JC(_SF != _OF, label)
    #define JG(label) _JC(!_ZF && (_SF == _OF), label)
    #define JLE(label) _JC(_ZF || (_SF != _OF), label)
    #define JGE(label) _JC(_SF == _OF, label)

    #define JS(label) _JC(_SF, label)
    #define JNS(label) _JC(!_SF, label)

    #define JO(label) _JC(_OF, label)
    #define JNO(label) _JC(!_OF, label)

#endif /* CONTROL_H */
