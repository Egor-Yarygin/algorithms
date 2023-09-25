%macro pushd 0
        push rax
        push rbx
        push rcx
        push rdx
%endmacro



%macro popd 0
        pop rdx
        pop rcx
        pop rbx
        pop rax
%endmacro



%macro print 1
        pushd
        push rbp
        mov rdi, format
        mov rsi, %1
        call printf
        pop rbp
        popd
%endmacro



%macro print_arr 1
        mov rcx, 0
next_step:
        print [%1+4*rcx]
        inc rcx
        cmp rcx, [size]
        jl next_step
%endmacro



%macro summ_arr 2
        mov rcx, 0
        mov rdx, [summ]
next_step2:
        mov rbx, [%1+4*rcx]
        sub rbx, [%2+4*rcx]
        add rdx, rbx
        inc rcx
        cmp rcx, [size]
        jl next_step2

        mov [summ], rdx
%endmacro





section   .text
global    main
extern printf
        
main:
        mov rax, [len]
        mov rbx, 4
        xor rdx, rdx
        div rbx
        mov [size], rax
        
        summ_arr x, y
        
        mov rax, [summ]
        mov rbx, [size]
        xor rdx, rdx
        cdq
        idiv ebx

        print rax

        mov       rax, 60
        xor       rdi, rdi
        syscall

section   .data
        format db '%d', 0xA, 0xD
        x dd 5, 3, 2, 6, 1, 7, 4
        y dd 0, 10, 1, 9, 2, 8, 5
        len dd $ - y
section   .bss
        size resd 1
        summ resd 0
