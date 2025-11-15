section .data
    hello_msg   db "Hello, world", 13, 10, 0

section .text
global main

extern printf ; retrieves from C runtime api

main:
    ; print 'hello_msg'
    lea rcx, [rel hello_msg]
    xor rax, rax
    call printf

    ; return
    xor rax, rax
    ret
