section .data
    hi db 'Hello World!' ,0


section .text
    global _start

;eax, ebx, ecx, edx
;edi = inc
_start:

; logic for sys write
mov eax, 4 ;code for sys write
mov ebx, 1 ; 1 for stdout
mov ecx, hi ;content
mov edx, 12 ;length
int 0x80 ;sys interup


;system call exit
mov eax, 1
mov ebx, 0 
int 0x80
