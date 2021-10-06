#include <stdio.h>
#include <stdlib.h>

int main() {
    double *ptr = calloc(1024, sizeof(double));

    for (int i = 0; i < 1024; i++ )
    ptr[i] = i + 1;

}