// kernel.c
// SpectrOS - Minimal Kernel by ArCom Corporation
#define VIDEO 0xB8000
#define WHITE_ON_BLACK 0x0F

// Escriu un caràcter a la pantalla
void print_char(char c, int col, int row, char color) {
    unsigned char *vidmem = (unsigned char*) VIDEO;
    int offset = (row * 80 + col) * 2;
    vidmem[offset] = c;        // caràcter
    vidmem[offset + 1] = color; // atribut color
}

// Escriu una cadena de text
void print_string(const char *str, int row, char color) {
    for (int col = 0; str[col] != '\0'; col++) {
        print_char(str[col], col, row, color);
    }
}

// Punt d’entrada del nucli
void kmain(void) {
    print_string("SpectrOS v0.0.1", 0, WHITE_ON_BLACK);
    print_string("(c) 2025 ArCom Corporation", 1, WHITE_ON_BLACK);
    print_string("Booting minimal kernel...", 3, WHITE_ON_BLACK);
    print_string("Welcome to SpectrOS!", 5, WHITE_ON_BLACK);

    for (;;) {
        __asm__("hlt");
    }
}
