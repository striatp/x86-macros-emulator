CC = clang
CFLAGS = -Wall -Wextra -I./source/include

SRC = source/main.c
TESTS = tests/run_tests.c tests/arithmetics/test_add.c tests/arithmetics/test_sub.c

build:
	@$(CC) $(CFLAGS) $(SRC) -o bin/emulator.exe

test:
	@$(CC) $(CFLAGS) $(TESTS) -o bin/tests && ./bin/tests
