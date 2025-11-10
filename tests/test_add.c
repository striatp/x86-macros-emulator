#include "../source/cassembly.h"

int test_ADD_positive() {
    _INT a = 5, b = 3;
    _ADD(a, b);
    return (a == 8 && _ZF == 0 && _SF == 0);
}

int test_ADD_zero_flag() {
    _INT a = -3, b = 3;
    _ADD(a, b);
    return (_ZF == 1);
}
