section .data
    fmt db "%d", 13, 10, 0

section .text
global main

extern printf

main:
    ; compute addition
    mov rax, 0x5
    mov rbx, 0x7
    add rax, rbx

    ; printf
    lea rcx, [rel fmt]
    mov rdx, rax
    xor rax, rax
    call printf

    xor rax, rax
    ret
