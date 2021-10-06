#include <stdio.h>

// 01110010

// >> 5
// 00000011
// 00000001 &
// --------
// 00000001
void print_binary_char(unsigned char a) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (a >> i) & 1);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");

    if (!fp) {
        return 1;
    }



    return 0;
}