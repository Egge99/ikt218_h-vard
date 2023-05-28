#include "gdt.h"

extern void print_string(const char* str, uint8_t color, int x, int y);

void print_char(char c, uint8_t color, int x, int y) {
    uint32_t index = y * VGA_COLUMNS + x;
    VGA_MEMORY[index] = ((uint16_t) color << 8) | c;
}

void print_string(const char* str, uint8_t color, int x, int y) {
    for (int i = 0; str[i] != '\0'; i++) {
        print_char(str[i], color, x + i, y);
    }
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