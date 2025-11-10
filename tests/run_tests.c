#include <stdio.h>
#include <stdlib.h>

extern int test_ADD_positive();
extern int test_ADD_zero_flag();

int main(void) {
    int passed = 0, failed = 0;

    if (test_ADD_positive()) passed++; else failed++;
    if (test_ADD_zero_flag()) passed++; else failed++;

    printf("✅ Passed: %d | ❌ Failed: %d\n", passed, failed);
    return failed ? EXIT_FAILURE : EXIT_SUCCESS;
}
