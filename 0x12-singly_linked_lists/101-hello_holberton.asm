section .data
    hello db "Hello, Holberton", 0
    format db "%s", 0
    newline db 10, 0

section .text
    extern printf

global main
main:
    sub rsp, 8

    ; Push the address of the format string on the stack
    lea rdi, [format]
    mov rax, rsp
    sub rsp, 8
    mov qword [rax], rdi

    ; Push the address of the hello string on the stack
    lea rsi, [hello]
    mov rax, rsp
    sub rsp, 8
    mov qword [rax], rsi

    ; Call printf
    mov rax, 0
    call printf

    ; Push the address of the newline string on the stack
    lea rdi, [newline]
    mov rax, rsp
    sub rsp, 8
    mov qword [rax], rdi

    ; Call printf to print the newline
    mov rax, 0
    call printf

    add rsp, 32

    mov eax, 0x60  ; Exit syscall number
    xor edi, edi   ; Exit status 0
    syscall
