section .data
    var1 db 'A'
    var2 db 'B'
    var3 db 'C' 

section .text
    global _start

;eax, ebx, ecx, edx
;edi = inc
_start:

    push var1; push value to stack
    push var2; push value to stack
    push var3; push value to stack


    ; logic for sys write 
    mov eax, 4 ;code for sys write
    mov ebx, 1 ; 1 for stdout
    mov ecx, [esp + 4] ;content - must be a pointer to value
    mov edx, 1 ;length
    int 0x80 ;sys interup


    

;system call exit
mov eax, 1
mov ebx, 0 
int 0x80
