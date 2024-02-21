.section .text
    .code16
    .org  0x7C00
start:
    mov  %cs, %ax
    mov  %ax, %ds
    call boot
    cld
    mov  $0x0E, %ah
    mov  $0x00, %bh
puts_loop:
    lodsb
    test %al, %al
    jz   puts_loop_exit
    int  $0x10
    jmp  puts_loop
puts_loop_exit:
    jmp  puts_loop_exit

boot:
    jmp main

.balign 512, 0
finish:
     .fill 510 - (finish - start), 1, 0
     .byte  0x55, 0xAA
