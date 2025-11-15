#include <stdio.h>
#include "include/control.h"
#include "x84-macros-emulator.h"

int main() {

    // ADD(RAX, 0x80);
    // ADD(RAX, RDX);
    // ADD(AH, 0x45);
    // // ADD(RAX, EDX);
    // // ADD(EAX, RDX);
    // DEC(EAX);
    // MOV(RAX, 0x0);
    // DEC(RAX);
    // DEC(RAX);

    MOV(R8, -5);

    //printf("%llu\n", R8);

    LABEL(test)
        INC(R8);
        printf("%llu\n", R8);

    JNZ(test);

    printf("Loop finished");

    //SUB(RAX, 0xFFFFFFFF);
    //ADD(RAX, 0xF);

    //_ADD(RAX, 5);
    //printf("RAX = 0x%016llX | CF=%d ZF=%d SF=%d OF=%d\n", RAX, _CF, _ZF, _SF, _OF);

    return 0;
}
