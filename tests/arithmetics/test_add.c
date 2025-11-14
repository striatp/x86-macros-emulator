#include "../../source/x84-macros-emulator.h"
#include <stdint.h>
#include <stdio.h>

/* Positive addition */
int test_ADD_positive() {
    _INT a = 5, b = 3;
    ADD(a, b);
    return (a == 8 && _ZF == 0 && _SF == 0);
}

/* Zero Flag */
int test_ADD_zero_flag() {
    _INT a = -3, b = 3;
    ADD(a, b);
    return (_ZF == 1);
}

/* Sign Flag */
int test_ADD_sign_flag() {
    _INT a = -5, b = -3;
    ADD(a, b);
    return (_SF == 1 && _ZF == 0);
}

/* Carry Flag (unsigned overflow) */
int test_ADD_carry_flag() {
    _INT a = 0xFFFFFFFF, b = 1;
    ADD(a, b);
    return (_CF == 1);
}

/* Overflow Flag (signed overflow) */
int test_ADD_overflow_flag() {
    _INT a = 0x7FFFFFFF;
    _INT b = 1;
    ADD(a, b);
    printf("a = %d, b = %d, OF = %d\n", a, b, _OF);
    return (_OF == 1);
}

/* Parity Flag (even parity = 1) */
int test_ADD_parity_flag() {
    int64_t a = 0x7FFFFFFFFFFFFFFF;
    int64_t b = 1;
    ADD(a, b);
    return (_OF == 1);
}

/* Auxiliary Carry Flag */
int test_ADD_aux_carry_flag() {
    _INT a = 0x0F;
    _INT b = 1;
    ADD(a, b);
    return (_AF == 1);
}

/* Combined test: Zero + Sign + Overflow */
int test_ADD_combined_flags() {
    _INT a = -1;
    _INT b = 1;
    ADD(a, b);
    return (_ZF == 1 && _SF == 0 && _OF == 0);
}
