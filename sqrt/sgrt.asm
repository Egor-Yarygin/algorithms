%macro print 2
        movsd xmm0, qword %1
        mov  rdi, %2
        mov  eax, 1
        call printf
%endmacro

global main
default rel
extern printf

section .text
main:
        sub  rsp, 8

        fld qword [num]
        fsqrt
        fst qword [result]

        print [num], str1
        print [result], str2

        add  rsp, 8
        xor  eax, eax
        ret

section .data
        str1 db `\nRoot of %f `, 0
        str2 db `= %f\n\n`, 0
        num dq 37.0
        result dq 0.0
