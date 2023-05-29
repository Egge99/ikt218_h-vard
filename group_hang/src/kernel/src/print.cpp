#include "gdt.h"

extern void print_string(const char* str, uint8_t color, int x, int y);
extern void clear_terminal();

int PrintLine = 0;



void print_char(char c, uint8_t color, int x, int y) {
    uint32_t index = y * VGA_COLUMNS + x;
    VGA_MEMORY[index] = ((uint16_t) color << 8) | c;
}


void print_string(const char* str, uint8_t color, int x, int y) {
    y = y + PrintLine;
    for (int i = 0; str[i] != '\0'; i++) {
        print_char(str[i], color, x + i, y);
    }
    PrintLine++;
}


void print_integer(int value, uint8_t color, int x, int y) {
    char buffer[20];
    int i = 0;
    if (value < 0) {
        buffer[i++] = '-';
        value = -value;
    }
    do {
        buffer[i++] = '0' + value % 10;
        value /= 10;
    } while (value != 0);
    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }
    buffer[i] = '\0';
    print_string(buffer, color, x, y);
}


void clear_terminal() {
    uint16_t empty_char = ((uint16_t) VGA_COLOR << 8) | ' ';
    for (int y = 0; y < VGA_ROWS; y++) {
        for (int x = 0; x < VGA_COLUMNS; x++) {
            uint32_t index = y * VGA_COLUMNS + x;
            VGA_MEMORY[index] = empty_char;
        }
    }
}