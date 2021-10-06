#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;

    ptr = malloc(sizeof(int));

    if (!ptr) {
        return 1;
    }
    
    // Assign a value in the location the pointer is pointing to
    *ptr = 10;

    // pass the pointer that the memory is allocated
    // If you call 
    free(ptr); 

    return 0;
}