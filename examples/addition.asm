section .data
    fmt db "%d", 13, 10, 0

section .text
global main

extern printf

main:
    ; compute addition
    mov rcx, 0x5
    mov rdx, 0x7
    call add_fn

    ; print result
    lea rcx, [rel fmt]
    mov rdx, rax
    xor rax, rax
    call printf

    xor rax, rax
    ret

; 1 arg: RCX
; 2 arg: RDX
; returns RAX
add_fn:
    add rcx, rdx
    mov rax, rcx
    ret
