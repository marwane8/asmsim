# simasm 
Mini assembly decoder to learn assembly instructions 


### Commands 

Print out binary
`xxd -b <file.bin>`

Disassemble binary
`ndisasm -b 16 <file.bin>`

Assemble assembley
`nasm file.asm -o out.exe`


### Shortcut 

xxd -b listing_0037_single_register_mov
nasm listing_0037_single_register_mov.asm -o hw_1



compile
gcc -c main.c decoder.c
gcc main.o decoder.o -o asmsim

