; This will set up our new segment registers. We need to do
; something special in order to set CS. We do what is called a
; far jump. A jump that includes a segment as well as an offset.
; This is declared in C as 'extern void gdt_flush();'
[global gdt_flush]    ; Allows the C code to link to this
extern gp            ; Says that '_gp' is in another file
gdt_flush:
    lgdt [gp]        ; Load the GDT with our '_gp' which is a special pointer
    mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush   ; 0x08 is the offset to our code segment: Far jump!
flush:
    ret               ; Returns back to the C code!

[global reload_segments]     ; Allows the C code to link to this
reload_segments:
   ; Reload CS register containing code selector:
   JMP   0x08:.reload_CS ; 0x08 is a stand-in for your code segment
.reload_CS:
   ; Reload data segment registers:
    mov ax, 0x10      ; 0x10 is the offset in the GDT to our data segment
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
   RET