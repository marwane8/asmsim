section .text
    global _start

;eax, ebx, ecx, edx
;edi = inc
_start:

xor edi, edi ; clear increment 
_loop:

    mov ecx, edi
    mov ecx, edi 
    add ecx, '0';add zero for asci
    push ecx ; push value to stack


    ; logic for sys write
    mov eax, 4 ;code for sys write
    mov ebx, 1 ; 1 for stdout
    mov ecx, esp;content-pointer to stack
    mov edx, 1 ;length
    int 0x80 ;sys interup

    ;increment and compare
    add edi, 1
    cmp edi, 5
    jl _loop

    

;system call exit
mov eax, 1
mov ebx, 0 
int 0x80
