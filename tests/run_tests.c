#include <stdio.h>
#include <stdlib.h>

/* ================================================================== */
/*                       Arithmetic Instructions                      */
/* ================================================================== */

extern int test_ADD_positive();
extern int test_ADD_zero_flag();
extern int test_ADD_sign_flag();
extern int test_ADD_carry_flag();
extern int test_ADD_overflow_flag();
extern int test_ADD_parity_flag();
extern int test_ADD_aux_carry_flag();
extern int test_ADD_combined_flags();

extern int test_SUB_positive();
extern int test_SUB_zero_flag();
extern int test_SUB_sign_flag();
extern int test_SUB_carry_flag();
extern int test_SUB_overflow_flag();
extern int test_SUB_parity_flag();
extern int test_SUB_aux_carry_flag();
extern int test_SUB_combined_flags();

void run_ADD_tests(int *passed, int *failed) {
    #define RUN_TEST(fn) \
        do { \
            if (fn()) { \
                printf("PASS: %s\n", #fn); \
                (*passed)++; \
            } else { \
                printf("FAIL: %s\n", #fn); \
                (*failed)++; \
            } \
        } while (0)

    RUN_TEST(test_ADD_positive);
    RUN_TEST(test_ADD_zero_flag);
    RUN_TEST(test_ADD_sign_flag);
    RUN_TEST(test_ADD_carry_flag);
    RUN_TEST(test_ADD_overflow_flag);
    RUN_TEST(test_ADD_parity_flag);
    RUN_TEST(test_ADD_aux_carry_flag);
    RUN_TEST(test_ADD_combined_flags);

    #undef RUN_TEST

    if (*failed) {
        exit(EXIT_FAILURE);
    }
}

void run_SUB_tests(int *passed, int *failed) {
    #define RUN_TEST(fn) \
        do { \
            if (fn()) { \
                printf("PASS: %s\n", #fn); \
                (*passed)++; \
            } else { \
                printf("FAIL: %s\n", #fn); \
                (*failed)++; \
            } \
        } while (0)

    RUN_TEST(test_SUB_positive);
    RUN_TEST(test_SUB_zero_flag);
    RUN_TEST(test_SUB_sign_flag);
    RUN_TEST(test_SUB_carry_flag);
    RUN_TEST(test_SUB_overflow_flag);
    RUN_TEST(test_SUB_parity_flag);
    RUN_TEST(test_SUB_aux_carry_flag);
    RUN_TEST(test_SUB_combined_flags);

    #undef RUN_TEST

    if (*failed) {
        exit(EXIT_FAILURE);
    }
}

/* ================================================================== */
/*                                Main                                */
/* ================================================================== */

int main(void) {
    int passed = 0, failed = 0;
    run_ADD_tests(&passed, &failed);
    run_SUB_tests(&passed, &failed);
    printf("\n✅ Passed: %d | ❌ Failed: %d\n", passed, failed);
    return EXIT_SUCCESS;
}
