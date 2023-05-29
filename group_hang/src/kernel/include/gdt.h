#ifndef GDT_H
#define GDT_H

#include <stdint.h> 

#define VGA_BASE_ADDRESS 0xb8000
#define VGA_COLUMNS 80
#define VGA_ROWS 25

static uint16_t* const VGA_MEMORY = (uint16_t*) VGA_BASE_ADDRESS;
static uint8_t VGA_COLOR = 0x0f; // White on black by default

void print_char(char c, uint8_t color, int x, int y);
void print_string(const char* str, uint8_t color, int x, int y);


void gdt_install();

#endif // GDT_H