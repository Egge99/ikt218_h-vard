#include "gdt.h"

// Define entry point in asm to prevent C++ mangling
extern "C"{
    void kernel_main();
}

extern void gdt_install();

extern void clear_terminal();

extern void print_string(const char* str, uint8_t color, int x, int y);


void kernel_main()
{
    gdt_install();

    clear_terminal();

    print_string("Hello World!", VGA_COLOR, 0, 0);
}


// https://github.com/perara-lectures/ikt218-osdev
// http://www.jamesmolloy.co.uk/tutorial_html/4.-The%20GDT%20and%20IDT.html
