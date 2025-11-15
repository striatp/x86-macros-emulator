# x86 Macros Emulator

**x86 Macros Emulator** is a lightweight C header collection that provides macro-based implementations of common x86-like arithmetic, logic, and system operations.
It aims to simulate low-level CPU behavior, including register management, flag updates, and basic instruction semantics in a portable and educational way.
This small project is a self-educational project, throughout the journey of building it, it helped me learning how computers really work.

## Overview

This project reproduces fundamental CPU instructions such as `ADD`, `SUB`, `INC`, `DEC`, `MOV`, and `XCHG`, alongside arithmetic and bitwise operations.
Each instruction updates condition flags (`ZF`, `SF`, `CF`, `OF`, etc.) in a manner consistent with x86 CPU logic.
The implementation is header-only, making it simple to include in any C project or educational environment without additional dependencies.

## Structure

```

x86-macros-emulator/
├── Makefile
├── source/
│   ├── include/
│   │   ├── arithmetics.h
│   │   ├── bitwise.h
│   │   ├── data.h
│   │   ├── registers.h
│   │   └── system.h
│   ├── cassembly.h
│   └── main.c
├── tests/
│   ├── ...
└── README.md

````

## Build and Run

You can build the project and run examples using the provided Makefile:

```bash
make build
````

To run the tests:

```bash
make test
```

## Goals

* Provide a minimal but realistic simulation of CPU-like instructions in C.
* Serve as an educational tool for understanding low-level operations.
* Maintain portability and simplicity with no external libraries.

## License

This project is open source and distributed under the MIT License.
See the `LICENSE` file for more details.
