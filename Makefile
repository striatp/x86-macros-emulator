CC = clang
CFLAGS = -Wall -Wextra -I./source/include

SRC = source/main.c
TESTS = tests/run_tests.c tests/test_add.c

build:
	@$(CC) $(CFLAGS) $(SRC) -o bin/emulator.exe

test:
	@$(CC) $(CFLAGS) $(TESTS) -o bin/tests && ./bin/tests
