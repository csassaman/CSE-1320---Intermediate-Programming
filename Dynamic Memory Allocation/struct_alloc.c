#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 128 
typedef struct {
    int id;
    char *product_name;
    double price;
    int quantity;
} product_t;

int main() {
    product_t *product = malloc(sizeof(product_t));

    if(product) {
        char buffer [BUF_SIZE] = { 0 };
        printf("Enter the product name: ");
    }
}