/* VGA colors */

enum VGAColor 
{
    VGA_COLOR_BLACK = 0,
    VGA_COLOR_BLUE = 1,
    VGA_COLOR_GREEN = 2,
    VGA_COLOR_CYAN = 3,
    VGA_COLOR_RED = 4,
    VGA_COLOR_MAGENTA = 5,
    VGA_COLOR_BROWN = 6,
    VGA_COLOR_LIGHT_GRAY = 7,
    VGA_COLOR_DARK_GRAY = 8,
    VGA_COLOR_LIGHT_BLUE = 9,
    VGA_COLOR_LIGHT_GREEN = 10,
    VGA_COLOR_LIGHT_CYAN = 11,
    VGA_COLOR_LIGHT_RED = 12,
    VGA_COLOR_LIGHT_MAGENTA = 13,
    VGA_COLOR_YELLOW = 14,
    VGA_COLOR_WHITE = 15,
};
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

volatile short* vga_buffer = (short*)0xB8000;

vga_clear_screen() 
{
    for (int y = 0; y < VGA_HEIGHT; y++) 
    {
        for (int x = 0; x < VGA_WIDTH; x++) 
        {
            const int index = y * VGA_WIDTH + x;
            vga_buffer[index] = ' ' | (VGA_COLOR_BLACK << 8);
        }
    }
}

// Function to write a character to the VGA buffer
vga_write_char(c, color, x, y) 
char c;
unsigned short color;
{
    const int index = y * VGA_WIDTH + x;
    vga_buffer[index] = c | (color << 8);
}
