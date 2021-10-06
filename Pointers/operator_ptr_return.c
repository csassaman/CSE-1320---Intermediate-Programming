#include <stdio.h>
#include<string.h>
#define BUF_SIZE 128

void trim(char *);

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

int (*choose_op(char *c))(int, int) {
    if (!strcmp(c, "add")) {
        return add;
    } else if (!strcmp(c, "mult")) {
        return mult;
    } else {
        return NULL;
    }
}

int main() {
    char operator[BUF_SIZE] = { 0 };
    int a = 0, b = 0;

    printf("Enter the operator: ");
    fgets(operator, BUF_SIZE, stdin);
    trim(operator);

    printf("Enter two iuntegers: ");
    scanf("%d %d", &a, &b);

    int (*op)(int, int) = choose_op(operator);

    if (op == NULL) {
        printf("Invalid operator\n");
        return 1;
    }

    int op_result = op(a, b);

    printf("op(%d, %d) = %d\n", a, b, op_result);

    return 0;
}