#include <stdio.h>
#include "cassembly.h"

int main(void) {

    _MOV(EAX, 1);
    _MOV(EBX, 2);

    _ADD(EAX, EBX);

    printf("%d, %d, %d\n", _ZF, _SF, _CF);
    printf("%d", EAX); // outputs: 3

    return 0;
}
