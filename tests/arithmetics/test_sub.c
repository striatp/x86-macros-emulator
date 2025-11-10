#include "../../source/cassembly.h"

/* Positive subtraction */
int test_SUB_positive() {
    _INT a = 10, b = 3;
    _SUB(a, b);
    return (a == 7 && _ZF == 0 && _SF == 0);
}

/* Zero Flag */
int test_SUB_zero_flag() {
    _INT a = 5, b = 5;
    _SUB(a, b);
    return (_ZF == 1);
}

/* Sign Flag */
int test_SUB_sign_flag() {
    _INT a = 3, b = 5;
    _SUB(a, b);
    return (_SF == 1 && _ZF == 0);
}

/* Carry Flag (unsigned borrow) */
int test_SUB_carry_flag() {
    _INT a = 3, b = 5;
    _SUB(a, b);
    return (_CF == 1);
}

/* Overflow Flag (signed overflow) */
int test_SUB_overflow_flag() {
    _INT a = 0x80000000; // INT_MIN
    _INT b = 1;
    _SUB(a, b);
    return (_OF == 1);
}

/* Parity Flag (even parity = 1) */
int test_SUB_parity_flag() {
    _INT a = 6;
    _INT b = 0;
    _SUB(a, b);
    return (_PF == 1);
}

/* Auxiliary Carry Flag */
int test_SUB_aux_carry_flag() {
    _INT a = 0x10;
    _INT b = 1;
    _SUB(a, b);
    return (_AF == 1);
}

/* Combined test: Zero + Sign + Overflow */
int test_SUB_combined_flags() {
    _INT a = -5;
    _INT b = -5;
    _SUB(a, b);
    return (_ZF == 1 && _SF == 0 && _OF == 0);
}
