#include <stdio.h>

int pow2(int a) {
    return a *  a;
}

void use_function(int (*fn)(int), int x) {
    printf("fn(%d) = %d\n", x, fn(x));
}

int main() {
    printf("Address of pow2 = %p\n", pow2);

    use_function(pow2, 8);
    return 0;
}
