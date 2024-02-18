bits 16

section bootloader
    cli
    xor ax, ax
    mov ds, ax
    mov es, ax

    mov bx, kernel_load
    mov ah, 0x02
    mov al, 0x01
    mov ch, 0x00
    mov dh, 0x00
    mov dl, 0x80
    int 0x13
    jc load_error

    jmp 0x0000:kernel_entry

load_error:
    mov ah, 0x0E
    mov al, 'E'
    int 0x10
    mov al, 'r'
    int 0x10
    mov al, 'r'
    int 0x1
    mov al, 'o'
    int 0x10
    mov al, 'r'
    int 0x10
    mov al, '!'
    int 0x10
    mov al, ' '
    int 0x10
    mov al, 'B'
    int 0x10
    mov al, 'o'
    int 0x10
    mov al, 'o'
    int 0x10
    mov al, 't'
    int 0x10
    mov al, ' '
    int 0x10
    mov al, 'f'
    int 0x10
    mov al, 'a'
    int 0x10
    mov al, 'i'
    int 0x10
    mov al, 'l'
    int 0x10
    mov al, 'e'
    int 0x10
    mov al, 'd'
    int 0x10
    hlt

kernel_load:
    
    kernel_entry:
    call main
    
    hlt
