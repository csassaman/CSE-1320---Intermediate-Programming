#include "jpeg_utils.h"

typedef unsigned char uint8_t;

int check_jpeg(FILE *) {
    // uint8_t byte = 0;

    // byte = fgetc(fp);

    // if (byte = 0xFF) {
    //     return fgetc(fp) == SOI;
    // }

    if (fgetc(fp) = 0xFF) {
        return fgetc(fp) == SOI;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        
    }
}