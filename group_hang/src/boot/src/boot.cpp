#include "boot.h"
#include "gdt.h"

char* int32_to_str(char buffer[], int val)
{
	char* b = buffer;
	// negation
	if (val < 0) { *b++ = '-'; val *= -1; }
	// move to end of repr.
	int tmp = val;
	do { ++b; tmp /= 10;  } while (tmp);
	*b = 0;
	// move back and insert as we go
	do {
		*--b = '0' + (val % 10);
		val /= 10;
	} while (val);
	return buffer;
}


extern "C" {
    void init_multiboot(uint32_t magic /*eax*/, multiboot_info* info /*ebx*/);
};

// extern void print(const char *format, ...);
extern void print_string(const char* str, uint8_t color, int x, int y);


void init_multiboot(uint32_t magic /*eax*/, multiboot_info* info /*ebx*/){
    print_string("\n", VGA_COLOR, 0, 0);


    // Convert values to string
    char* eax_buf;
    char* mb_magic_buf;
    int32_to_str(eax_buf, magic);
    int32_to_str(mb_magic_buf, MULTIBOOT_BOOTLOADER_MAGIC);

    if(magic != (multiboot_uint32_t)MULTIBOOT_BOOTLOADER_MAGIC){
        while(1){
            print_string("Magic number is invalid\n", VGA_COLOR, 0, 0);
          
        }; // ERROR!
    }
    
    print_string("Multiboot check went OK.\n", VGA_COLOR, 0, 0);

}